#include "./neuron.hpp"

Neuron::Neuron() {
  static int id{1};
  this->id = id++;
}

std::ostream& operator<<(std::ostream& os, const Neuron& obj) {
  for (Neuron* n : obj.in) {
    os << n->id << "\t-->\t[" << obj.id << "]" << std::endl;
  }

  for (Neuron* n : obj.out) {
    os << "[" << obj.id << "]\t-->\t" << n->id << std::endl;
  }

  return os;
}

Neuron* Neuron::begin() {
  return this;
}

Neuron* Neuron::end() {
  return this + 1;
}