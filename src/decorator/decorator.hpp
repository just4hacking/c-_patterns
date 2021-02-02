#include <string>
#include <vector>
#include <iostream>
#include <sstream>  

using namespace std;

namespace decorator {

struct Shape {
  virtual string str() const = 0;
};

struct Circle : public Shape {
  float radius;

  Circle() {}

  Circle(float radius) : radius(radius) {

  }

  void resize(float factor) {
    radius *= factor;
  }

  string str() const override {
    ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
};

struct Square : public Shape {
  float side;

  Square() {}

  Square(float side) : side(side) {

  }

  string str() const override {
    ostringstream oss;
    oss << "A square with side " << side;
    return oss.str();
  }
};

struct ColoredShape : public Shape {
  Shape& shape;
  string color;

  ColoredShape(Shape& shape, const string& color) :
    shape(shape), color(color) {

  }

  string str() const override {
    ostringstream oss;
    oss << shape.str() << " has the color " << color;
    return oss.str();
  }
};

struct TransparentShape : public Shape {
  Shape& shape;
  uint8_t transparency;

  TransparentShape(Shape& shape, uint8_t transparency) :
    shape(shape), transparency(transparency) {

  }

  string str() const override {
    ostringstream oss;
    oss << shape.str() 
        << " has "
        << static_cast<float>(transparency) / 255.f * 100.f
        << "% transparency";
    return oss.str();
  }

};

//THE downside of dynamic decoration is that we can't invoke 
// Circle's resize method, we are bind to an interface defined 
// in Shape class

//let's see how static decoration works
//mixin inheritance
//perfect forwarding
template <typename T> 
concept IsAShape = std::is_base_of<Shape, T>::value;

template<typename T> struct ColoredShape2 : T {
  string color;

  ColoredShape2() {

  }

  template <typename ...Args>
  ColoredShape2(const string& color, Args ...args) 
    : T(std::forward<Args>(args)...), color{color} {
  }

  string str() const override {
    ostringstream oss;
    oss << T::str() << " has the color " << color;
    return oss.str();
  }
};

}


/*
EXAMPLE
int main(int argc, char *argv[]) {
  decorator::Square square{5};
  decorator::ColoredShape red_square{square, "red"};
  cout << square.str() << endl << red_square.str() << endl;
  decorator::TransparentShape my_square{red_square, 51};
  cout << my_square.str() << endl;
}


STATIC DECORATOR (doesn't work)

int main(int argc, char *argv[]) {
  decorator::ColoredShape2<Circle> green_circle{"green", 5};
  cout << green_circle.str() << endl;
}

*/
