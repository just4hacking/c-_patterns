#include "./foo.hpp"
#include <iostream>

class PFoo::impl {
public:
  void say_hello()
  {
    std::cout << "hello";
  }
};

void PFoo::say_hello()
{
  impl->say_hello();
}
