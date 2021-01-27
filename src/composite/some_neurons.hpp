#pragma once
#include <string>
#include <vector>
#include <ostream>

//DOESNT WORK LINKING ERROR
//https://isocpp.org/wiki/faq/templates#separate-template-class-defn-from-decl
struct Neuron;

//CRTP
template <typename Self>
struct SomeNeurons {
  template <typename T> void connect_to(T& other);
};


/*
int main(int argc, char *argv[]) {
  Neuron n1, n2;
  n1.connect_to(n2);
  cout << n1 << n2 << endl;
  
  NeuronLayer layer1{2}, layer2{3};
  n1.connect_to(layer1);
  layer2.connect_to(n2);
  layer1.connect_to(layer2);
}
*/