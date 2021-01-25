#pragma once
#include <map>
#include <memory>
#include <iostream>

enum class Importance {
  primary,
  secondary,
  tertiary
};

template <typename T, typename Key = std::string>
class Multiton {
public:
  static std::shared_ptr<T> get(const Key& key) {
    if (const auto it = instances.find(key); it != instances.end()) {
      return it->second;
    }

    auto instance = std::make_shared<T>();
    instances[key] = instance;
    return instance;
  }
protected:
  Multiton() = default;
  virtual ~Multiton() = default;
private:
  static std::map<Key, std::shared_ptr<T>> instances;
};

template <typename T, typename Key> 
std::map<Key, std::shared_ptr<T>> Multiton<T, Key>::instances;

class MultitonPrinter {
public:
  MultitonPrinter() {
    ++MultitonPrinter::totalInstanceCount;
    std::cout << "A total of " << MultitonPrinter::totalInstanceCount 
        << " instances created so far\n";
  }
private:
  static int totalInstanceCount;
};

int MultitonPrinter::totalInstanceCount = 0;