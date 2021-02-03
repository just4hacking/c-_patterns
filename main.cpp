#include <iostream>
#include <cmath>
#include <memory>
#include <vector>

#include "./src/builder/index.hpp"
#include "./src/prototype/index.hpp"
#include "./src/factory/index.hpp"
#include "./src/singleton/index.hpp"
#include "./src/adapter/index.hpp"
#include "./src/bridge/index.hpp"
#include "./src/composite/index.hpp"
#include "./src/decorator/index.hpp"
#include "./src/flyweight/index.hpp"
#include "./src/proxy/index.hpp"
#include "./src/chain_of_responsibility/index.hpp"
#include "./src/command/index.hpp"

using namespace std;


int main(int argc, char *argv[])
{
  command::BankAccount ba;

  vector<command::BankAccountCommand> commands {
    command::BankAccountCommand{ba, command::BankAccountCommand::Action::deposit, 100},
    command::BankAccountCommand{ba, command::BankAccountCommand::Action::withdraw, 200}
  };

  cout << ba << endl;

  for (auto& cmd : commands) {
    cmd.call();
  }

  for (auto it = commands.rbegin(); it != commands.rend(); ++it) {
    it->undo();
  }

  cout << ba << endl;

  //composite
  command::BankAccount ba2;
  ba2.deposit(100);

  command::MoneyTransferCommand cmd{ba, ba2, 50000};
  cmd.call();

  cout << ba << endl << ba2 << endl;

  cmd.undo();

  cout << ba << endl << ba2 << endl;
}
