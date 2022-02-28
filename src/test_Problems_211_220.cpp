#include "gtest/gtest.h"

#include "problems_211_220/Problem_211.hpp"
#include "problems_211_220/Problem_212.hpp"
#include "problems_211_220/Problem_213.hpp"
#include "problems_211_220/Problem_214.hpp"
#include "problems_211_220/Problem_215.hpp"
#include "problems_211_220/Problem_216.hpp"
#include "problems_211_220/Problem_217.hpp"
#include "problems_211_220/Problem_218.hpp"
#include "problems_211_220/Problem_219.hpp"
#include "problems_211_220/Problem_220.hpp"


// Problem 211
TEST( Problem_211, Given_Case )
{
  // given the string "abracadabra" and the pattern "abr", you should return [0, 7]
  std::vector<int> indecies = indexOf( "abracadabra", "abr" );
  std::vector<int> expected = { 0, 7 };

  EXPECT_EQ( indecies, expected );
}

// Problem 212
TEST( Problem_212, Given_Case )
{
  // given 1, return "A". Given 27, return "AA"
  std::string col1 = colLetter( 1 );
  std::string col2 = colLetter( 27 );

  EXPECT_EQ( col1, "A" );
  EXPECT_EQ( col2, "AA" );
}

TEST( Problem_212, Test_Case )
{
  std::string col1 = colLetter( 2 );
  std::string col2 = colLetter( 25 );
  std::string col3 = colLetter( 26 );
  std::string col4 = colLetter( 52 );
  std::string col5 = colLetter( 53 );

  EXPECT_EQ( col1, "B" );
  EXPECT_EQ( col2, "Y" );
  EXPECT_EQ( col3, "Z" );
  EXPECT_EQ( col4, "ZZ" );
  EXPECT_EQ( col5, "AAA" );
}

// Problem 213
TEST( Problem_213, Given_Case )
{
  // given "2542540123", you should return ['254.25.40.123', '254.254.0.123']
  std::vector<std::string> ips      = generateIpAddresses( "2542540123" );
  std::vector<std::string> expected = { "254.25.40.123", "254.254.0.123" };

  EXPECT_EQ( ips, expected );
}

// Problem 214
TEST( Problem_214, Given_Case )
{
  //  given 156, you should return 3
  int length = longestOneRun( 156 );

  EXPECT_EQ( length, 3 );
}

// Problem 215
TEST( Problem_215, Given_Case )
{
  /*
             5
          /     \
        3         7
      /  \      /   \
    1     4    6     9
   /                /
  0                8

  [0, 1, 3, 6, 8, 9]
  */

  auto * root = new btNode( 5, new btNode( 3, new btNode( 1, new btNode( 0 ) ), new btNode( 4 ) ),
                            new btNode( 7, new btNode( 6 ), new btNode( 9, new btNode( 8 ) ) ) );

  std::vector<int> result   = bottomView( root );
  std::vector<int> expected = { 0, 1, 3, 4, 8, 9 };
  EXPECT_EQ( result, expected );
}

// Problem 216
TEST( Problem_216, Given_Case )
{
  int result = romanToInt( "XIV" );
  EXPECT_EQ( result, 14 );
}

// Problem 217
TEST( Problem_217, Given_Case )
{
  int result1 = nextSparse( 21 );
  int result2 = nextSparse( 22 );

  EXPECT_EQ( result1, 21 );
  EXPECT_EQ( result2, 32 );
}

// Problem 218
TEST( Problem_218, Given_Case )
{
  auto * result   = new slNode<char>( { 'a', 'b', 'c' } );
  auto * expected = new slNode<char>( { 'c', 'b', 'a' } );
  result          = reverse( result );

  EXPECT_EQ( *result, *expected );
}

// Problem 219


// Problem 220
TEST( Problem_220, Given_Case )
{
  int result = max_profit_coin_game( { 10, 24, 5, 9 } );

  EXPECT_EQ( result, 33 );
}