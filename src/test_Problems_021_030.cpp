#include "gtest/gtest.h"

#include "problems_021_030/Problem_021.hpp"
#include "problems_021_030/Problem_022.hpp"
#include "problems_021_030/Problem_023.hpp"
#include "problems_021_030/Problem_024.hpp"
#include "problems_021_030/Problem_025.hpp"
#include "problems_021_030/Problem_026.hpp"
#include "problems_021_030/Problem_027.hpp"
#include "problems_021_030/Problem_028.hpp"
#include "problems_021_030/Problem_029.hpp"
#include "problems_021_030/Problem_030.hpp"

// Problem 021
TEST( Problem_21, Given_Case ) {
  std::vector<std::pair<int, int>> const schedule    = { std::make_pair( 30, 75 ), std::make_pair( 0, 50 ),
                                                         std::make_pair( 60, 150 ) };
  int const                              roomsNeeded = findMinRoomsNeeded( schedule );

  EXPECT_EQ( roomsNeeded, 2 );
}

TEST( Problem_21, Test_Case ) {
  std::vector<std::pair<int, int>> const schedule    = { std::make_pair( 0, 75 ), std::make_pair( 25, 100 ),
                                                         std::make_pair( 80, 100 ), std::make_pair( 50, 75 ) };
  int const                              roomsNeeded = findMinRoomsNeeded( schedule );

  EXPECT_EQ( roomsNeeded, 3 );
}

// Problem 022
TEST( Problem_22, Given_Case_1 ) {
  // For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should
  // return ['the', 'quick', 'brown', 'fox'].

  std::vector<std::string> const wordSet  = { "quick", "brown", "the", "fox" };
  std::string const              str      = "thequickbrownfox";
  std::vector<std::string> const expected = { "the", "quick", "brown", "fox" };
  auto                           result   = decompressString( wordSet, str );

  EXPECT_EQ( result, expected );
}

TEST( Problem_22, Given_Case_2 ) {
  // Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either
  // ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].

  std::vector<std::string> const wordSet  = { "bed", "bath", "bedbath", "and", "beyond" };
  std::string const              str      = "bedbathandbeyond";
  std::vector<std::string> const expected = { "bed", "bath", "and", "beyond" };
  auto                           result   = decompressString( wordSet, str );

  EXPECT_EQ( result, expected );
}

// Problem 023
TEST( Problem_23, Given_Case ) {
  /*
  [[f, f, f, f],
   [t, t, f, t],
   [f, f, f, f],
   [f, f, f, f]]
  and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is
  7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
  */

  std::vector<std::vector<bool>> const maze = {
    {false, false, false, false},
    { true,  true, false,  true},
    {false, false, false, false},
    {false, false, false, false}
  };
  std::pair<int, int> const startPos( 3, 0 );
  std::pair<int, int> const endPos( 0, 0 );
  int const                 expectedMoves = 7;
  int const                 moves         = stepsToSolveMaze( maze, startPos, endPos );

  EXPECT_EQ( moves, expectedMoves );
}

TEST( Problem_23, Test_Case ) {
  std::vector<std::vector<bool>> const maze = {
    {false, false, false, false},
    { true,  true, false,  true},
    {false, false, false, false},
    {false, false, false, false}
  };
  std::pair<int, int> const startPos( 3, 3 );
  std::pair<int, int> const endPos( 0, 0 );
  int const                 expectedMoves = 6;
  int const                 moves         = stepsToSolveMaze( maze, startPos, endPos );

  EXPECT_EQ( moves, expectedMoves );
}

// Problem 024
TEST( Problem_24, Test_Case ) {
  auto *root = new lbtNode( 10 );
  auto *a    = new lbtNode( 12 );
  auto *b    = new lbtNode( 34 );
  auto *c    = new lbtNode( 75 );
  auto *d    = new lbtNode( 11 );
  auto *e    = new lbtNode( 28 );
  auto *f    = new lbtNode( 19 );
  auto *g    = new lbtNode( 23 );
  auto *h    = new lbtNode( 99 );

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

// Problem 025
TEST( Problem_25, Given_Case_1 ) {
  EXPECT_TRUE( regex( "ray", "ra." ) );
  EXPECT_FALSE( regex( "raymond", "ra." ) );
}

TEST( Problem_25, Given_Case_2 ) {
  EXPECT_TRUE( regex( "chat", ".*at" ) );
  EXPECT_FALSE( regex( "chats", ".*at" ) );
}

// Problem 026
TEST( Problem_26, Test_Case ) {
  slList<int> list;
  list.add( new slNode( 1 ) );
  list.add( new slNode( 2 ) );
  list.add( new slNode( 3 ) );
  list.add( new slNode( 4 ) );
  list.add( new slNode( 5 ) );

  auto *rmNode = getKthLastNode( list, 2 );

  EXPECT_EQ( rmNode->value, 4 );
}

// Problem 027
TEST( Problem_27, Given_Case ) {
  // For example, given the string "([])[]({})", you should return true.
  // Given the string "([)]" or "((()", you should return false.
  EXPECT_TRUE( isBallancedString( "([])[]({})" ) );
  EXPECT_FALSE( isBallancedString( "([)]" ) );
  EXPECT_FALSE( isBallancedString( "((()" ) );
}

// Problem 028
TEST( Problem_28, Given_Case ) {
  // For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k
  // = 16, you should return the following:
  //["the  quick brown", # 1 extra space on the left
  //"fox  jumps  over", # 2 extra spaces distributed evenly
  //"the   lazy   dog"] # 4 extra spaces distributed evenly

  std::vector<std::string> const words            = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
  std::vector<std::string> const expected_strings = { "the  quick brown", "fox  jumps  over", "the   lazy   dog" };
  auto                           returned_strings = padWords( words, 16 );

  EXPECT_EQ( returned_strings, expected_strings );
}

// Problem 029
TEST( Problem_29, Given_case ) {
  std::string const expected_encode = "4A3B2C1D2A";
  std::string const expected_decode = "AAAABBBCCDAA";
  std::string const encode          = runLengthEncode( "AAAABBBCCDAA" );
  std::string const decode          = runLengthDecode( encode );

  EXPECT_EQ( encode, expected_encode );
  EXPECT_EQ( decode, expected_decode );
}

TEST( Problem_29, Test_case ) {
  std::string const expected_encode = "2B3G2R1E";
  std::string const expected_decode = "BBGGGRRE";
  std::string const encode          = runLengthEncode( "BBGGGRRE" );
  std::string const decode          = runLengthDecode( encode );

  EXPECT_EQ( encode, expected_encode );
  EXPECT_EQ( decode, expected_decode );
}

// Problem 030
TEST( Problem_30, Given_Case_1 ) {
  // [2, 1, 2] = 1 unit of water
  int const unitWater = waterHeightMap( { 2, 1, 2 } );

  EXPECT_EQ( unitWater, 1 );
}

TEST( Problem_30, Given_Case_2 ) {
  // [3, 0, 1, 3, 0, 5] = 8 unit of water
  int const unitWater = waterHeightMap( { 3, 0, 1, 3, 0, 5 } );

  EXPECT_EQ( unitWater, 8 );
}