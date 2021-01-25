#include <iostream>
#include <map>
#include <fstream>
#include <filesystem>
#include <gtest/gtest.h>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;


class SingletonDatabase {
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

struct SingletonRecordFinder {
  //the problem is with testing
  int total_population(vector<string> names) {
    int result{0};
    for (auto& name : names) {
      cout << SingletonDatabase::get().get_population(name) << endl;
      result += SingletonDatabase::get().get_population(name);
    }
    return result;
  }
};