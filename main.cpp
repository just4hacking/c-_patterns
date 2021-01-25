#include <iostream>
#include <cmath>
#include <memory>

#include "./src/builder/index.hpp"
#include "./src/prototype/index.hpp"
#include "./src/factory/index.hpp"
#include "./src/singleton/index.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  typedef Multiton<MultitonPrinter, Importance> mt;

  auto main = mt::get(Importance::primary);
  auto aux = mt::get(Importance::secondary);
  auto aux2 = mt::get(Importance::secondary);
}

