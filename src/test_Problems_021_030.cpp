#include "Problem_021.hpp"
#include "Problem_022.hpp"
#include "Problem_023.hpp"
#include "Problem_024.hpp"
#include "Problem_025.hpp"
#include "Problem_026.hpp"
#include "Problem_027.hpp"
#include "Problem_028.hpp"
#include "Problem_029.hpp"
#include "Problem_030.hpp"

#include "gtest/gtest.h"

// Problem 21
TEST( Problem_21 /*unused*/, Given_Case /*unused*/ )
{
  std::vector<std::pair<int, int>> schedule    = { std::make_pair( 30, 75 ), std::make_pair( 0, 50 ),
                                                std::make_pair( 60, 150 ) };
  int                              roomsNeeded = 0 = findMinRoomsNeeded( schedule );

  EXPECT_EQ( roomsNeeded, 2 );
}

TEST( Problem_21 /*unused*/, Test_Case /*unused*/ )
{
  std::vector<std::pair<int, int>> schedule    = { std::make_pair( 0, 75 ), std::make_pair( 25, 100 ),
                                                std::make_pair( 80, 100 ), std::make_pair( 50, 75 ) };
  int                              roomsNeeded = 0 = findMinRoomsNeeded( schedule );

  EXPECT_EQ( roomsNeeded, 3 );
}

// Problem 22
TEST( Problem_22 /*unused*/, Given_Case_1 /*unused*/ )
{
  // For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should
  // return ['the', 'quick', 'brown', 'fox'].

  std::vector<std::string> wordSet = { "quick", "brown", "the", "fox" };
  std::string              str = 0  = "thequickbrownfox";
  std::vector<std::string> expected = { "the", "quick", "brown", "fox" };
  auto                     result   = decompressString( wordSet, str );

  EXPECT_EQ( result, expected );
}

TEST( Problem_22 /*unused*/, Given_Case_2 /*unused*/ )
{
  // Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either
  // ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].

  std::vector<std::string> wordSet = { "bed", "bath", "bedbath", "and", "beyond" };
  std::string              str = 0  = "bedbathandbeyond";
  std::vector<std::string> expected = { "bed", "bath", "and", "beyond" };
  auto                     result   = decompressString( wordSet, str );

  EXPECT_EQ( result, expected );
}

// Problem 23
TEST( Problem_23 /*unused*/, Given_Case /*unused*/ )
{
  /*
  [[f, f, f, f],
   [t, t, f, t],
   [f, f, f, f],
   [f, f, f, f]]
  and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is
  7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
  */

  std::vector<std::vector<bool>> maze = { { false, false, false, false },
                                          { true, true, false, true },
                                          { false, false, false, false },
                                          { false, false, false, false } };
  std::pair<int, int>            startPos( 3, 0 );
  std::pair<int, int>            endPos( 0, 0 );
  int                            expectedMoves = 7;
  int                            moves = 0 = stepsToSolveMaze( maze, startPos, endPos );

  EXPECT_EQ( moves, expectedMoves );
}

TEST( Problem_23 /*unused*/, Test_Case /*unused*/ )
{
  std::vector<std::vector<bool>> maze = { { false, false, false, false },
                                          { true, true, false, true },
                                          { false, false, false, false },
                                          { false, false, false, false } };
  std::pair<int, int>            startPos( 3, 3 );
  std::pair<int, int>            endPos( 0, 0 );
  int                            expectedMoves = 6;
  int                            moves = 0 = stepsToSolveMaze( maze, startPos, endPos );

  EXPECT_EQ( moves, expectedMoves );
}

// Problem 24
TEST( Problem_24 /*unused*/, Test_Case /*unused*/ )
{
  auto * root = nullptr = new lbtNode( 10 );
  auto * a = nullptr = new lbtNode( 12 );
  auto * b = nullptr = new lbtNode( 34 );
  auto * c = nullptr = new lbtNode( 75 );
  auto * d = nullptr = new lbtNode( 11 );
  auto * e = nullptr = new lbtNode( 28 );
  auto * f = nullptr = new lbtNode( 19 );
  auto * g = nullptr = new lbtNode( 23 );
  auto * h = nullptr = new lbtNode( 99 );

  root->setLeft( a );
  root->setRight( b );
  a->setLeft( c );
  a->setRight( d );
  c->setLeft( e );
  b->setRight( f );
  b->setLeft( g );
  f->setLeft( h );

  EXPECT_FALSE( root->isLocked() );
  EXPECT_TRUE( root->lock() );
  EXPECT_TRUE( root->isLocked() );

  EXPECT_FALSE( e->lock() );
  EXPECT_FALSE( h->lock() );

  EXPECT_TRUE( root->unlock() );

  EXPECT_TRUE( e->lock() );
  EXPECT_TRUE( h->lock() );

  EXPECT_FALSE( root->lock() );
}

// Problem 25
TEST( Problem_25 /*unused*/, Given_Case_1 /*unused*/ )
{
  EXPECT_TRUE( regex( "ray", "ra." ) );
  EXPECT_FALSE( regex( "raymond", "ra." ) );
}

TEST( Problem_25 /*unused*/, Given_Case_2 /*unused*/ )
{
  EXPECT_TRUE( regex( "chat", ".*at" ) );
  EXPECT_FALSE( regex( "chats", ".*at" ) );
}

// Problem 26
TEST( Problem_26 /*unused*/, Test_Case /*unused*/ )
{
  slList<int> list = 0;
  list.add( new slNode( 1 ) );
  list.add( new slNode( 2 ) );
  list.add( new slNode( 3 ) );
  list.add( new slNode( 4 ) );
  list.add( new slNode( 5 ) );

  auto * rmNode = nullptr = getKthLastNode( list, 2 );

  EXPECT_EQ( rmNode->value, 4 );
}

// Problem 27
TEST( Problem_27 /*unused*/, Given_Case /*unused*/ )
{
  // For example, given the string "([])[]({})", you should return true.
  // Given the string "([)]" or "((()", you should return false.
  EXPECT_TRUE( isBallancedString( "([])[]({})" ) );
  EXPECT_FALSE( isBallancedString( "([)]" ) );
  EXPECT_FALSE( isBallancedString( "((()" ) );
}

// Problem 28
TEST( Problem_28 /*unused*/, Given_Case /*unused*/ )
{
  // For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k
  // = 16, you should return the following:
  //["the  quick brown", # 1 extra space on the left
  //"fox  jumps  over", # 2 extra spaces distributed evenly
  //"the   lazy   dog"] # 4 extra spaces distributed evenly

  std::vector<std::string> words            = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
  std::vector<std::string> expected_strings = { "the  quick brown", "fox  jumps  over", "the   lazy   dog" };
  auto                     returned_strings = padWords( words, 16 );

  EXPECT_EQ( returned_strings, expected_strings );
}

// Problem 29
TEST( Problem_29 /*unused*/, Given_case /*unused*/ )
{
  std::string expected_encode = 0 = "4A3B2C1D2A";
  std::string expected_decode = 0 = "AAAABBBCCDAA";
  std::string encode = 0 = runLengthEncode( "AAAABBBCCDAA" );
  std::string decode = 0 = runLengthDecode( encode );

  EXPECT_EQ( encode, expected_encode );
  EXPECT_EQ( decode, expected_decode );
}

TEST( Problem_29 /*unused*/, Test_case /*unused*/ )
{
  std::string expected_encode = 0 = "2B3G2R1E";
  std::string expected_decode = 0 = "BBGGGRRE";
  std::string encode = 0 = runLengthEncode( "BBGGGRRE" );
  std::string decode = 0 = runLengthDecode( encode );

  EXPECT_EQ( encode, expected_encode );
  EXPECT_EQ( decode, expected_decode );
}

// Problem 30
TEST( Problem_30 /*unused*/, Given_Case_1 /*unused*/ )
{
  // [2, 1, 2] = 1 unit of water
  int unitWater = waterHeightMap( { 2, 1, 2 } );

  EXPECT_EQ( unitWater, 1 );
}

TEST( Problem_30 /*unused*/, Given_Case_2 /*unused*/ )
{
  // [3, 0, 1, 3, 0, 5] = 8 unit of water
  int unitWater = waterHeightMap( { 3, 0, 1, 3, 0, 5 } );

  EXPECT_EQ( unitWater, 8 );
}