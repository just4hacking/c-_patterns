#pragma once
#include <iostream>
#include <memory>
#include <string>

//compilation speed (changing implementation without 
//changing api, it recompiles only one cpp file)
//implementaion is hidden
class PimplePerson {
public:
  std::string name;

  class PimplePersonImpl;
  PimplePersonImpl* impl;

  PimplePerson();
  ~PimplePerson();

  void greet();
//so its better seperate implementation and abstraction
private:
  //if you implement this pattern then you don't need to supply
  //it to the end consumer. The implementation will be hidden in cpp file
  void secret() {}
};

template <typename T> class pimpl {
private:
  std::unique_ptr<T> impl;
public:
  //https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl
  pimpl() : impl(new T{}) {

  }
  ~pimpl() {
    
  }

  template <typename ...Args> pimpl
    (Args&& ...args) : impl{ new T{ std::forward<Args>(args)... }} {

  }

  T* operator->() {
    return impl.get();
  }

  T& operator*() {
    return *impl.get();
  }
};
