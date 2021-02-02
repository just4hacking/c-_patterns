#pragma once
#include <string>
#include <vector>
#include <iostream>

//property proxy
namespace proxy {
  
using namespace std;

template <typename T>
struct Property {
public:
  T value;

  Property(T value) {
    *this = value;
  }

  operator T() {
    return value;
  }

  T operator=(T new_value) {
    cout << "Assignment!\n";
    return value = new_value;
  }
};

struct Creature {
public:
  Property<int> strength{10};
  Property<int> agility{10};
  
};

}

/*

EXAMPLE
int main(int argc, char *argv[])
{
  proxy::Creature c;
  c.strength = 12;

  int x = c.agility;
}
*/