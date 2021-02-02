#pragma once
#include <string>
#include <map>
#include <iostream>
#include <boost/bimap.hpp>
#include <boost/flyweight.hpp>

namespace flyweight_custom {

using namespace std;

typedef uint32_t key;

struct User {
public:
  User(const string& first_name, const string& last_name)
    : first_name{add(first_name)}
    , last_name{add(last_name)} {}

  const string& get_first_name() const {
    return names.left.find(first_name)->second;
  }

  const string& get_last_name() const {
    return names.left.find(last_name)->second;
  }

  friend ostream& operator<<(ostream& os, const User& user); 

protected:
  key first_name, last_name;
  static boost::bimap<key, string> names;
  static key seed;

  static key add(const string& s) {
    auto it = names.right.find(s);

    if (it == names.right.end()) {
      key id = ++seed;
      names.insert({seed, s});
      return id;
    }

    return it->second;
  }
};

key User::seed{0};
boost::bimap<key, string> User::names{};

ostream& operator<<(ostream& os, const User& user) {
  os << "first_name: " << user.get_first_name()
     << " last_name: " << user.get_last_name()
     << "(" << user.last_name << ")";
  return os;
}

//use boost flyweight library
struct User2 {
public:
  boost::flyweight<string> first_name, last_name;

  User2(const string& first_name, const string& last_name) 
    : first_name(first_name),
      last_name(last_name) {}
  
};

}

/*
EXAMPLE

int main(int argc, char *argv[])
{
  flyweight_custom::User user1{"John", "Smith"};
  flyweight_custom::User user2{"Jane", "Smith"};

  cout << user1 << endl << user2;

  flyweight_custom::User2 first{"John", "Smith"};
  flyweight_custom::User2 second{"Jane", "Smith"};

  cout << first.first_name << endl;
  
  cout << boolalpha;
  
  cout << (
    &first.first_name.get() == &second.first_name.get()
  ) << endl;

  cout << (
    &first.last_name.get() == &second.last_name.get()
  ) << endl;
  
}
*/