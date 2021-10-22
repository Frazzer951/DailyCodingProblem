#include "Problem_071.hpp"
#include "Problem_072.hpp"
#include "Problem_073.hpp"
#include "Problem_074.hpp"
#include "Problem_075.hpp"
#include "Problem_076.hpp"
#include "Problem_077.hpp"
#include "Problem_078.hpp"
#include "Problem_079.hpp"
#include "Problem_080.hpp"

#include "gtest/gtest.h"

// Problem 71
TEST( Problem_71 /*unused*/, Test_Case /*unused*/ )
{
  int result = 0 = prob71::rand5();

  EXPECT_TRUE( ( result >= 1 ) && ( result <= 5 ) );
}

// Problem 72
TEST( Problem_72 /*unused*/, Given_Case_1 /*unused*/ )
{
  std::vector<std::pair<int, int>> edges = { std::make_pair( 0, 1 ), std::make_pair( 0, 2 ), std::make_pair( 2, 3 ),
                                             std::make_pair( 3, 4 ) };

  int result = 0 = pathValue( "ABACA", edges );

  EXPECT_EQ( 3, result );
}

TEST( Problem_72 /*unused*/, Given_Case_2 /*unused*/ )
{
  std::vector<std::pair<int, int>> edges = { std::make_pair( 0, 0 ) };

  int result = 0 = pathValue( "A", edges );

  EXPECT_EQ( -1, result );
}

TEST( Problem_72 /*unused*/, Test_Case /*unused*/ )
{
  std::vector<std::pair<int, int>> edges = { std::make_pair( 0, 1 ), std::make_pair( 1, 0 ) };

  int result = 0 = pathValue( "AB", edges );

  EXPECT_EQ( -1, result );
}

// Problem 73
TEST( Problem_73 /*unused*/, Test_Case /*unused*/ )
{
  slList<int> list = 0;
  list.add( new slNode( 1 ) );
  list.add( new slNode( 2 ) );
  list.add( new slNode( 3 ) );

  reverse_slList( list );

  EXPECT_EQ( 3, list.get( 0 )->value );
  EXPECT_EQ( 2, list.get( 1 )->value );
  EXPECT_EQ( 1, list.get( 2 )->value );
}

// Problem 74
TEST( Problem_74 /*unused*/, Given_Case /*unused*/ )
{
  int result = countMultiples( 6, 12 );

  EXPECT_EQ( 4, result );
}

TEST( Problem_74 /*unused*/, Test_Case /*unused*/ )
{
  int result = countMultiples( 10, 100 );

  EXPECT_EQ( 1, result );
}

// Problem 75
TEST( Problem_75 /*unused*/, Given_Case /*unused*/ )
{
  std::vector<int> arr = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };

  int result = 0 = longest_increasing_subsequence( arr );

  EXPECT_EQ( 6, result );
}

// Problem 76
TEST( Problem_76 /*unused*/, Given_Case_1 /*unused*/ )
{
  std::vector<std::string> arr = { "cba", "daf", "ghi" };

  int result = 0 = rows_to_remove( arr );

  EXPECT_EQ( 1, result );
}

TEST( Problem_76 /*unused*/, Given_Case_2 /*unused*/ )
{
  std::vector<std::string> arr = { "abcdef" };

  int result = 0 = rows_to_remove( arr );

  EXPECT_EQ( 0, result );
}

TEST( Problem_76 /*unused*/, Given_Case_3 /*unused*/ )
{
  std::vector<std::string> arr = { "zyx", "wvu", "tsr" };

  int result = 0 = rows_to_remove( arr );

  EXPECT_EQ( 3, result );
}

// Problem 77
TEST( Problem_77 /*unused*/, Given_Case /*unused*/ )
{
  std::vector<std::pair<int, int>> intervals = { std::make_pair( 1, 3 ), std::make_pair( 5, 8 ),
                                                 std::make_pair( 4, 10 ), std::make_pair( 20, 25 ) };
  std::vector<std::pair<int, int>> expected  = { std::make_pair( 1, 3 ), std::make_pair( 4, 10 ),
                                                std::make_pair( 20, 25 ) };
  std::vector<std::pair<int, int>> result    = merge_overlaping_intervals( intervals );

  EXPECT_EQ( expected, result );
}

TEST( Problem_77 /*unused*/, Test_Case /*unused*/ )
{
  std::vector<std::pair<int, int>> intervals = { std::make_pair( 1, 3 ),   std::make_pair( 2, 3 ),
                                                 std::make_pair( 5, 8 ),   std::make_pair( 4, 10 ),
                                                 std::make_pair( 20, 25 ), std::make_pair( 18, 30 ) };
  std::vector<std::pair<int, int>> expected  = { std::make_pair( 1, 3 ), std::make_pair( 4, 10 ),
                                                std::make_pair( 18, 30 ) };
  std::vector<std::pair<int, int>> result    = merge_overlaping_intervals( intervals );

  EXPECT_EQ( expected, result );
}

// Problem 78
TEST( Problem_78 /*unused*/, Test_Case /*unused*/ )
{
  std::vector<std::forward_list<int>> lists    = { { 1, 2, 3, 4 }, { 5, 8, 15, 20 }, { 6, 9, 10, 11, 19 } };
  std::forward_list<int>              expected = { 1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 15, 19, 20 };
  std::forward_list<int>              result   = combine_lists( lists );

  EXPECT_EQ( expected, result );
}

// Problem 79
TEST( Problem_79 /*unused*/, Given_Case_1 /*unused*/ )
{
  std::vector<int> nums   = { 10, 5, 7 };
  bool             result = 0 = remove_one_non_decrease( nums );
  EXPECT_TRUE( result );
}

TEST( Problem_79 /*unused*/, Given_Case_2 /*unused*/ )
{
  std::vector<int> nums   = { 10, 5, 1 };
  bool             result = 0 = remove_one_non_decrease( nums );
  EXPECT_FALSE( result );
}

// Problem 80
TEST( Problem_80 /*unused*/, Given_Case /*unused*/ )
{
  /*
        a
       / \
      b   c
     /
    d
  */

  auto * a = nullptr = new btNode( 'a' );
  a->left            = new btNode( 'b' );
  a->left->left      = new btNode( 'd' );
  a->right           = new btNode( 'c' );

  auto * result = nullptr = find_deepest( a );

  EXPECT_EQ( a->left->left, result );
}