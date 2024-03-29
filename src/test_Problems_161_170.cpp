#include "gtest/gtest.h"

#include "problems_161_170/Problem_161.hpp"
#include "problems_161_170/Problem_162.hpp"
#include "problems_161_170/Problem_163.hpp"
#include "problems_161_170/Problem_164.hpp"
#include "problems_161_170/Problem_165.hpp"
#include "problems_161_170/Problem_166.hpp"
#include "problems_161_170/Problem_167.hpp"
#include "problems_161_170/Problem_168.hpp"
#include "problems_161_170/Problem_169.hpp"
#include "problems_161_170/Problem_170.hpp"

// Problem 161
TEST( Problem_161, Given_Case ) {
  // given 1111 0000 1111 0000 1111 0000 1111 0000, return 0000 1111 0000 1111 0000 1111 0000 1111
  long int const x      = 0xF0F0F0F0;
  long int const result = reverse( x );

  EXPECT_EQ( result, 0x0F0F0F0F );
}

// Problem 162
TEST( Problem_162, Given_Case ) {
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

  std::vector<std::string> const lst      = { "dog", "cat", "apple", "apricot", "fish" };
  std::vector<std::string> const expected = { "d", "c", "app", "apr", "f" };
  std::vector<std::string> const result   = shortest_unique_prefix( lst );

  EXPECT_EQ( result, expected );
}

// Problem 163
TEST( Problem_163, Given_Case ) {
  // [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'] should return 5, since it is equivalent to
  // ( ( 15 / ( 7 - ( 1 + 1 ) ) ) * 3 ) - ( 2 + ( 1 + 1 ) ) = 5.

  std::vector<std::string> const equation = { "15", "7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-" };
  double const                   result   = solve( equation );
  EXPECT_DOUBLE_EQ( result, 5.0 );
}

// Problem 164
TEST( Problem_164, Test_Case_1 ) {
  std::vector<int> const arr = { 1, 2, 3, 4, 3, 5, 6, 7, 8, 9 };
  EXPECT_EQ( findDuplicate( arr ), 3 );
}

TEST( Problem_164, Test_Case_2 ) {
  std::vector<int> const arr = { 1, 2, 3, 4, 9, 5, 6, 7, 8, 9 };
  EXPECT_EQ( findDuplicate( arr ), 9 );
}

// Problem 165
TEST( Problem_165, Given_Case ) {
  std::vector<int> const arr      = { 3, 4, 9, 6, 1 };
  std::vector<int> const expected = { 1, 1, 2, 1, 0 };
  std::vector<int> const result   = rightSmaller( arr );
  EXPECT_EQ( result, expected );
}

// Problem 166
TEST( Problem_166, Given_Case ) {
  // For example, given the input [[1, 2], [3], [], [4, 5, 6]], calling next() repeatedly should output 1, 2, 3, 4,
  // 5, 6.

  std::vector<std::vector<int>> const arr = {
    { 1, 2 },
    { 3 },
    {},
    { 4, 5, 6 }
  };

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

// Problem 167
TEST( Problem_167, Given_Case ) {
  // given the list ["code", "edoc", "da", "d"], return [(0, 1), (1, 0), (2, 3)]

  std::vector<std::string> const         words    = { "code", "edoc", "da", "d" };
  std::vector<std::pair<int, int>> const expected = {
    {0, 1},
    {1, 0},
    {2, 3}
  };
  std::vector<std::pair<int, int>> const result = palindromes( words );

  EXPECT_EQ( result, expected );
}

// Problem 168
TEST( Problem_168, Given_Case ) {
  /*
    [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
    you should return:

    [[7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]]
  */
  std::vector<std::vector<int>> const arr = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  std::vector<std::vector<int>> const expected = {
    {7, 4, 1},
    {8, 5, 2},
    {9, 6, 3}
  };
  std::vector<std::vector<int>> const result = rotate90( arr );

  EXPECT_EQ( result, expected );
}

// Problem 169
TEST( Problem_169, Given_Case ) {
  // the linked list 4 -> 1 -> -3 -> 99 should become -3 -> 1 -> 4 -> 99

  LNode *a        = nullptr;
  LNode *expected = nullptr;

  push( &a, 99 );
  push( &a, -3 );
  push( &a, 1 );
  push( &a, 4 );

  push( &expected, 99 );
  push( &expected, 4 );
  push( &expected, 1 );
  push( &expected, -3 );

  MergeSort( &a );

  EXPECT_EQ( *a, *expected );
}

// Problem 170
TEST( Problem_170, Given_Case_1 ) {
  // given start = "dog", end = "cat", and dictionary = {"dot", "dop", "dat", "cat"}, return ["dog", "dot", "dat",
  // "cat"].

  std::vector<std::string> const dict     = { "dot", "dop", "dat", "cat" };
  std::vector<std::string> const expected = { "dog", "dot", "dat", "cat" };
  std::vector<std::string> const result   = shortestTransform( "dog", "cat", dict );

  EXPECT_EQ( result, expected );
}

TEST( Problem_170, Given_Case_2 ) {
  // Given start = "dog", end = "cat", and dictionary = {"dot", "tod", "dat", "dar"}, return {}

  std::vector<std::string> const dict     = { "dot", "tod", "dat", "dar" };
  std::vector<std::string> const expected = {};
  std::vector<std::string> const result   = shortestTransform( "dog", "cat", dict );

  EXPECT_EQ( result, expected );
}