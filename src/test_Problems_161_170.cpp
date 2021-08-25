#include "Problem_161.hpp"
#include "Problem_162.hpp"
#include "Problem_163.hpp"

#include "gtest/gtest.h"

// Problem 161
TEST( Problem_161, Given_Case )
{
  // given 1111 0000 1111 0000 1111 0000 1111 0000, return 0000 1111 0000 1111 0000 1111 0000 1111
  long int x      = 0xF0F0F0F0;
  long int result = reverse( x );

  EXPECT_EQ( result, 0x0F0F0F0F );
}