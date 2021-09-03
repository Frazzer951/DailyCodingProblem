#include "Problem_171.hpp"
#include "Problem_172.hpp"

#include "gtest/gtest.h"

TEST( Problem_171, Test_Case )
{
  std::vector<Timelog> entries = { { 0, 3, Type::enter }, { 10, 6, Type::exit },  { 3, 15, Type::enter },
                                   { 99, 2, Type::exit }, { 100, 4, Type::exit }, { 18, 5, Type::exit },
                                   { 5, 1, Type::enter }, { 6, 2, Type::exit } };

  std::pair<long, long> result = busiest_period( entries );
  std::pair<long, long> expected( 5, 6 );

  EXPECT_EQ( result, expected );
}