#include <numeric>

#include "gtest/gtest.h"

#include "problems_171_180/Problem_171.hpp"
#include "problems_171_180/Problem_172.hpp"
#include "problems_171_180/Problem_173.hpp"
#include "problems_171_180/Problem_174.hpp"
#include "problems_171_180/Problem_175.hpp"
#include "problems_171_180/Problem_176.hpp"
#include "problems_171_180/Problem_177.hpp"
#include "problems_171_180/Problem_178.hpp"
#include "problems_171_180/Problem_179.hpp"
#include "problems_171_180/Problem_180.hpp"

// Problem 171
TEST( Problem_171, Test_Case ) {
  std::vector<Timelog> entries = {
    {  0,  3, Type::enter},
    { 10,  6,  Type::exit},
    {  3, 15, Type::enter},
    { 99,  2,  Type::exit},
    {100,  4,  Type::exit},
    { 18,  5,  Type::exit},
    {  5,  1, Type::enter},
    {  6,  2,  Type::exit}
  };

  std::pair<long, long> result = busiest_period( entries );
  std::pair<long, long> expected( 5, 6 );

  EXPECT_EQ( result, expected );
}

// Problem 172
TEST( Problem_172, Given_Case_1 ) {
  // Given s = "dogcatcatcodecatdog" and words = ["cat", "dog"], return [0, 13]
  std::vector<int> result   = indiciesOfSubstrings( "dogcatcatcodecatdog", { "cat", "dog" } );
  std::vector<int> expected = { 0, 13 };

  EXPECT_EQ( result, expected );
}

TEST( Problem_172, Given_Case_2 ) {
  // Given s = "barfoobazbitbyte" and words = ["dog", "cat"], return []
  std::vector<int> result   = indiciesOfSubstrings( "barfoobazbitbyte", { "dog", "cat" } );
  std::vector<int> expected = {};

  EXPECT_EQ( result, expected );
}

// Problem 173
TEST( Problem_173, Given_Case ) {
  std::map<std::string, std::any> vals;
  std::map<std::string, std::any> foo;
  std::map<std::string, std::any> bar;
  bar["baz"]  = 8;
  foo["a"]    = 5;
  foo["bar"]  = bar;
  vals["key"] = 3;
  vals["foo"] = foo;

  std::map<std::string, int> expected;
  expected["key"]         = 3;
  expected["foo.a"]       = 5;
  expected["foo.bar.baz"] = 8;

  std::map<std::string, int> result = flatten( vals );

  EXPECT_EQ( result, expected );
}

// Problem 174

// Problem 175
TEST( Problem_175, Test_Case ) {
  std::vector<transition> transitions = {
    {'a', 'a',   0.9},
    {'a', 'b', 0.075},
    {'a', 'c', 0.025},
    {'b', 'a',  0.15},
    {'b', 'b',   0.8},
    {'b', 'c',  0.05},
    {'c', 'a',  0.25},
    {'c', 'b',  0.25},
    {'c', 'c',   0.5}
  };

  auto result = markovChain( 'a', 5000, transitions );
}

// Problem 176
TEST( Problem_176, Given_Case ) {
  EXPECT_TRUE( canMap( "abc", "bcd" ) );
  EXPECT_FALSE( canMap( "foo", "bar" ) );
}

// Problem 177
TEST( Problem_177, Given_Case_1 ) {
  // Given the linked list 7 -> 7 -> 3 -> 5 and k = 2, it should become 3 -> 5 -> 7 -> 7

  auto        *head     = new slNode<int>( { 7, 7, 3, 5 } );
  auto        *expected = new slNode<int>( { 3, 5, 7, 7 } );
  slNode<int> *result   = rotate( head, 2 );

  EXPECT_EQ( *result, *expected );
}

TEST( Problem_177, Given_Case_2 ) {
  // Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3, it should become 3 -> 4 -> 5 -> 1 -> 2.

  auto        *head     = new slNode<int>( { 1, 2, 3, 4, 5 } );
  auto        *expected = new slNode<int>( { 3, 4, 5, 1, 2 } );
  slNode<int> *result   = rotate( head, 3 );

  EXPECT_EQ( *result, *expected );
}

// Problem 178
TEST( Problem_178, Test_Case ) {
  std::vector<int> count56;
  std::vector<int> count55;

  for ( int i = 0; i < 10000; i++ ) {
    count56.push_back( diceSim( { 5, 6 } ) );
    count55.push_back( diceSim( { 5, 5 } ) );
  }

  double average56 = std::accumulate( count56.begin(), count56.end(), 0 ) / 10000.0;
  double average55 = std::accumulate( count55.begin(), count55.end(), 0 ) / 10000.0;

  std::cout << "55: " << average55 << '\n';
  std::cout << "56: " << average56 << '\n';
}

// Problem 179
TEST( Problem_179, Given_Case ) {
  /*
  For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the following tree:

      5
     / \
    3   7
   / \   \
  2   4   8
  */

  auto *expected = new btNode( 5 );
  expected       = add( expected, 7 );
  expected       = add( expected, 8 );
  expected       = add( expected, 3 );
  expected       = add( expected, 4 );
  expected       = add( expected, 2 );

  auto *result = createBSTfromPostOrder( { 2, 4, 3, 8, 7, 5 } );

  EXPECT_EQ( *result, *expected );
}

// Problem 180
TEST( Problem_180, Given_Case_1 ) {
  // If the stack is [1, 2, 3, 4, 5], it should become [1, 5, 2, 4, 3]
  std::stack<int> s( { 1, 2, 3, 4, 5 } );
  std::stack<int> result = interleave( s );
  std::stack<int> expected( { 1, 5, 2, 4, 3 } );

  EXPECT_EQ( result, expected );
}

TEST( Problem_180, Given_Case_2 ) {
  // If the stack is [1, 2, 3, 4], it should become [1, 4, 2, 3]
  std::stack<int> s( { 1, 2, 3, 4 } );
  std::stack<int> result = interleave( s );
  std::stack<int> expected( { 1, 4, 2, 3 } );

  EXPECT_EQ( result, expected );
}