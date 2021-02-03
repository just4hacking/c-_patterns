#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

namespace command {

using namespace std;

struct BankAccount {
  int balance{0};
  int overdraft_limit{-500};

  void deposit(int amount) {
    balance += amount;
    cout << "deposited " << amount 
         << ", balance is now " << balance << endl; 
  }

  bool withdraw(int amount) {
    if (balance - amount >= overdraft_limit) {
      balance -= amount;
      cout << "withdraw " << amount
           << ", balance is now" << balance << endl;
      return true;
    }
    return false;
  }

  friend ostream& operator<<(ostream& os, BankAccount& ba) {
    os << "balance: " << ba.balance << endl;
    return os; 
  }
};

struct Command {
  bool succeeded;
  virtual void call() = 0;
  virtual void undo() = 0;
};

struct BankAccountCommand : public Command {
  BankAccount& account;
  enum Action { deposit, withdraw } action;
  int amount;

  BankAccountCommand(BankAccount& account, Action action, int amount)
  : account(account), action(action), amount(amount) {
    succeeded = false;
  }

  void call() override {
    switch (action) {
      case deposit:
        account.deposit(amount);
        succeeded = true;
        break;
      case withdraw:
        succeeded = account.withdraw(amount);
        break;
    }
  }

  void undo() override {
    if (!succeeded)
      return;

    switch (action) {
      case Action::deposit:
        account.withdraw(amount);
        break;
      case Action::withdraw:
        account.deposit(amount);
        break;
    }
  }
};

struct CompositeBankAccountCommand : public vector<BankAccountCommand>, Command {
  CompositeBankAccountCommand(const std::initializer_list<BankAccountCommand>& items) 
  : vector(items) {

  }

  void call() override {
    for (auto& cmd : *this) {
      cmd.call();
    }
  }

  void undo() override {
    for (auto it = rbegin(); it != rend(); ++it) {
      it->undo();
    }
  }
};


struct DependentCompositeCommand : public CompositeBankAccountCommand {
  DependentCompositeCommand(const initializer_list<BankAccountCommand>& items)
  : CompositeBankAccountCommand(items) {

  }

  void call() override {
    bool ok = true;

    for (auto& cmd : *this) {
      if (ok) {
        cmd.call();
        ok = cmd.succeeded;
      } else {
        cmd.succeeded = false;
      }
    }
  }
  
};

struct MoneyTransferCommand : public DependentCompositeCommand {
  MoneyTransferCommand(BankAccount& from, BankAccount& to, int amount)
  : DependentCompositeCommand({ 
    BankAccountCommand{from, BankAccountCommand::Action::withdraw, amount},
    BankAccountCommand{to, BankAccountCommand::Action::deposit, amount}
  }) {}
};


}

/*
EXAMPLE

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
*/