#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace proxy {

using namespace std;

struct Image {
  virtual void draw() = 0;
};

struct Bitmap : Image {
public:
  Bitmap(const string& filename) {
    cout << "Loading bitmap from" << filename << endl;
  }

  void draw() override {
    cout << "Drawing bitmap" << endl;
  }
};

struct LazyBitmap : Image {
public:
  LazyBitmap(const string& filename) : filename(filename) {

  }

  void draw() override {
    if (!bmp) {
      bmp = new Bitmap(filename);
    }

    bmp->draw();
  }
private:
  string filename;
  Bitmap* bmp{nullptr};
};

}