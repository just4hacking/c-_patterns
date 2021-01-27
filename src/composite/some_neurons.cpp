#include "./some_neurons.hpp"
#include "./neuron.hpp"

template <typename Self>
template <typename T>
void SomeNeurons<Self>::connect_to(T& other) {
  for (Neuron& from : static_cast<Self*>(this)) {
    for (Neuron& to : other) {
      from.out.push_back(&other);
      to.in.push_back(&from);
    }
  }
}