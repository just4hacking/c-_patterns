#pragma once
#include <vector>
#include <cmath>
#include <iostream>
#include <memory>
#include <algorithm> 
#include <boost/functional/hash.hpp>

struct GeometryPoint {
  int x, y;

  friend std::size_t hash_value(const GeometryPoint& obj) {
    std::size_t seed = 0x1E44943F;
    boost::hash_combine(seed, obj.x);
    boost::hash_combine(seed, obj.y);
    return seed;
  }
};

struct Line {
  GeometryPoint start, end;

  friend std::size_t hash_value(const Line& obj) {
    std::size_t seed = 0x1E44943F;
    boost::hash_combine(seed, obj.start);
    boost::hash_combine(seed, obj.end);
    return seed;
  }
};

struct VectorObject {
  virtual std::vector<Line>::iterator begin() = 0;
  virtual std::vector<Line>::iterator end() = 0;
};

struct VectorRectangle : VectorObject {
  VectorRectangle(int x, int y, int width, int height) {
    lines.emplace_back(Line { GeometryPoint { x, y }, GeometryPoint { x + width, y }});
    lines.emplace_back(Line { GeometryPoint { x + width, y }, GeometryPoint { x + width, y + height }});
    lines.emplace_back(Line { GeometryPoint { x, y }, GeometryPoint { x, y + height }});
    lines.emplace_back(Line { GeometryPoint { x, y + height }, GeometryPoint { x + width, y + height }});
  }

  std::vector<Line>::iterator begin() override {
    return lines.begin();
  }

  std::vector<Line>::iterator end() override {
    return lines.end();
  }

private:
  std::vector<Line> lines;
};

//
void DrawGeometryPoint() {

}

struct LineToGeometryPointAdapter {
  typedef std::vector<GeometryPoint> GeometryPoints;

  LineToGeometryPointAdapter(Line& line) {
    static int count = 0;
    
    // no interpolation
    int left = std::min(line.start.x, line.end.x);
    int right = std::max(line.start.x, line.end.x);
    int top = std::min(line.start.y, line.end.y);
    int bottom = std::max(line.start.y, line.end.y);
    int dx = right - left;
    int dy = line.end.y - line.start.y;

    // only vertical or horizontal lines
    if (dx == 0)
    {
      // vertical
      for (int y = top; y <= bottom; ++y)
      {
        points.emplace_back(GeometryPoint{ left,y });
      }
    }
    else if (dy == 0)
    {
      for (int x = left; x <= right; ++x)
      {
        points.emplace_back(GeometryPoint{ x, top });
      }
    }
  }

  GeometryPoints::iterator begin() {
    return points.begin();
  }

  GeometryPoints::iterator end() {
    return points.end();
  }

private:
  GeometryPoints points;
};

void DrawGeometryPoints(std::vector<GeometryPoint>::iterator start, std::vector<GeometryPoint>::iterator end) {
  for (auto i = start; i != end; ++i) {
    std::cout << "x: " << i->x << " y: " << i->y << std::endl;
  }
}

struct LineToGeometryPointCachingAdapter {
  typedef std::vector<GeometryPoint> GeometryPoints;

  LineToGeometryPointCachingAdapter(Line& line) {
    boost::hash<Line> hash;
    line_hash = hash(line);

    if (cache.find(line_hash) != cache.end()) 
      return;

    GeometryPoints points;
    int left = std::min(line.start.x, line.end.x);
    int right = std::max(line.start.x, line.end.x);
    int top = std::min(line.start.y, line.end.y);
    int bottom = std::max(line.start.y, line.end.y);
    int dx = right - left;
    int dy = line.end.y - line.start.y;

    // only vertical or horizontal lines
    if (dx == 0)
    {
      // vertical
      for (int y = top; y <= bottom; ++y)
      {
        points.emplace_back(GeometryPoint{ left,y });
      }
    }
    else if (dy == 0)
    {
      for (int x = left; x <= right; ++x)
      {
        points.emplace_back(GeometryPoint{ x, top });
      }
    }
    cache[line_hash] = points;
  }

  GeometryPoints::iterator begin() {
    return cache[line_hash].begin();
  }

  GeometryPoints::iterator end() {
    return cache[line_hash].end();
  }

private:
  size_t line_hash;
  static std::map<size_t, GeometryPoints> cache;
};

std::map<size_t, LineToGeometryPointCachingAdapter::GeometryPoints> LineToGeometryPointCachingAdapter::cache = {};

//we have implemented an adapter 
void drawAdapter(std::vector<std::shared_ptr<VectorObject>> vectorObjects) {
  for (auto& o : vectorObjects) {
    for (auto& l : *o) {
      LineToGeometryPointAdapter lpo{ l };
      DrawGeometryPoints(lpo.begin(), lpo.end());
    }
  }
}

//we have implemented an adapter 
//it's like proxy cache
void drawCachingAdapter(std::vector<std::shared_ptr<VectorObject>> vectorObjects) {
  for (auto& o : vectorObjects) {
    for (auto& l : *o) {
      LineToGeometryPointCachingAdapter lpo{ l };
      DrawGeometryPoints(lpo.begin(), lpo.end());
    }
  }
}

/*
EXAMPLE
std::vector<std::shared_ptr<VectorObject>> vectorObjects {
  std::make_shared<VectorRectangle>(10, 10, 100, 100),
  std::make_shared<VectorRectangle>(30, 30, 60, 60),
};

int main(int argc, char *argv[]) {
  //drawAdapter(vectorObjects);
  drawCachingAdapter(vectorObjects);
}
*/
