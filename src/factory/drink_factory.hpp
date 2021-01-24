#pragma once

#include <map>
#include <functional>
#include "./hot_drink.hpp"
#include "./hot_drink_factory.hpp"

using namespace std;

class DrinkFactory {
  map<string, unique_ptr<HotDrinkFactory>> hot_factories;
public:
  DrinkFactory() {
    hot_factories["coffee"] = make_unique<CoffeeFactory>();
    hot_factories["tea"] = make_unique<TeaFactory>();
  }

  unique_ptr<HotDrink> make_drink(const string& name) {
    auto drink = hot_factories[name]->make();
    drink->prepare(50);
    return drink;
  }
};

//Functional factory
class DrinkWithVolumeFactory {
  map<string, function<unique_ptr<HotDrink>()>> factories;
public:
  DrinkWithVolumeFactory() {
    factories["tea"] = [] {
      auto tea = make_unique<Tea>();
      tea->prepare(200);
      return tea;
    };

    factories["coffee"] = [] {
      auto coffee = make_unique<Coffee>();
      coffee->prepare(50);
      return coffee;
    };
  }

  unique_ptr<HotDrink> make_drink(const string& name) {
    return factories[name]();
  }
};

/*
EXAMPLE
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
*/