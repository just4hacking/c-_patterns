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
  Group root("root");
  Circle c1, c2;
  root.objects.push_back(&c1);
  Group subgroup("sub");
  subgroup.objects.push_back(&c2);
  root.objects.push_back(&subgroup);

  root.draw();
}
