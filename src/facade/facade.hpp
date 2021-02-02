#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

struct Window {

};

class Console {
public:
  static Console& instance() {
    static Console console;
    return console;
  }

  vector<shared_ptr<Window>> windows;

  //this is a facade as simple as that!
  vector<Window> multicolumn (const string& title,
    uint8_t columnCount, uint8_t columnWidth, 
    uint8_t charsHigh) {
    
    auto w = make_shared<Window>();
    //some complicated logic
    //
  }
private:
  const int charWidth = 10, charHeight = 14;
  Console() {}
  Console(Console const&) = delete;
  void operator=(Console const&) = delete;
};
