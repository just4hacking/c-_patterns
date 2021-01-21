/*
  1.  High-level modules should not depend on low-level modules
      Both should depend on abstractions
  
  2.  Abstractions should not depend on details,
      Details should depend on abstractions

  IT PROTECTS YOU FROM CHANGES IN IMPLEMENTATION DETAILS
*/

#include <vector>
#include <string>

using namespace std;

enum class Relationship {
  parent,
  child,
  sibling
};

struct Person {
  string name;
};

//low-level
//imagine we decide to change the store of relations
//all the ,modules that depend on this one are forced to be
//refactored
struct BadRelationships {
  vector<tuple<Person, Relationship, Person>> relations;

  void add_parent_and_child(const Person& parent, const Person& child) {
    relations.push_back({ parent, Relationship::parent, child });
    relations.push_back({ child, Relationship::child, parent });
  }
};

// high-level. it depends on a concrete implementation (vector)
struct BadResearch {
  BadResearch(BadRelationships& BadRelationships) {
    auto& relations = BadRelationships.relations;
    for (auto&& [first, rel, second] : relations) {
      if (first.name == "John" && rel == Relationship::parent) {
        cout << "John has a child called " << second.name << endl;
      }
    }
  }
};

//SOLUTION
//How to solve it? introduce an 
//abstractions and move some parts into low-level module
struct RelationshipBrowser {
  virtual vector<Person> find_all_children_of(const string& name) = 0;
};

//low-level
struct Relationships : RelationshipBrowser {
  vector<tuple<Person, Relationship, Person>> relations;

  void add_parent_and_child(const Person& parent, const Person& child) {
    relations.push_back({ parent, Relationship::parent, child });
    relations.push_back({ child, Relationship::child, parent });
  }

  vector<Person> find_all_children_of(const string& name) override {
    vector<Person> result;
    for (auto&& [first, rel, second] : relations) {
      if (first.name == name && rel == Relationship::parent) {
        result.push_back(second);
      }
    }
    return result;
  }  
};

//it doesn't depend on low-level relationships and
//it works trough an abstraction
struct Research {
  Research(RelationshipBrowser& browser) {
    for (auto& child : browser.find_all_children_of("John")) {
      cout << "John has a child called " << child.name << endl;
    }
  }
};

/*
EXAMPLE

int main(int argc, char *argv[]) {
  Person parent{"John"};
  Person child1{"Chris"}, child2{"Matt"};

  Relationships relationships;
  relationships.add_parent_and_child(parent, child1);
  relationships.add_parent_and_child(parent, child2);
  
  Research _(relationships);

  return 0;
}
*/

