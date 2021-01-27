#pragma once
#include "./pimple.hpp"

//DOESNT WORK
class PFoo {
  class impl;
  //COMPILE ERROR
  pimpl<impl> impl;
public:
  void say_hello();
};