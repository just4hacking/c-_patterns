#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
class HtmlBuilder;

class HtmlElement {
  friend class HtmlBuilder;
  string name, text;
  vector<HtmlElement> elements;

  const size_t indent_size = 2;

  HtmlElement() {}

  HtmlElement(const string& name, const string& text) :
    name(name), text(text) {}
public:
  string str(int indent = 0) const {
    ostringstream oss;
    string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << endl;

    if (text.size() > 0) {
      oss << string(indent_size * (indent + 1), ' ') << text << endl;
    }

    for (const auto& e : elements) {
      oss << e.str(indent + 1);
    }

    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }

  /*
  doesnt'work because of circular dependency, 
  spliting the types into h/cpp would work
  
  static HtmlBuilder* create(string root_name) {
    return new HtmlBuilder{root_name};
  }
  */
};

//instead of constructing object in a single line we
//create a seperate object for this
//it allows us to construct complex objects step by step
class HtmlBuilder {
  HtmlElement root;
public:
  HtmlBuilder(string root_name) {
    root.name = root_name;
  }

  HtmlBuilder& add_child(string child_name, string child_text) {
    HtmlElement e{child_name, child_text};
    root.elements.emplace_back(e);
    //to enable fluent building
    return *this;
  }

  string str() const {
    return root.str();
  }

  operator HtmlElement() const {
    return root;
  }

  static HtmlBuilder create(string root_name) {
    return {root_name};
  }
};

/*
EXAMPLE
int main(int argc, char *argv[]) {
  //fluent builder
  auto builder = HtmlBuilder::create("ul")
    .add_child("li", "hello")
    .add_child("li", "world");

  auto el = static_cast<HtmlElement>(builder);

  cout << builder.str() << endl;
  cout << el.str() << endl;
  return 0;
}

*/
