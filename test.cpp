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
  cout << tp << endl;
  ASSERT_EQ(17500000+17400000, tp);
}

int dsfmain(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av); 
  return RUN_ALL_TESTS();
}