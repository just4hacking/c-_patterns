#pragma once
#include <vector>
#include <ostream>
#include "./some_neurons.hpp"

class Neuron : public SomeNeurons<Neuron> {
public:
  std::vector<Neuron*> in, out;
  unsigned int id;

  Neuron();

  friend std::ostream& operator<<(std::ostream& os, const Neuron& obj);

  Neuron* begin();
  Neuron* end();
};