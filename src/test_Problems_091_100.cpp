#include "Problem_091.hpp"
#include "Problem_092.hpp"

#include "gtest/gtest.h"

// Problem 92
TEST( Problem_92, Given_Case )
{
  /*
  For example, given {'CSC300': ['CSC100', 'CSC200'],
                      'CSC200': ['CSC100'],
                      'CSC100': []},
  should return ['CSC100', 'CSC200', 'CSCS300'].
  */

  std::map<std::string, std::vector<std::string>> course_dependencies = { { "CSC300", { "CSC100", "CSC200" } }, { "CSC200", { "CSC100" } }, { "CSC100", {} } };

  std::vector<std::string> expected = { "CSC100", "CSC200", "CSC300" };
  std::vector<std::string> result   = course_order( course_dependencies );

  EXPECT_EQ( expected, result );
}