#include <iostream>
#include <cmath>
#include "./builder/index.hpp"
#include "./factory/index.hpp"

using namespace std;

//alternative to drink factory
unique_ptr<HotDrink> make_drink(string type) {
  unique_ptr<HotDrink> drink;

  if (type == "tea") {
    drink = make_unique<Tea>();
    drink->prepare(200);
  } else {
    drink = make_unique<Coffee>();
    drink->prepare(50);
  }
  return drink;
}

int main(int argc, char *argv[]) {
  DrinkFactory df;
  auto c = df.make_drink("coffee");

  DrinkWithVolumeFactory dnvf;
  auto t = dnvf.make_drink("tea");

  cout << "Success" << endl;
  return 0;
}