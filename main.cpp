#include <speaker.h>
#include <talker.h>

using namespace std;
using namespace hello;
using namespace talk;

int main(int argc, char *argv[]) {
  Speaker* speaker = new Speaker();
  Talker* talker = new Talker();

  speaker->sayHello();  
  talker->sayTalk();
  
}