/* 
YOU SHOULD BE ALWAYS BE ABLE TO SUBSTITUE BASE TYPE ON SUBTYPE

THIS IS AN EXAMPLE OF BREAKING 
THE LISKOV SUBSTITUTION PRINCIPLE */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Rectangle {
protected:
  int width, height;
public:
  Rectangle(int width, int height) 
    : width(width), height(height) {}

  virtual void setHeight(int height) {
    Rectangle::height = height;
  }

  virtual void setWidth(int width) {
    Rectangle::width = width;
  }

  int getHeight() const {
    return height;
  }

  int getWidth() const {
    return width;
  }

  int area() const { 
    return width * height;
  }
};

//you can't supply it to the process function, it will behave differently
//so  it violates the liskov substitution principle
class Square : public Rectangle {
public:
  Square(int size): Rectangle(size, size) {}

  virtual void setHeight(int height) override {
    this->width = this->height = height;
  }

  virtual void setWidth(int width) override {
    this->width = this->height = width;
  }
};

/*
//breaks liskovv substitution principle
@"expected area = 30, got 30\r\n"
@"expected area = 50, got 100\r\n"

void process(Rectangle& r) {
  int w = r.getWidth();
  r.setHeight(10);

  cout << "expected area = " << (w * 10)
      << ", got " << r.area() << endl;
}

int main(int argc, char *argv[]) {
  Rectangle r{3, 4};
  process(r);

  Square sq{5};
  process(sq);

  return 0;
}
*/