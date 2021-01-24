#include <iostream>
#include "./builder/index.hpp"

using namespace std;

int main(int argc, char *argv[]) {

  Person p = Person::create()
    .lives()
      .at("123 London Road")
      .with_postcode("SW1 1GB")
      .in("London")
    .works()
      .at("Pragmasoft")
      .as_a("Consultant")
      .earning(10e6);
      
  cout << p << endl;
  return 0;
}