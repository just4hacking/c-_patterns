#include <iostream>
#include <cmath>
#include <memory>

#include "./src/builder/index.hpp"
#include "./src/prototype/index.hpp"
#include "./src/factory/index.hpp"
#include "./src/singleton/index.hpp"
#include "./src/adapter/index.hpp"
#include "./src/bridge/index.hpp"
#include "./src/composite/index.hpp"
#include "./src/decorator/index.hpp"
#include "./src/flyweight/index.hpp"

using namespace std;


int main(int argc, char *argv[])
{
  flyweight_custom::FormattedText ft{"This is a brave new world!"};
  ft.capitalize(10, 15);
  cout << ft << endl;

  flyweight_custom::BetterFormattedText bft{"This is a brave new world!"};
  bft.get_range(10, 15).capitalize = true;
  cout << bft << endl;
}
