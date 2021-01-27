#include <vector>
#include "./neuron.hpp"
#include "./some_neurons.hpp"

//vector doesn have virtual destrcutor, its only an example
struct NeuronLayer : std::vector<Neuron>, public SomeNeurons<NeuronLayer> {
  NeuronLayer(int count) {
    while (count --> 0) {
      emplace_back(Neuron{});
    }
  }

  friend std::ostream& operator<<(std::ostream& os, const NeuronLayer& obj) {
    for (auto& n : obj) {
      os << n;
    }
    return os;
  }
};