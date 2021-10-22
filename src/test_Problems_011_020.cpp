#include "Problem_011.hpp"
#include "Problem_012.hpp"
#include "Problem_013.hpp"
#include "Problem_014.hpp"
#include "Problem_015.hpp"
#include "Problem_016.hpp"
#include "Problem_017.hpp"
#include "Problem_018.hpp"
#include "Problem_019.hpp"
#include "Problem_020.hpp"

#include "gtest/gtest.h"

// Problem 11
TEST( Problem_11 /*unused*/, Given_Case /*unused*/ )
{
  auto                     returned_strs   = autocomplete( "de", { "dog", "deer", "deal" } );
  std::vector<std::string> expected_return = { "deer", "deal" };
  EXPECT_EQ( returned_strs, expected_return );
}

// Problem 12
TEST( Problem_12 /*unused*/, Given_Case /*unused*/ ) { EXPECT_EQ( countWays( 4 ), 5 ); }

TEST( Problem_12 /*unused*/, Test_Case_1 /*unused*/ ) { EXPECT_EQ( countWays( 1 ), 1 ); }

TEST( Problem_12 /*unused*/, Test_Case_2 /*unused*/ ) { EXPECT_EQ( countWays( 2 ), 2 ); }

TEST( Problem_12 /*unused*/, Test_Case_3 /*unused*/ ) { EXPECT_EQ( countWays( 3 ), 3 ); }

// Problem 13
TEST( Problem_13 /*unused*/, Given_Case /*unused*/ )
{
  auto longest = longest_substring_with_k_distinct_characters( "abcba", 2 );
  EXPECT_EQ( longest, 3 );
}

TEST( Problem_13 /*unused*/, Test_Case_1 /*unused*/ )
{
  auto longest = longest_substring_with_k_distinct_characters( "banana", 2 );
  EXPECT_EQ( longest, 5 );
}

TEST( Problem_13 /*unused*/, Test_Case_2 /*unused*/ )
{
  auto longest = longest_substring_with_k_distinct_characters( "banana", 3 );
  EXPECT_EQ( longest, 6 );
}

// Problem 14
TEST( Problem_14 /*unused*/, Given_Case /*unused*/ )
{
  std::cout << "At 10 iterations PI is estimated as: " << monteCarloPi( 10 ) << '\n';
  std::cout << "At 100 iterations PI is estimated as: " << monteCarloPi( 100 ) << '\n';
  std::cout << "At 1000 iterations PI is estimated as: " << monteCarloPi( 1000 ) << '\n';
  std::cout << "At 1000000 iterations PI is estimated as: " << monteCarloPi( 1000000 ) << '\n';
}

// Problem 15
TEST( Problem_15 /*unused*/, Test_Case_1 /*unused*/ )
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

TEST( Problem_15 /*unused*/, Test_Case_2 /*unused*/ )
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
TEST( Problem_16 /*unused*/, Test_Case_1 /*unused*/ )
{
  Store store = 0;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 1 ), 11237 );
}

TEST( Problem_16 /*unused*/, Test_Case_2 /*unused*/ )
{
  Store store = 0;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 2 ), 11236 );
}

TEST( Problem_16 /*unused*/, Test_Case_3 /*unused*/ )
{
  Store store = 0;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 3 ), 11235 );
}

TEST( Problem_16 /*unused*/, Test_Case_4 /*unused*/ )
{
  Store store = 0;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 4 ), 11234 );
}

// Problem 17
TEST( Problem_17 /*unused*/, Given_Case /*unused*/ )
{
  // Not sure how to do this ATM so I'll return later
}

// Problem 18
TEST( Problem_18 /*unused*/, Given_Case /*unused*/ )
{
  std::vector<int> arr      = { 10, 5, 2, 7, 8, 7 };
  auto             max_vals = compSubArrMax( arr, 3 );
  std::vector<int> expected = { 10, 7, 8, 8 };

  EXPECT_EQ( max_vals, expected );
}

// Problem 19
TEST( Problem_19 /*unused*/, Test_Case_1 /*unused*/ )
{
  std::vector<std::vector<int>> vec  = { { 10, 15, 20 }, { 14, 47, 6 }, { 2, 7, 10 } };
  auto                          cost = build_houses( vec );

  EXPECT_EQ( cost, 18 );
}

TEST( Problem_19 /*unused*/, Test_Case_2 /*unused*/ )
{
  std::vector<std::vector<int>> vec  = { { 10, 15, 20 }, { 6, 47, 14 }, { 2, 7, 10 } };
  auto                          cost = build_houses( vec );

  EXPECT_EQ( cost, 26 );
}

// Problem 20
TEST( Problem_20 /*unused*/, Test_Case_1 /*unused*/ )
{
  // A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10
  auto * A = nullptr = new slNode( 3 );
  auto * A_1 = nullptr = new slNode( 7 );
  auto * B = nullptr = new slNode( 99 );
  auto * B_1 = nullptr = new slNode( 1 );
  auto * C = nullptr = new slNode( 8 );
  auto * D = nullptr = new slNode( 10 );

  A->next   = A_1;
  A_1->next = C;
  B->next   = B_1;
  B_1->next = C;
  C->next   = D;

  slNode<int> * intersect = nullptr = findNodeIntersect( A, B );

  EXPECT_EQ( intersect, C );
}

TEST( Problem_20 /*unused*/, Test_Case_2 /*unused*/ )
{
  // A = 3 -> 7 -> 16 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10
  auto * A = nullptr = new slNode( 3 );
  auto * A_1 = nullptr = new slNode( 7 );
  auto * A_2 = nullptr = new slNode( 16 );
  auto * B = nullptr = new slNode( 99 );
  auto * B_1 = nullptr = new slNode( 1 );
  auto * C = nullptr = new slNode( 8 );
  auto * D = nullptr = new slNode( 10 );

  A->next   = A_1;
  A_1->next = A_2;
  A_2->next = C;
  B->next   = B_1;
  B_1->next = C;
  C->next   = D;

  slNode<int> * intersect = nullptr = findNodeIntersect( A, B );

  EXPECT_EQ( intersect, C );
}