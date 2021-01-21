/* OPEN-CLOSED PRINCIPLE + SPECIFICATION PATTERN */

#include <vector>
#include <string>

using namespace std;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product {
  string name;
  Color color;
  Size size;
};

//to add a new filter you always need to modify this class
struct BadFilter {
  vector<Product*> by_color(vector<Product*> items, Color color) {
    vector<Product*> result;
    for (auto& i : items)
      if (i->color == color)
        result.push_back(i);
    return result;
  }
};

//will be implemented later
template <typename T> struct AndSpecification;

//satisfies open-closed princinple
//open to extension closed to modification
//if you need one more filter you just inherit 
//one more class from Specification interface
template <typename T> struct Specification {
  virtual bool is_satisfied(T* item) = 0;

  AndSpecification<T> operator&&(Specification<T>&& right) {
    return AndSpecification<T>(*this, right);
  }
};

template <typename T> struct Filter {
  virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

struct GoodFilter : Filter<Product> {
  vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) {
    vector<Product*> result;
    for (auto& i : items)
      if (spec.is_satisfied(i))
        result.push_back(i);
    return result;
  }
};

struct ColorSpecification : Specification<Product>
{
  Color color;
  ColorSpecification(Color color) : color(color) {};

  bool is_satisfied(Product* item) override {
    return item->color == color;
  }
};

struct SizeSpecification : Specification<Product>
{
  Size size;
  SizeSpecification(Size size) : size(size) {};

  bool is_satisfied(Product* item) override {
    return item->size == size;
  }
};

//we also can combine specifications so it gives us an extra flexibility
template <typename T> struct AndSpecification : Specification<T> {
  Specification<T>& left;
  Specification<T>& right;

  AndSpecification(Specification<T>& left, Specification<T>& right) 
    : left(left), right(right) {}

  bool is_satisfied(T* item) override {
    return left.is_satisfied(item) && right.is_satisfied(item);
  }
};

/* EXAMPLE

int main(int argc, char *argv[]) {
  Product apple{"Apple", Color::green, Size::small};
  Product tree{"Tree", Color::green, Size::large};
  Product house{"House", Color::blue, Size::large};
  
  GoodFilter product_filter;
  vector<Product*> items { &apple, &tree, &house };

  auto spec = ColorSpecification(Color::green) 
    && SizeSpecification(Size::large);

  auto green_things = product_filter.filter(items, spec);
  
  for (auto& item : green_things) {
    cout << item->name << " is green and " << item->size << endl;
  }
}
*/