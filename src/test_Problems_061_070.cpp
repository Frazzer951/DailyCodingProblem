#include "gtest/gtest.h"

#include "problems_061_070/Problem_061.hpp"
#include "problems_061_070/Problem_062.hpp"
#include "problems_061_070/Problem_063.hpp"
#include "problems_061_070/Problem_064.hpp"
#include "problems_061_070/Problem_065.hpp"
#include "problems_061_070/Problem_066.hpp"
#include "problems_061_070/Problem_067.hpp"
#include "problems_061_070/Problem_068.hpp"
#include "problems_061_070/Problem_069.hpp"
#include "problems_061_070/Problem_070.hpp"

// Problem 061
TEST( Problem_61, Given_Case ) {
  double const result = p61::pow( 2, 10 );

  EXPECT_DOUBLE_EQ( 1024, result );
}

TEST( Problem_61, Test_Case ) {
  double const result = p61::pow( 5, -5 );

  EXPECT_DOUBLE_EQ( 0.00032, result );
}

// Problem 062
TEST( Problem_62, Given_Case_1 ) {
  int const result = num_ways( 2, 2 );

  EXPECT_EQ( 2, result );
}

TEST( Problem_62, Given_Case_2 ) {
  int const result = num_ways( 5, 5 );

  EXPECT_EQ( 70, result );
}

TEST( Problem_62, Test_Case ) {
  int const result = num_ways( 2, 8 );

  EXPECT_EQ( 8, result );
}

// Problem 063
TEST( Problem_63, Given_Case_1 ) {
  std::vector<std::vector<char>> const letters = {
    {'F', 'A', 'C', 'I'},
    {'O', 'B', 'Q', 'P'},
    {'A', 'N', 'O', 'B'},
    {'M', 'A', 'S', 'S'}
  };

  bool const result = findWord( letters, "FOAM" );

  EXPECT_TRUE( result );
}

TEST( Problem_63, Given_Case_2 ) {
  std::vector<std::vector<char>> const letters = {
    {'F', 'A', 'C', 'I'},
    {'O', 'B', 'Q', 'P'},
    {'A', 'N', 'O', 'B'},
    {'M', 'A', 'S', 'S'}
  };

  bool const result = findWord( letters, "MASS" );

  EXPECT_TRUE( result );
}

TEST( Problem_63, Test_Case_1 ) {
  std::vector<std::vector<char>> const letters = {
    {'F', 'A', 'C', 'I'},
    {'O', 'B', 'Q', 'P'},
    {'A', 'N', 'O', 'B'},
    {'M', 'A', 'S', 'S'}
  };

  bool const result = findWord( letters, "ZOOM" );

  EXPECT_FALSE( result );
}

TEST( Problem_63, Test_Case_2 ) {
  std::vector<std::vector<char>> const letters = {
    {'F', 'A', 'C', 'I'},
    {'O', 'B', 'Q', 'P'},
    {'A', 'N', 'O', 'B'},
    {'M', 'A', 'S', 'S'}
  };

  bool const result = findWord( letters, "LAUGH" );

  EXPECT_FALSE( result );
}

// Problem 064
TEST( Problem_64, Test_Case_1 ) {
  int const result = knights_tours( 1 );

  EXPECT_EQ( 1, result );
}

// Problem 065
TEST( Problem_65, Given_Case ) {
  std::vector<std::vector<int>> const v = {
    { 1,  2,  3,  4,  5},
    { 6,  7,  8,  9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20}
  };

  std::vector<int> const expected = { 1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12 };

  auto result = print_spiral( v );

  EXPECT_EQ( expected, result );
}

// Problem 066
TEST( Problem_66, Test_Case ) {
  int heads = 0;
  int tails = 0;

  for ( int i = 0; i < 10000; i++ ) {
    bool const flip = toss_fair();
    if ( flip )
      heads++;
    else
      tails++;
  }

  int const difference = heads - tails;
  std::cout << "The difference is " << difference << ".\n";
  EXPECT_TRUE( ( difference >= -500 ) && ( difference <= 500 ) );
}

// Problem 067
LFUCache LFU_cache( 5 );
TEST( Problem_67, Set ) {
  LFU_cache.set( "1", 1 );
  LFU_cache.set( "2", 2 );
  LFU_cache.set( "3", 3 );
  LFU_cache.set( "4", 4 );
  LFU_cache.set( "5", 5 );

  EXPECT_EQ( 1, LFU_cache.get( "1" ) );
  EXPECT_EQ( 2, LFU_cache.get( "2" ) );
  EXPECT_EQ( 3, LFU_cache.get( "3" ) );
  EXPECT_EQ( 4, LFU_cache.get( "4" ) );
  EXPECT_EQ( 5, LFU_cache.get( "5" ) );
}

// Problem 068
TEST( Problem_68, Given_Case ) {
  std::vector<std::pair<int, int>> const bishops = { std::make_pair( 0, 0 ), std::make_pair( 1, 2 ), std::make_pair( 2, 2 ),
                                                     std::make_pair( 4, 0 ) };

  int const result = pairs( bishops, 5 );

  EXPECT_EQ( 2, result );
}

// Problem 069
TEST( Problem_69, Given_Case ) {
  int const result = largest_product_x3( { -10, -10, 5, 2 } );

  EXPECT_EQ( 500, result );
}

TEST( Problem_69, Test_Case ) {
  int const result = largest_product_x3( { -18, 3, 9, 4, -1, 10, 7 } );

  EXPECT_EQ( 630, result );
}

// Problem 070
TEST( Problem_70, Given_Case_1 ) {
  int const result = perfecet_num( 1 );

  EXPECT_EQ( 19, result );
}

TEST( Problem_70, Given_Case_2 ) {
  int const result = perfecet_num( 2 );

  EXPECT_EQ( 28, result );
}

TEST( Problem_70, Test_Case ) {
  int const result = perfecet_num( 10 );

  EXPECT_EQ( 109, result );
}