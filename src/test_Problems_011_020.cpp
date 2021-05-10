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

  for( unsigned int i = 0; i < elements.size(); ++i )
  {
    if( elements[i] == elem ) { inVec = true; }
  }

  EXPECT_TRUE( inVec );
}

TEST( Problem_15, Test_Case_2 )
{
  std::vector<int> elements = { 10, 15, 12, 67, 21, 43 };
  auto             elem     = randElement( elements );
  bool             inVec    = false;

  for( unsigned int i = 0; i < elements.size(); ++i )
  {
    if( elements[i] == elem ) { inVec = true; }
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
// TEST( Problem_17, Given_Case ) { FAIL(); }

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
  slNode * A   = new slNode( 3 );
  slNode * A_1 = new slNode( 7 );
  slNode * B   = new slNode( 99 );
  slNode * B_1 = new slNode( 1 );
  slNode * C   = new slNode( 8 );
  slNode * D   = new slNode( 10 );

  A->next   = A_1;
  A_1->next = C;
  B->next   = B_1;
  B_1->next = C;
  C->next   = D;

  slNode * intersect = findNodeIntersect( A, B );

  EXPECT_EQ( intersect, C );
}

TEST( Problem_20, Test_Case_2 )
{
  // A = 3 -> 7 -> 16 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10
  slNode * A   = new slNode( 3 );
  slNode * A_1 = new slNode( 7 );
  slNode * A_2 = new slNode( 16 );
  slNode * B   = new slNode( 99 );
  slNode * B_1 = new slNode( 1 );
  slNode * C   = new slNode( 8 );
  slNode * D   = new slNode( 10 );

  A->next   = A_1;
  A_1->next = A_2;
  A_2->next = C;
  B->next   = B_1;
  B_1->next = C;
  C->next   = D;

  slNode * intersect = findNodeIntersect( A, B );

  EXPECT_EQ( intersect, C );
}