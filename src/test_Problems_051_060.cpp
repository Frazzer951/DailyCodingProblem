#include "gtest/gtest.h"

#include "problems_051_060/Problem_051.hpp"
#include "problems_051_060/Problem_052.hpp"
#include "problems_051_060/Problem_053.hpp"
#include "problems_051_060/Problem_054.hpp"
#include "problems_051_060/Problem_055.hpp"
#include "problems_051_060/Problem_056.hpp"
#include "problems_051_060/Problem_057.hpp"
#include "problems_051_060/Problem_058.hpp"
#include "problems_051_060/Problem_059.hpp"
#include "problems_051_060/Problem_060.hpp"


// Problem 051
TEST( Problem_51, Test_Case )
{
  std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  auto shuffled = shuffle( arr );
}

// Problem 052
TEST( Problem_52, set_get )
{
  LRUCache LRU_cache( 5 );

  EXPECT_NO_THROW( LRU_cache.set( "one", "1" ) );
  EXPECT_NO_THROW( LRU_cache.set( "two", "2" ) );
  EXPECT_NO_THROW( LRU_cache.set( "three", "3" ) );
  EXPECT_NO_THROW( LRU_cache.set( "four", "4" ) );
  EXPECT_NO_THROW( LRU_cache.set( "five", "5" ) );
  EXPECT_NO_THROW( LRU_cache.set( "six", "6" ) );

  EXPECT_EQ( LRU_cache.get( "one" ), "" );
  EXPECT_EQ( LRU_cache.get( "two" ), "2" );
  EXPECT_EQ( LRU_cache.get( "three" ), "3" );
  EXPECT_EQ( LRU_cache.get( "four" ), "4" );
  EXPECT_EQ( LRU_cache.get( "five" ), "5" );
  EXPECT_EQ( LRU_cache.get( "six" ), "6" );
}

TEST( Problem_52, CacheSizeTest )
{
  LRUCache LRU_cache( 5 );

  EXPECT_NO_THROW( LRU_cache.set( "one", "1" ) );
  EXPECT_NO_THROW( LRU_cache.set( "two", "2" ) );
  EXPECT_NO_THROW( LRU_cache.set( "three", "3" ) );
  EXPECT_NO_THROW( LRU_cache.set( "four", "4" ) );
  EXPECT_NO_THROW( LRU_cache.set( "five", "5" ) );
  EXPECT_NO_THROW( LRU_cache.set( "six", "6" ) );

  EXPECT_EQ( LRU_cache.get( "one" ), "" );
  EXPECT_EQ( LRU_cache.get( "two" ), "2" );
  EXPECT_EQ( LRU_cache.get( "three" ), "3" );
  EXPECT_EQ( LRU_cache.get( "four" ), "4" );
  EXPECT_EQ( LRU_cache.get( "five" ), "5" );
  EXPECT_EQ( LRU_cache.get( "six" ), "6" );

  LRU_cache.set( "seven", "7" );
  EXPECT_EQ( LRU_cache.get( "seven" ), "7" );
  EXPECT_EQ( LRU_cache.get( "two" ), "" );
}

// Problem 053
TEST( Problem_53, enqueue_dequeue )
{
  queue_s q;

  EXPECT_NO_THROW( q.enqueue( 1 ) );
  EXPECT_NO_THROW( q.enqueue( 2 ) );
  EXPECT_NO_THROW( q.enqueue( 3 ) );
  EXPECT_NO_THROW( q.enqueue( 4 ) );
  EXPECT_NO_THROW( q.enqueue( 5 ) );

  EXPECT_EQ( q.dequeue(), 1 );
  EXPECT_EQ( q.dequeue(), 2 );
  EXPECT_EQ( q.dequeue(), 3 );
  EXPECT_EQ( q.dequeue(), 4 );
  EXPECT_EQ( q.dequeue(), 5 );
  EXPECT_THROW( q.dequeue(), std::out_of_range );
}


// Problem 054
TEST( Problem_54, valid_sudoku_1 )
{
  std::vector<std::vector<int>> test_board = { { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

  EXPECT_TRUE( valid_sudoku( test_board ) );
}

TEST( Problem_54, valid_sudoku_2 )
{
  std::vector<std::vector<int>> test_board = { { 5, 3, 4, 6, 7, 8, 9, 1, 2 }, { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
                                               { 1, 9, 8, 3, 4, 2, 5, 6, 7 }, { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
                                               { 4, 2, 6, 8, 5, 3, 7, 9, 1 }, { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
                                               { 9, 6, 1, 5, 3, 7, 2, 8, 4 }, { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
                                               { 3, 4, 5, 2, 8, 6, 1, 7, 9 } };

  EXPECT_TRUE( valid_sudoku( test_board ) );
}

TEST( Problem_54, invalid_sudoku_1 )
{
  std::vector<std::vector<int>> test_board = { { 1, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 1, 0, 0, 0, 0, 0, 0, 0, 0 } };

  EXPECT_FALSE( valid_sudoku( test_board ) );
}

TEST( Problem_54, invalid_sudoku_2 )
{
  std::vector<std::vector<int>> test_board = { { 2, 0, 0, 0, 0, 0, 0, 0, 2 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

  EXPECT_FALSE( valid_sudoku( test_board ) );
}

TEST( Problem_54, invalid_sudoku_3 )
{
  std::vector<std::vector<int>> test_board = { { 3, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 3, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                                               { 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

  EXPECT_FALSE( valid_sudoku( test_board ) );
}

TEST( Problem_54, test_case_1 )
{
  std::vector<std::vector<int>> test_board = { { 0, 0, 4, 6, 0, 8, 9, 1, 2 }, { 0, 7, 2, 0, 0, 0, 3, 4, 8 },
                                               { 1, 0, 0, 3, 4, 2, 5, 0, 7 }, { 0, 5, 9, 7, 0, 1, 4, 2, 0 },
                                               { 0, 2, 6, 0, 5, 0, 7, 9, 0 }, { 0, 1, 3, 9, 0, 4, 8, 5, 0 },
                                               { 9, 0, 1, 5, 3, 7, 0, 0, 4 }, { 2, 8, 7, 0, 0, 0, 6, 3, 0 },
                                               { 3, 4, 5, 2, 0, 6, 1, 0, 0 } };

  std::vector<std::vector<int>> expected_board = { { 5, 3, 4, 6, 7, 8, 9, 1, 2 }, { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
                                                   { 1, 9, 8, 3, 4, 2, 5, 6, 7 }, { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
                                                   { 4, 2, 6, 8, 5, 3, 7, 9, 1 }, { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
                                                   { 9, 6, 1, 5, 3, 7, 2, 8, 4 }, { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
                                                   { 3, 4, 5, 2, 8, 6, 1, 7, 9 } };

  auto result_board = solveSudoku( test_board );

  EXPECT_EQ( result_board, expected_board );
}

// Problem 055
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

// Problem 056


// Problem 057
TEST( Problem_57, Given_Case )
{
  // given the string "the quick brown fox jumps over the lazy dog" and k = 10,
  // you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"].

  auto                     result   = splitString( "the quick brown fox jumps over the lazy dog", 10 );
  std::vector<std::string> expected = { "the quick", "brown fox", "jumps over", "the lazy", "dog" };

  EXPECT_EQ( result, expected );
}

// Problem 058
TEST( Problem_58, Given_Case )
{
  // Given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4

  int result = shifted_array_search( { 13, 18, 25, 2, 8, 10 }, 8 );

  EXPECT_EQ( 4, result );
}

// Problem 059


// Problem 060
TEST( Problem_60, Given_Case_1 )
{
  // For example, given the multiset {15, 5, 20, 10, 35, 15, 10},
  // it would return true, since we can split it up into
  // {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

  bool result = partitions( { 15, 5, 20, 10, 35, 15, 10 } );

  EXPECT_TRUE( result );
}

TEST( Problem_60, Given_Case_2 )
{
  // Given the multiset {15, 5, 20, 10, 35}, it would return false,
  // since we can't split it up into two subsets that add up to the same sum.

  bool result = partitions( { 15, 5, 20, 10, 35 } );

  EXPECT_FALSE( result );
}