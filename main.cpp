#include <iostream>
#include <cmath>
#include <memory>

#include "./src/builder/index.hpp"
#include "./src/prototype/index.hpp"
#include "./src/factory/index.hpp"
#include "./src/singleton/index.hpp"
#include "./src/adapter/index.hpp"

using namespace std;


std::vector<std::shared_ptr<VectorObject>> vectorObjects {
  std::make_shared<VectorRectangle>(10, 10, 100, 100),
  std::make_shared<VectorRectangle>(30, 30, 60, 60),
};

int main(int argc, char *argv[]) {
  //drawAdapter(vectorObjects);
  drawCachingAdapter(vectorObjects);
}

