/*
DON'T PUT TOO MUCH INTO AN INTERFACE, SPLIT INTO SEPARATE INTERFACES
*/
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Document;
struct BadIMachine {

  virtual void print(Document* doc) = 0;
  virtual void scan(Document* doc) = 0;
  virtual void fax(Document* doc) = 0;
};

//what if we decide to implement just a printer 
//or just a scanner
struct BadMFP : BadIMachine {
  void print(Document* doc) {

  }

  void scan(Document* doc) {

  }

  void fax(Document* doc) {

  }
};

//problem
struct BadScanner : BadIMachine {
  void print(Document* doc) {
    //throw exeception? It's misleading for client
  }

  void scan(Document* doc) {
    //ok
  }

  void fax(Document* doc) {
    //throw exeception?
  }
};
//the solution is to segregate interfaces
struct IPrinter {
  virtual void print(Document& doc) = 0;
};

struct IScanner {
  virtual void scan(Document& doc) = 0;
};

struct IFax {
  virtual void fax(Document& doc) = 0;
};

struct Printer : IPrinter {
  void print(Document& doc) override {

  }
};

struct IMachine : IPrinter, IScanner {};

//decorator pattern can be implemented
struct Machine : IMachine {
  IPrinter& printer;
  IScanner& scanner;

  Machine(IPrinter& printer, IScanner& scanner) :
    printer(printer), scanner(scanner) {}

  void print(Document& doc) override {
    printer.print(doc);
  }

  void scan(Document& doc) override {
    scanner.scan(doc);
  }
};