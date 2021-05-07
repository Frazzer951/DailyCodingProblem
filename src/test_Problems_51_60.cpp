#include "Problem_51.hpp"
#include "Problem_52.hpp"
#include "Problem_53.hpp"

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