#include <vector>
#include <gtest/gtest.h>
#include <iostream>
#include "./src/singleton/index.hpp"

using namespace std;

// there is a problem with singleton
TEST(RecordFinderTests, SingletonTotalPopulationTest) {
  SingletonRecordFinder rf;
  vector<string> names{"Seoul", "Mexico City"};
  int tp = rf.total_population(names);
  ASSERT_EQ(17500000+17400000, tp);
}

// much better way of dealing with a dependency on a singleton
TEST(RecordFinderTests, DependendantTotalPopulationTest) {
  DummyDatabase db;
  ConfigurableRecordFinder rf{db};
  vector<string> names{"alpha", "gamma"};
  int tp = rf.total_population(names);
  EXPECT_EQ(4, tp);
}

int dsfmain(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av); 
  return RUN_ALL_TESTS();
}