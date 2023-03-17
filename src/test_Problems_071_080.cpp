#include "gtest/gtest.h"

#include "problems_071_080/Problem_071.hpp"
#include "problems_071_080/Problem_072.hpp"
#include "problems_071_080/Problem_073.hpp"
#include "problems_071_080/Problem_074.hpp"
#include "problems_071_080/Problem_075.hpp"
#include "problems_071_080/Problem_076.hpp"
#include "problems_071_080/Problem_077.hpp"
#include "problems_071_080/Problem_078.hpp"
#include "problems_071_080/Problem_079.hpp"
#include "problems_071_080/Problem_080.hpp"

// Problem 071
TEST( Problem_71, Test_Case ) {
  int const result = prob71::rand5();

  EXPECT_TRUE( ( result >= 1 ) && ( result <= 5 ) );
}

// Problem 072
TEST( Problem_72, Given_Case_1 ) {
  std::vector<std::pair<int, int>> const edges = { std::make_pair( 0, 1 ), std::make_pair( 0, 2 ), std::make_pair( 2, 3 ),
                                                   std::make_pair( 3, 4 ) };

  int const result = pathValue( "ABACA", edges );

  EXPECT_EQ( 3, result );
}

TEST( Problem_72, Given_Case_2 ) {
  std::vector<std::pair<int, int>> const edges = { std::make_pair( 0, 0 ) };

  int const result = pathValue( "A", edges );

  EXPECT_EQ( -1, result );
}

TEST( Problem_72, Test_Case ) {
  std::vector<std::pair<int, int>> const edges = { std::make_pair( 0, 1 ), std::make_pair( 1, 0 ) };

  int const result = pathValue( "AB", edges );

  EXPECT_EQ( -1, result );
}

// Problem 073
TEST( Problem_73, Test_Case ) {
  slList<int> list;
  list.add( new slNode( 1 ) );
  list.add( new slNode( 2 ) );
  list.add( new slNode( 3 ) );

  reverse_slList( list );

  EXPECT_EQ( 3, list.get( 0 )->value );
  EXPECT_EQ( 2, list.get( 1 )->value );
  EXPECT_EQ( 1, list.get( 2 )->value );
}

// Problem 074
TEST( Problem_74, Given_Case ) {
  int const result = countMultiples( 6, 12 );

  EXPECT_EQ( 4, result );
}

TEST( Problem_74, Test_Case ) {
  int const result = countMultiples( 10, 100 );

  EXPECT_EQ( 1, result );
}

// Problem 075
TEST( Problem_75, Given_Case ) {
  std::vector<int> const arr = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };

  int const result = longest_increasing_subsequence( arr );

  EXPECT_EQ( 6, result );
}

// Problem 076
TEST( Problem_76, Given_Case_1 ) {
  std::vector<std::string> const arr = { "cba", "daf", "ghi" };

  int const result = rows_to_remove( arr );

  EXPECT_EQ( 1, result );
}

TEST( Problem_76, Given_Case_2 ) {
  std::vector<std::string> const arr = { "abcdef" };

  int const result = rows_to_remove( arr );

  EXPECT_EQ( 0, result );
}

TEST( Problem_76, Given_Case_3 ) {
  std::vector<std::string> const arr = { "zyx", "wvu", "tsr" };

  int const result = rows_to_remove( arr );

  EXPECT_EQ( 3, result );
}

// Problem 077
TEST( Problem_77, Given_Case ) {
  std::vector<std::pair<int, int>> const intervals = { std::make_pair( 1, 3 ), std::make_pair( 5, 8 ), std::make_pair( 4, 10 ),
                                                       std::make_pair( 20, 25 ) };
  std::vector<std::pair<int, int>> const expected  = { std::make_pair( 1, 3 ), std::make_pair( 4, 10 ),
                                                       std::make_pair( 20, 25 ) };
  std::vector<std::pair<int, int>> const result    = merge_overlaping_intervals( intervals );

  EXPECT_EQ( expected, result );
}

TEST( Problem_77, Test_Case ) {
  std::vector<std::pair<int, int>> const intervals = { std::make_pair( 1, 3 ),   std::make_pair( 2, 3 ),
                                                       std::make_pair( 5, 8 ),   std::make_pair( 4, 10 ),
                                                       std::make_pair( 20, 25 ), std::make_pair( 18, 30 ) };
  std::vector<std::pair<int, int>> const expected  = { std::make_pair( 1, 3 ), std::make_pair( 4, 10 ),
                                                       std::make_pair( 18, 30 ) };
  std::vector<std::pair<int, int>> const result    = merge_overlaping_intervals( intervals );

  EXPECT_EQ( expected, result );
}

// Problem 078
TEST( Problem_78, Test_Case ) {
  std::vector<std::forward_list<int>> const lists = {
    { 1, 2, 3, 4 },
    { 5, 8, 15, 20 },
    { 6, 9, 10, 11, 19 }
  };
  std::forward_list<int> const expected = { 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 15, 19, 20 };
  std::forward_list<int> const result   = combine_lists( lists );

  EXPECT_EQ( expected, result );
}

// Problem 079
TEST( Problem_79, Given_Case_1 ) {
  std::vector<int> const nums   = { 10, 5, 7 };
  bool const             result = remove_one_non_decrease( nums );
  EXPECT_TRUE( result );
}

TEST( Problem_79, Given_Case_2 ) {
  std::vector<int> const nums   = { 10, 5, 1 };
  bool const             result = remove_one_non_decrease( nums );
  EXPECT_FALSE( result );
}

// Problem 080
TEST( Problem_80, Given_Case ) {
  /*
        a
       / \
      b   c
     /
    d
  */

  auto *a       = new btNode( 'a' );
  a->left       = new btNode( 'b' );
  a->left->left = new btNode( 'd' );
  a->right      = new btNode( 'c' );

  auto *result = find_deepest( a );

  EXPECT_EQ( a->left->left, result );
}