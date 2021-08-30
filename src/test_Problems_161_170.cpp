#include "Problem_161.hpp"
#include "Problem_162.hpp"
#include "Problem_163.hpp"
#include "Problem_164.hpp"
#include "Problem_165.hpp"
#include "Problem_166.hpp"
#include "Problem_167.hpp"
#include "Problem_168.hpp"

#include "gtest/gtest.h"

// Problem 161
TEST( Problem_161, Given_Case )
{
  // given 1111 0000 1111 0000 1111 0000 1111 0000, return 0000 1111 0000 1111 0000 1111 0000 1111
  long int x      = 0xF0F0F0F0;
  long int result = reverse( x );

  EXPECT_EQ( result, 0x0F0F0F0F );
}

// Problem 162
TEST( Problem_162, Given_Case )
{
  /*
  given the list:
    dog
    cat
    apple
    apricot
    fish

  Return the list:
    d
    c
    app
    apr
    f
  */

  std::vector<std::string> lst      = { "dog", "cat", "apple", "apricot", "fish" };
  std::vector<std::string> expected = { "d", "c", "app", "apr", "f" };
  std::vector<std::string> result   = shortest_unique_prefix( lst );

  EXPECT_EQ( result, expected );
}

// Problem 163
TEST( Problem_163, Given_Case )
{
  // [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'] should return 5, since it is equivalent to
  // ( ( 15 / ( 7 - ( 1 + 1 ) ) ) * 3 ) - ( 2 + ( 1 + 1 ) ) = 5.

  std::vector<std::string> equation = { "15", "7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-" };
  double                   result   = solve( equation );
  EXPECT_DOUBLE_EQ( result, 5.0 );
}

// Problem 164
TEST( Problem_164, Test_Case_1 )
{
  std::vector<int> arr = { 1, 2, 3, 4, 3, 5, 6, 7, 8, 9 };
  EXPECT_EQ( findDuplicate( arr ), 3 );
}

TEST( Problem_164, Test_Case_2 )
{
  std::vector<int> arr = { 1, 2, 3, 4, 9, 5, 6, 7, 8, 9 };
  EXPECT_EQ( findDuplicate( arr ), 9 );
}

// Problem 165
TEST( Problem_165, Given_Case )
{
  std::vector<int> arr      = { 3, 4, 9, 6, 1 };
  std::vector<int> expected = { 1, 1, 2, 1, 0 };
  std::vector<int> result   = rightSmaller( arr );
  EXPECT_EQ( result, expected );
}

// Problem 166
TEST( Problem_166, Given_Case )
{
  // For example, given the input [[1, 2], [3], [], [4, 5, 6]], calling next() repeatedly should output 1, 2, 3, 4,
  // 5, 6.

  std::vector<std::vector<int>> arr = { { 1, 2 }, { 3 }, {}, { 4, 5, 6 } };

  iterator2D it( arr );

  EXPECT_TRUE( it.has_next() );
  EXPECT_EQ( it.next(), 1 );
  EXPECT_TRUE( it.has_next() );
  EXPECT_EQ( it.next(), 2 );
  EXPECT_TRUE( it.has_next() );
  EXPECT_EQ( it.next(), 3 );
  EXPECT_TRUE( it.has_next() );
  EXPECT_EQ( it.next(), 4 );
  EXPECT_TRUE( it.has_next() );
  EXPECT_EQ( it.next(), 5 );
  EXPECT_TRUE( it.has_next() );
  EXPECT_EQ( it.next(), 6 );
  EXPECT_FALSE( it.has_next() );
  EXPECT_ANY_THROW( it.next() );
}