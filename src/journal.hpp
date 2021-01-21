#include <string>
#include <vector>

struct Journal {
  std::string title;
  std::vector<std::string> entries;

  Journal(const std::string& title);
  void add_entry(const std::string& entry);
};