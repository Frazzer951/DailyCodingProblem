#include "gtest/gtest.h"

#include "problems_011_020/Problem_011.hpp"
#include "problems_011_020/Problem_012.hpp"
#include "problems_011_020/Problem_013.hpp"
#include "problems_011_020/Problem_014.hpp"
#include "problems_011_020/Problem_015.hpp"
#include "problems_011_020/Problem_016.hpp"
#include "problems_011_020/Problem_017.hpp"
#include "problems_011_020/Problem_018.hpp"
#include "problems_011_020/Problem_019.hpp"
#include "problems_011_020/Problem_020.hpp"

// Problem 11
TEST( Problem_11, Given_Case )
{
  auto                     returned_strs   = autocomplete( "de", { "dog", "deer", "deal" } );
  std::vector<std::string> expected_return = { "deer", "deal" };
  EXPECT_EQ( returned_strs, expected_return );
}

// Problem 12
TEST( Problem_12, Given_Case ) { EXPECT_EQ( countWays( 4 ), 5 ); }

TEST( Problem_12, Test_Case_1 ) { EXPECT_EQ( countWays( 1 ), 1 ); }

TEST( Problem_12, Test_Case_2 ) { EXPECT_EQ( countWays( 2 ), 2 ); }

TEST( Problem_12, Test_Case_3 ) { EXPECT_EQ( countWays( 3 ), 3 ); }

// Problem 13
TEST( Problem_13, Given_Case )
{
  auto longest = longest_substring_with_k_distinct_characters( "abcba", 2 );
  EXPECT_EQ( longest, 3 );
}

TEST( Problem_13, Test_Case_1 )
{
  auto longest = longest_substring_with_k_distinct_characters( "banana", 2 );
  EXPECT_EQ( longest, 5 );
}

TEST( Problem_13, Test_Case_2 )
{
  auto longest = longest_substring_with_k_distinct_characters( "banana", 3 );
  EXPECT_EQ( longest, 6 );
}

// Problem 14
TEST( Problem_14, Given_Case )
{
  std::cout << "At 10 iterations PI is estimated as: " << monteCarloPi( 10 ) << '\n';
  std::cout << "At 100 iterations PI is estimated as: " << monteCarloPi( 100 ) << '\n';
  std::cout << "At 1000 iterations PI is estimated as: " << monteCarloPi( 1000 ) << '\n';
  std::cout << "At 1000000 iterations PI is estimated as: " << monteCarloPi( 1000000 ) << '\n';
}

// Problem 15
TEST( Problem_15, Test_Case_1 )
{
  std::vector<int> elements = { 10, 15, 12, 67, 21, 43 };
  auto             elem     = randElement( elements );
  bool             inVec    = false;

  for( int element : elements )
  {
    if( element == elem ) { inVec = true; }
  }

  EXPECT_TRUE( inVec );
}

TEST( Problem_15, Test_Case_2 )
{
  std::vector<int> elements = { 10, 15, 12, 67, 21, 43 };
  auto             elem     = randElement( elements );
  bool             inVec    = false;

  for( int element : elements )
  {
    if( element == elem ) { inVec = true; }
  }

  EXPECT_TRUE( inVec );
}

// Problem 16
TEST( Problem_16, Test_Case_1 )
{
  Store store;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 1 ), 11237 );
}

TEST( Problem_16, Test_Case_2 )
{
  Store store;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 2 ), 11236 );
}

TEST( Problem_16, Test_Case_3 )
{
  Store store;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 3 ), 11235 );
}

TEST( Problem_16, Test_Case_4 )
{
  Store store;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 4 ), 11234 );
}

// Problem 17


// Problem 18
TEST( Problem_18, Given_Case )
{
  std::vector<int> arr      = { 10, 5, 2, 7, 8, 7 };
  auto             max_vals = compSubArrMax( arr, 3 );
  std::vector<int> expected = { 10, 7, 8, 8 };

  EXPECT_EQ( max_vals, expected );
}

// Problem 19
TEST( Problem_19, Test_Case_1 )
{
  std::vector<std::vector<int>> vec  = { { 10, 15, 20 }, { 14, 47, 6 }, { 2, 7, 10 } };
  auto                          cost = build_houses( vec );

  EXPECT_EQ( cost, 18 );
}

TEST( Problem_19, Test_Case_2 )
{
  std::vector<std::vector<int>> vec  = { { 10, 15, 20 }, { 6, 47, 14 }, { 2, 7, 10 } };
  auto                          cost = build_houses( vec );

  EXPECT_EQ( cost, 26 );
}

// Problem 20
TEST( Problem_20, Test_Case_1 )
{
  // A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10
  auto * A   = new slNode( 3 );
  auto * A_1 = new slNode( 7 );
  auto * B   = new slNode( 99 );
  auto * B_1 = new slNode( 1 );
  auto * C   = new slNode( 8 );
  auto * D   = new slNode( 10 );

  A->next   = A_1;
  A_1->next = C;
  B->next   = B_1;
  B_1->next = C;
  C->next   = D;

  slNode<int> * intersect = findNodeIntersect( A, B );

  EXPECT_EQ( intersect, C );
}

TEST( Problem_20, Test_Case_2 )
{
  // A = 3 -> 7 -> 16 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10
  auto * A   = new slNode( 3 );
  auto * A_1 = new slNode( 7 );
  auto * A_2 = new slNode( 16 );
  auto * B   = new slNode( 99 );
  auto * B_1 = new slNode( 1 );
  auto * C   = new slNode( 8 );
  auto * D   = new slNode( 10 );

  A->next   = A_1;
  A_1->next = A_2;
  A_2->next = C;
  B->next   = B_1;
  B_1->next = C;
  C->next   = D;

  slNode<int> * intersect = findNodeIntersect( A, B );

  EXPECT_EQ( intersect, C );
}