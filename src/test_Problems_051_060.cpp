#include "Problem_051.hpp"
#include "Problem_052.hpp"
#include "Problem_053.hpp"
#include "Problem_054.hpp"
#include "Problem_055.hpp"
#include "Problem_057.hpp"

#include "gtest/gtest.h"

// Problem 51
TEST( Problem_51, Test_Case )
{
  std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  auto shuffled = shuffle( arr );
}

// Problem 52
LRUCache cache( 5 );
TEST( Problem_52, set )
{
  EXPECT_NO_THROW( cache.set( "one", "1" ) );
  EXPECT_NO_THROW( cache.set( "two", "2" ) );
  EXPECT_NO_THROW( cache.set( "three", "3" ) );
  EXPECT_NO_THROW( cache.set( "four", "4" ) );
  EXPECT_NO_THROW( cache.set( "five", "5" ) );
  EXPECT_NO_THROW( cache.set( "six", "6" ) );
}

TEST( Problem_52, get )
{
  EXPECT_EQ( cache.get( "one" ), "" );
  EXPECT_EQ( cache.get( "two" ), "2" );
  EXPECT_EQ( cache.get( "three" ), "3" );
  EXPECT_EQ( cache.get( "four" ), "4" );
  EXPECT_EQ( cache.get( "five" ), "5" );
  EXPECT_EQ( cache.get( "six" ), "6" );
}

TEST( Problem_52, CacheSizeTest )
{
  cache.set( "seven", "7" );
  EXPECT_EQ( cache.get( "seven" ), "7" );
  EXPECT_EQ( cache.get( "two" ), "" );
}

// Problem 53
queue_s q;
TEST( Problem_53, enqueue )
{
  EXPECT_NO_THROW( q.enqueue( 1 ) );
  EXPECT_NO_THROW( q.enqueue( 2 ) );
  EXPECT_NO_THROW( q.enqueue( 3 ) );
  EXPECT_NO_THROW( q.enqueue( 4 ) );
  EXPECT_NO_THROW( q.enqueue( 5 ) );
}

TEST( Problem_53, dequeue )
{
  EXPECT_EQ( q.dequeue(), 1 );
  EXPECT_EQ( q.dequeue(), 2 );
  EXPECT_EQ( q.dequeue(), 3 );
  EXPECT_EQ( q.dequeue(), 4 );
  EXPECT_EQ( q.dequeue(), 5 );
  EXPECT_EQ( q.dequeue(), NULL );
}

// Problem 54
TEST( Problem_54, valid_sudoku_1 )
{
  std::vector<std::vector<int>> test_board = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

  EXPECT_TRUE( valid_sudoku( test_board ) );
}

TEST( Problem_54, valid_sudoku_2 )
{
  std::vector<std::vector<int>> test_board = { { 5, 3, 4, 6, 7, 8, 9, 1, 2 },
                                               { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
                                               { 1, 9, 8, 3, 4, 2, 5, 6, 7 },
                                               { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
                                               { 4, 2, 6, 8, 5, 3, 7, 9, 1 },
                                               { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
                                               { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
                                               { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
                                               { 3, 4, 5, 2, 8, 6, 1, 7, 9 } };

  EXPECT_TRUE( valid_sudoku( test_board ) );
}

TEST( Problem_54, invalid_sudoku_1 )
{
  std::vector<std::vector<int>> test_board = { { 1, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 1, 0, 0, 0, 0, 0, 0, 0, 0 } };

  EXPECT_FALSE( valid_sudoku( test_board ) );
}

TEST( Problem_54, invalid_sudoku_2 )
{
  std::vector<std::vector<int>> test_board = { { 2, 0, 0, 0, 0, 0, 0, 0, 2 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

  EXPECT_FALSE( valid_sudoku( test_board ) );
}

TEST( Problem_54, invalid_sudoku_3 )
{
  std::vector<std::vector<int>> test_board = { { 3, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 3, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

  EXPECT_FALSE( valid_sudoku( test_board ) );
}

TEST( Problem_54, test_case_1 )
{
  std::vector<std::vector<int>> test_board = { { 0, 0, 4, 6, 0, 8, 9, 1, 2 },
                                               { 0, 7, 2, 0, 0, 0, 3, 4, 8 },
                                               { 1, 0, 0, 3, 4, 2, 5, 0, 7 },
                                               { 0, 5, 9, 7, 0, 1, 4, 2, 0 },
                                               { 0, 2, 6, 0, 5, 0, 7, 9, 0 },
                                               { 0, 1, 3, 9, 0, 4, 8, 5, 0 },
                                               { 9, 0, 1, 5, 3, 7, 0, 0, 4 },
                                               { 2, 8, 7, 0, 0, 0, 6, 3, 0 },
                                               { 3, 4, 5, 2, 0, 6, 1, 0, 0 } };

  std::vector<std::vector<int>> expected_board = { { 5, 3, 4, 6, 7, 8, 9, 1, 2 },
                                                   { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
                                                   { 1, 9, 8, 3, 4, 2, 5, 6, 7 },
                                                   { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
                                                   { 4, 2, 6, 8, 5, 3, 7, 9, 1 },
                                                   { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
                                                   { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
                                                   { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
                                                   { 3, 4, 5, 2, 8, 6, 1, 7, 9 } };

  auto result_board = solveSudoku( test_board );

  EXPECT_EQ( result_board, expected_board );
}

// Problem 55
URLShortener urls;
TEST( Problem_55, shorten_restore )
{
  std::string url    = "www.google.com";
  std::string result = urls.restore( urls.shorten( url ) );

  EXPECT_EQ( result, url );
}

TEST( Problem_55, shorten_same_url )
{
  std::string url       = "www.frazzer.net";
  std::string shorten_1 = urls.shorten( url );
  std::string shorten_2 = urls.shorten( url );
  std::string restore_1 = urls.restore( shorten_1 );
  std::string restore_2 = urls.restore( shorten_2 );

  EXPECT_EQ( shorten_1, shorten_2 );
  EXPECT_EQ( url, restore_1 );
  EXPECT_EQ( url, restore_2 );
}

// Problem 57
TEST( Problem_57, Given_Case )
{
  // given the string "the quick brown fox jumps over the lazy dog" and k = 10,
  // you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"].

  auto                     result   = splitString( "the quick brown fox jumps over the lazy dog", 10 );
  std::vector<std::string> expected = { "the quick", "brown fox", "jumps over", "the lazy", "dog" };

  EXPECT_EQ( result, expected );
}