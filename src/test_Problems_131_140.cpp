#include "gtest/gtest.h"

#include "problems_131_140/Problem_131.hpp"
#include "problems_131_140/Problem_132.hpp"
#include "problems_131_140/Problem_133.hpp"
#include "problems_131_140/Problem_134.hpp"
#include "problems_131_140/Problem_135.hpp"
#include "problems_131_140/Problem_136.hpp"
#include "problems_131_140/Problem_137.hpp"
#include "problems_131_140/Problem_138.hpp"
#include "problems_131_140/Problem_139.hpp"
#include "problems_131_140/Problem_140.hpp"

// Problem 131

// Problem 132
TEST( Problem_132, record ) {
  hitcounter h;

  ASSERT_NO_FATAL_FAILURE( h.record( timestamp( 10, 15, 6 ) ) );
  ASSERT_NO_FATAL_FAILURE( h.record( timestamp( 12, 10, 1 ) ) );
  ASSERT_NO_FATAL_FAILURE( h.record( timestamp( 4, 2, 59 ) ) );
}

class HitCounterTest : public ::testing::Test {
protected:
  void SetUp() override {
    h.record( timestamp( 1, 16, 0 ) );
    h.record( timestamp( 4, 2, 59 ) );
    h.record( timestamp( 5, 5, 15 ) );
    h.record( timestamp( 10, 15, 6 ) );
    h.record( timestamp( 12, 10, 1 ) );
    h.record( timestamp( 18, 54, 30 ) );
    h.record( timestamp( 20, 13, 2 ) );
  }

  hitcounter h;
};

TEST_F( HitCounterTest, total ) { EXPECT_EQ( h.total(), 7 ); }

TEST_F( HitCounterTest, range ) {
  auto                   timestamps = h.range( timestamp( 5, 0, 0 ), timestamp( 19, 0, 0 ) );
  std::vector<timestamp> expected   = { timestamp( 5, 5, 15 ), timestamp( 10, 15, 6 ), timestamp( 12, 10, 1 ),
                                        timestamp( 18, 54, 30 ) };

  EXPECT_EQ( timestamps, expected );
}

// Problem 133
TEST( Problem_133, Given_Case ) {
  /*
     10
    /  \
   5    30
       /  \
     22    35
  */
  auto *root         = new pbtNode( 10, nullptr );
  root->left         = new pbtNode( 5, root );
  root->right        = new pbtNode( 30, root );
  root->right->left  = new pbtNode( 22, root->right );
  root->right->right = new pbtNode( 35, root->right );

  EXPECT_EQ( nextElement( root->right->left ), 30 );
  EXPECT_EQ( nextElement( root->left ), 10 );
  EXPECT_EQ( nextElement( root ), 22 );
}

// Problem 134
TEST( Problem_134, Test_Class ) {
  int         arr[] = { 0, 0, 0, 18, 0, 0, 0, 1, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 4, 9 };
  int         size  = sizeof( arr ) / sizeof( int );
  SparseArray sArr;
  ASSERT_NO_FATAL_FAILURE( sArr.init( arr, size ) );

  for ( int i = 0; i < size; i++ ) { EXPECT_EQ( sArr.get( i ), arr[i] ); }

  ASSERT_NO_FATAL_FAILURE( sArr.set( 2, 1000 ) );
  EXPECT_EQ( sArr.get( 2 ), 1000 );
}

// Problem 135
TEST( Problem_135, Given_Case ) {
  /*
    10
   /  \
  5    5
   \     \
     2    1
         /
       -1
  */
  auto *root         = new btNode( 10, new btNode( 5 ), new btNode( 5 ) );
  root->left->right  = new btNode( 2 );
  root->right->right = new btNode( 1, new btNode( -1 ) );

  int result = minPathSum( root );

  EXPECT_EQ( result, 15 );
}

// Problem 136
TEST( Problem_136, Given_Case ) {
  /*
  For example, given the following matrix:

  [[1, 0, 0, 0],
   [1, 0, 1, 1],
   [1, 0, 1, 1],
   [0, 1, 0, 0]]
  Return 4.
  */

  std::vector<std::vector<int>> v = {
    {1, 0, 0, 0},
    {1, 0, 1, 1},
    {1, 0, 1, 1},
    {0, 1, 0, 0}
  };
  int result = largestRectangle( v );

  EXPECT_EQ( result, 4 );
}

// Problem 137
TEST( Problem_137, BitArray ) {
  bitarray arr( 10 );
  bool     a[10] = { 1, 1, 1, 0, 0, 1, 1, 0, 0, 1 };
  for ( int i = 0; i < 10; i++ ) { EXPECT_FALSE( arr.get( i ) ); }
  for ( int i = 0; i < 10; i++ ) { ASSERT_NO_FATAL_FAILURE( arr.set( i, a[i] ) ); }
  for ( int i = 0; i < 10; i++ ) { EXPECT_EQ( arr.get( i ), a[i] ); }
}

// Problem 138
TEST( Problem_138, Given_Case ) {
  int result = minimum_coins( 16 );
  EXPECT_EQ( result, 3 );
}

// Problem 139

// Problem 140
TEST( Problem_140, Given_Case ) {
  // given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8
  std::vector<int>    arr = { 2, 4, 6, 8, 10, 2, 6, 10 };
  std::pair<int, int> expected( 4, 8 );
  std::pair<int, int> result = array_two_elements( arr );

  EXPECT_EQ( result, expected );
}