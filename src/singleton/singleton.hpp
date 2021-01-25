#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <filesystem>
#include <gtest/gtest.h>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

//resolves issues with testing, as we can implement 
//a dependency inhection
class Database {
public:
  virtual int get_population(const string& name) = 0;
};

class SingletonDatabase : public Database {
  SingletonDatabase() {
    cout << "Initializing database\n";
    ifstream ifs;
    ifs = ifstream("../src/singleton/capitals.txt");

    string s, s2;

    //little workaround for tests (working directory is different)
    if (!ifs.good()) {
      ifs = ifstream("./src/singleton/capitals.txt");
    }

    while(getline(ifs, s)) {
      getline(ifs, s2);
      int pop = lexical_cast<int>(s2);
      capitals[s] = pop;
    }
  }
  map<string, int> capitals;
public:
  SingletonDatabase(SingletonDatabase const&) = delete;
  void operator=(SingletonDatabase const&) = delete;

  static SingletonDatabase&get() {
    static SingletonDatabase db;
    return db;
  }

  int get_population(const string& name) {
    return capitals[name];
  }
};

class DummyDatabase : public Database {
  map<string, int> capitals;
public:
  DummyDatabase() {
    capitals["alpha"] = 1;
    capitals["beta"] = 2;
    capitals["gamma"] = 3;
  }

  int get_population(const string& name) override {
    return capitals[name];
  }
};

//more flexible database
struct ConfigurableRecordFinder {
  Database& db;

  ConfigurableRecordFinder(Database& db) : db(db) {

  }

  int total_population(vector<string> names) {
    int result{0};
    for (auto& name : names) {
      result += db.get_population(name);
    }
    return result;
  }
};

//bad finder as it's hard to test
struct SingletonRecordFinder {
  //the problem is with testing
  int total_population(vector<string> names) {
    int result{0};
    for (auto& name : names) {
      result += SingletonDatabase::get().get_population(name);
    }
    return result;
  }
};

/*
EXAMPLE
int main(int argc, char *argv[]) {
  string city = "Tokyo";
  cout << city << " has population " <<
    SingletonDatabase::get().get_population(city) << endl;

}
*/