#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>
#include "./journal.hpp"

using namespace std;
using namespace boost;

Journal::Journal(const string& title): title(title) 
{}

void Journal::add_entry(const string& entry) {
  static int count = 1;
  entries.push_back(lexical_cast<string>(count++) + ": " + entry);
}