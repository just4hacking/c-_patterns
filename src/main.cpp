#include <speaker.h>
#include <talker.h>
#include "./journal.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  Journal journal("Dear Diary");
  journal.add_entry("I ate a bug");
  journal.add_entry("I cried today");
  cout<<"hello"<< endl;
}