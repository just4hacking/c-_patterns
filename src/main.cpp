#include <speaker.h>
#include <talker.h>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace hello;
using namespace talk; 
using namespace boost;

struct Journal {
  string title;
  vector<string> entries;

  Journal(const string& title): title(title) {}

  void add_entry(const string& entry) {
    static int count = 1;
    entries.push_back(lexical_cast<string>(count++) + ": " + entry);

  }
};

int main(int argc, char *argv[]) {
  Journal journal("Dear Diary");
  journal.add_entry("I ate a bug");
  journal.add_entry("I cried today");
  cout<<"hello"<< endl;
}