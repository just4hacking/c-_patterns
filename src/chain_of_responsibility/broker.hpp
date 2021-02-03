#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <boost/signals2.hpp>

namespace chain {

using namespace boost;
using namespace boost::signals2;
using namespace std;

struct Query {
public:
  string creature_name;
  enum Argument { attack, defense } argument;
  int result;

  Query(const string& creature_name, Argument argument, int result)
  : argument(argument), result(result), creature_name(creature_name) {

  }
};

//mediator
struct Game {
  boost::signals2::signal<void(Query&)> queries;
};  

struct GameCreature {
  Game& game;
  int attack, defense;
  string name;

  GameCreature(Game& game, int attack, int defense, const string& name)
  : game(game), attack(attack), defense(defense), name(name) {

  }

  int get_attack() const {
    Query q{name, Query::Argument::attack, attack};
    game.queries(q);
    return q.result;
  }

  friend ostream& operator<<(ostream& os, const GameCreature& creature) {
    os << "attack: " << creature.get_attack() 
       << " name: " << creature.name;
    return os;
  }
};

class GameCreatureModifier {
  Game& game;
  GameCreature& creature;
public:
  GameCreatureModifier(Game& game, GameCreature& creature) 
  : game(game), creature(creature) {

  }

  virtual ~GameCreatureModifier() = default;
};

class DoubleAttackModifier2 : public GameCreatureModifier {
  boost::signals2::connection conn;
public:
  DoubleAttackModifier2(Game& game, GameCreature& creature) 
  : GameCreatureModifier(game, creature) {
    conn = game.queries.connect([&](Query& q) {
      if (q.creature_name == creature.name 
        && q.argument == Query::Argument::attack) {
        q.result *= 2;
      }
    });
  }

  ~DoubleAttackModifier2() {
    conn.disconnect();
  }
};

/*
EXAMPLE
int main(int argc, char *argv[])
{
  chain::Game game;
  chain::GameCreature goblin{game, 2, 2, "Strong Goblin"};

  cout << goblin << endl;

  {
    chain::DoubleAttackModifier2 dam{game, goblin};
    cout << goblin << endl;
  }

  cout << goblin << endl;
}
*/

}