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

using namespace std;

double add(double a, double b) {
  cout << a << "+" << b << " = " << (a + b) << endl;
  return a + b;
}

int main(int argc, char *argv[])
{
  //decorator::Logger([]() { cout << "Hello" << endl;}, "HelloFunction")();
  auto log = decorator::make_logger2([]() {
    cout << "Hello" << endl;
  },
  "HelloFunction");
  log();

  auto logged_add = decorator::make_logger3(add, "Add");
  auto result = logged_add(2, 3);
  cout << "result = " << result << endl;
}
