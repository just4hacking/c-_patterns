#include <string>
#include <vector>
#include <ostream>
#include <cmath>

using namespace std;

enum class PointType {
  cartesian,
  polar
};

struct BadPoint {
  //if else makes it very messy very fast
  BadPoint(float a, float b, PointType type = PointType::cartesian) {
    if (type == PointType::cartesian) {
      x = a;
      y = b;
    } else {
      x = a * cos(b);
      y = a * sin(b);
    }
  }

  /*
  BadPoint(float rho, float theta) {
    //imagine we want to init point with a different types of parameters
    //we can't implement it like this, because name of consturctor and the list of parameters
    //should be unique
  }
  */

  float x, y;
};

class Point {
  //violates open-closed principle
  //so it's not recommened, the workaround is to make
  //a constructor public
  friend class PointFactory;

  Point(float x, float y) : x(x), y(y) {

  }

  //inner factory
  //doesn't violates open closed principle
  class InnerPointFactory {
    InnerPointFactory() {}
  public:
    static Point NewCartesian(float x, float y) {
      return {x, y};
    }

    static Point NewPolar(float r, float theta) {
      return { r * cos(theta), r * sin(theta) };
    }
  };  

public: 
  float x, y;
  static InnerPointFactory Factory;
  
  //factory methods
  static Point NewCartesian(float x, float y) {
    return {x, y};
  }

  static Point NewPolar(float r, float theta) {
    return { r * cos(theta), r * sin(theta) };
  }

  friend ostream& operator<<(ostream& os, const Point& point) {
    os << "x: " << point.x << " y: " << point.y;
    return os;
  }
};

struct PointFactory {
  static Point NewCartesian(float x, float y) {
    return {x, y};
  }

  static Point NewPolar(float r, float theta) {
    return { r * cos(theta), r * sin(theta) };
  }
};

/*
EXAMPLE
int main(int argc, char *argv[]) {
  auto p = Point::NewPolar(5, M_PI_4);
  auto m = PointFactory::NewPolar(3, M_PI_4);
  auto c = Point::Factory.NewPolar(2, M_PI_4);
  cout << p << endl;
  cout << m << endl;
  cout << c << endl;
  return 0;
}
*/