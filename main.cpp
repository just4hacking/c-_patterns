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

using namespace std;

int main(int argc, char *argv[]) {

  Creature orc;
  orc.set_strength(16);
  orc.set_agility(11);
  orc.set_intelligence(9);

  cout << "The orc has an average stat of "
       << orc.average()
       << " and a maximum stat of "
       << orc.max()
       << "\n";

  return 0;
  
}
