//bad pattern
#pragma once
#include <vector>
#include <string>

using namespace std;

//bad idea
//can't inherit static field and it's not flexible at all
class BadPrinter {
  static int id;
public:
  int get_id() const { return id; }
  void set_id(int value) { id = value; }
};

/*
int main(int argc, char *argv[]) {
  Printer p;
  int id = p.get_id();

  Printer p2;
}
*/

