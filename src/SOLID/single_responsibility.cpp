/* 
  Object should have only one (primary responsibility), so
  it should have only one reason to change
*/
#include <fstream>
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

struct Journal {
  string title;
  vector<string> entries;

  Journal(const string& title) : title(title) {}

  void add_entry(const string& entry) {
    static int count = 1;
    entries.push_back(lexical_cast<string>(count++) + ": " + entry);
  }

  //another concern, which is bad
  //what if you happen to change persistence,
  //for example, you would like to save to db
  void badSave(const string& filename) {
    ofstream ofs(filename);
    for (auto& e : entries) 
      ofs << e << endl;
  }
};

//Solution
//more robust and managable way
struct PersistenceManager {
  void save(const Journal& j, const string& filename) {
    ofstream ofs(filename);
    for (auto& e : j.entries) 
      ofs << e << endl;
  }
};

/* EXAMPLE
int main(int argc, char *argv[]) {
  Journal journal{"Dear Diary"};
  journal.add_entry("I ate a bug");
  journal.add_entry("I cried today");

  PersistenceManager saver;
  saver.save(journal, "diary.txt");
  return 0;
}
*/