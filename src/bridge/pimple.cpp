#include "./pimple.hpp"

using namespace std;

//DOESNT WORK 
//https://github.com/0x2648/pimpl-template WORKS
class PimplePerson::PimplePersonImpl {
public:
  void greet(PimplePerson* p) {
    cout << "hello my name is " << p->name << endl;
  }
};

PimplePerson::PimplePerson() : impl(new PimplePersonImpl) {
}

PimplePerson::~PimplePerson() {
  delete impl;
}

void PimplePerson::greet() {
  impl->greet(this);
}
