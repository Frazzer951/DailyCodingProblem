#include "gtest/gtest.h"

#include "problems_041_050/Problem_041.hpp"
#include "problems_041_050/Problem_042.hpp"
#include "problems_041_050/Problem_043.hpp"
#include "problems_041_050/Problem_044.hpp"
#include "problems_041_050/Problem_045.hpp"
#include "problems_041_050/Problem_046.hpp"
#include "problems_041_050/Problem_047.hpp"
#include "problems_041_050/Problem_048.hpp"
#include "problems_041_050/Problem_049.hpp"
#include "problems_041_050/Problem_050.hpp"

// Problem 041
TEST( Problem_41, Given_Case_1 ) {
  // Given [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport 'YUL',
  // return ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

  std::vector<std::pair<std::string, std::string>> const flights = { std::make_pair( "SFO", "HKO" ),
                                                                     std::make_pair( "YYZ", "SFO" ),
                                                                     std::make_pair( "YUL", "YYZ" ),
                                                                     std::make_pair( "HKO", "ORD" ) };

  std::vector<std::string> const result   = getItinerary( flights, "YUL" );
  std::vector<std::string> const expected = { "YUL", "YYZ", "SFO", "HKO", "ORD" };

  EXPECT_EQ( result, expected );
}

TEST( Problem_41, Given_Case_2 ) {
  // Given [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', return null.

  std::vector<std::pair<std::string, std::string>> const flights = { std::make_pair( "SFO", "COM" ),
                                                                     std::make_pair( "COM", "YYZ" ) };

  std::vector<std::string> const result   = getItinerary( flights, "COM" );
  std::vector<std::string> const expected = {};

  EXPECT_EQ( result, expected );
}

TEST( Problem_41, Given_Case_3 ) {
  // Given [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', return ['A', 'B', 'C', 'A', 'C']

  std::vector<std::pair<std::string, std::string>> const flights = { std::make_pair( "A", "B" ), std::make_pair( "A", "C" ),
                                                                     std::make_pair( "B", "C" ), std::make_pair( "C", "A" ) };

  std::vector<std::string> const result   = getItinerary( flights, "A" );
  std::vector<std::string> const expected = { "A", "B", "C", "A", "C" };

  EXPECT_EQ( result, expected );
}

// Problem 042
TEST( Problem_42, Given_Case ) {
  // given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24
  auto                   result   = subset_sum( { 12, 1, 61, 5, 9, 2 }, 24 );
  std::vector<int> const expected = { 12, 1, 9, 2 };

  EXPECT_EQ( result, expected );
}

// Problem 043
TEST( Problem_43, Test_Push ) {
  stack testStack;
  testStack.push( 10 );

  EXPECT_EQ( testStack.top->val, 10 );
}

TEST( Problem_43, Test_Pop ) {
  stack testStack;
  testStack.push( 15 );

  int const result   = testStack.pop();
  int const expected = 15;

  EXPECT_EQ( result, expected );
}

TEST( Problem_43, Test_Pop_Exception ) {
  stack testStack;

  EXPECT_ANY_THROW( testStack.pop() );
}

TEST( Problem_43, Test_getMax ) {
  stack testStack;
  testStack.push( 15 );
  testStack.push( 18 );
  testStack.push( 2 );

  int const result   = testStack.getMax();
  int const expected = 18;

  EXPECT_EQ( result, expected );
}

TEST( Problem_43, Test_getMax_Exception ) {
  stack const testStack;
  int         x = 0;
  EXPECT_ANY_THROW( x = testStack.getMax() );
  if ( x == 10 ) x++;
}

// Problem 044
TEST( Problem_44, Given_Case_1 ) {
  // The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4,3).
  int const result   = outOfOrder( { 2, 4, 1, 3, 5 } );
  int const expected = 3;

  EXPECT_EQ( result, expected );
}

TEST( Problem_44, Given_Case_2 ) {
  // The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.

  int const result   = outOfOrder( { 5, 4, 3, 2, 1 } );
  int const expected = 10;

  EXPECT_EQ( result, expected );
}

// Problem 045
TEST( Problem_45, Test_Case ) {
  int const result = rand7();

  EXPECT_TRUE( ( result >= 1 ) && ( result <= 7 ) );
}

// Problem 046
TEST( Problem_46, Given_Case_1 ) {
  // "aabcdcb" is "bcdcb"
  std::string const result   = longest_palindrome( "aabcdcb" );
  std::string const expected = "bcdcb";

  EXPECT_EQ( result, expected );
}

TEST( Problem_46, Given_Case_2 ) {
  // "bananas" is "anana"
  std::string const result   = longest_palindrome( "bananas" );
  std::string const expected = "anana";

  EXPECT_EQ( result, expected );
}

// Problem 047
TEST( Problem_47, Given_Case ) {
  //[9, 11, 8, 5, 7, 10], you should return 5
  int const result   = max_profit( { 9, 11, 8, 5, 7, 10 } );
  int const expected = 5;

  EXPECT_EQ( result, expected );
}

TEST( Problem_47, Test_Case ) {
  int const result   = max_profit( { 10, 16, 7, 18, 5, 9 } );
  int const expected = 11;

  EXPECT_EQ( result, expected );
}

// Problem 048
TEST( Problem_48, Given_Case ) {
  /*
  For example, given the following preorder traversal:
  [a, b, d, e, c, f, g]
  And the following inorder traversal:
  [d, b, e, a, f, c, g]
  You should return the following tree:
      a
     / \
    b   c
   / \ / \
  d  e f  g
  */

  auto *a = new btNode( 'a' );
  auto *b = new btNode( 'b' );
  auto *c = new btNode( 'c' );
  auto *d = new btNode( 'd' );
  auto *e = new btNode( 'e' );
  auto *f = new btNode( 'f' );
  auto *g = new btNode( 'g' );

  std::vector<btNode<char> *> const preorder = { a, b, d, e, c, f, g };
  std::vector<btNode<char> *> const inorder  = { d, b, e, a, f, c, g };

  auto *result = reconstruct( preorder, inorder );

  EXPECT_EQ( result, a );
}

// Problem 049
TEST( Problem_49, Given_Case_1 ) {
  // [34, -50, 42, 14, -5, 86], the maximum sum would be 137
  int const result   = max_subarray_sum( { 34, -50, 42, 14, -5, 86 } );
  int const expected = 137;

  EXPECT_EQ( result, expected );
}

TEST( Problem_49, Given_Case_2 ) {
  // [-5, -1, -8, -9], the maximum sum would be 0
  int const result   = max_subarray_sum( { -5, -1, -8, -9 } );
  int const expected = 0;

  EXPECT_EQ( result, expected );
}

// Problem 050
TEST( Problem_50, Given_Case ) {
  /*
  For example, given the following tree:

      *
     / \
    +   +
   / \ / \
  3  2 4  5

  You should return 45, as it is (3 + 2) * (4 + 5).
  */
  btNode root( '*' );
  root.left         = new btNode( '+' );
  root.right        = new btNode( '+' );
  root.left->left   = new btNode( '3' );
  root.left->right  = new btNode( '2' );
  root.right->left  = new btNode( '4' );
  root.right->right = new btNode( '5' );

  int const result   = evaluate( root );
  int const expected = 45;

  EXPECT_EQ( result, expected );
}
