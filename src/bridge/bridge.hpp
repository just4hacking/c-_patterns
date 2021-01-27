#pragma once
#include <iostream>

using namespace std;

//bridge helps us avoid satte space explosion
// Shapes - BCircle, squre
// Renderer - raster, vector 

//2x2
//INSTEAD OF SPAWING 4 DIFFERENT RENDERES WE CAN MAKE 
//PASS A REFERENCE TO RENDERER TO A SHAPE
struct Renderer {
  virtual void render_circle(float x, float y, float radius) = 0;
};

struct VectorRenderer : Renderer {
  void render_circle(float x, float y, float radius) {
    cout << "Drawing a vector BCircle of radius" << radius << endl;
  }
};

struct RasterRenderer : Renderer {
  void render_circle(float x, float y, float radius) {
    cout << "Rasterizing a BCircle of radius" << radius << endl;
  }
};

struct Shape {
protected:
  Renderer& renderer;
public:
  Shape(Renderer& renderer) : renderer(renderer) {

  }
public:
  virtual void draw() = 0;
  virtual void resize(float factor) = 0;
};

struct BCircle : Shape {
  BCircle(Renderer& renderer, float x, float y, float radius) :
    Shape(renderer), x{x}, y{y}, radius{radius} {

  }

  float x, y, radius;

  void draw() override {
    renderer.render_circle(x, y, radius);
  }

  void resize(float factor) {
    radius *= factor;
  }
};

/*
EXAMPLE
int main(int argc, char *argv[]) {
  RasterRenderer rr;
  BCircle raster_circle{rr, 5, 5, 5};
  raster_circle.draw();
  raster_circle.resize(2);
  raster_circle.draw();
}
*/