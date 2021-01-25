#include <iostream>
#include <cmath>

#include "./src/builder/index.hpp"
#include "./src/prototype/index.hpp"
#include "./src/factory/index.hpp"
#include "./src/singleton/index.hpp"

using namespace std;


int main(int argc, char *argv[]) {
  string city = "Tokyo";
  cout << city << " has population " <<
    SingletonDatabase::get().get_population(city) << endl;

}

