#include "Problem_131.hpp"
#include "Problem_132.hpp"
#include "Problem_133.hpp"
#include "Problem_134.hpp"
#include "Problem_135.hpp"

#include "gtest/gtest.h"


// Problem 132
TEST( Problem_132, record )
{
  hitcounter h;

  ASSERT_NO_FATAL_FAILURE( h.record( timestamp( 10, 15, 6 ) ) );
  ASSERT_NO_FATAL_FAILURE( h.record( timestamp( 12, 10, 1 ) ) );
  ASSERT_NO_FATAL_FAILURE( h.record( timestamp( 4, 2, 59 ) ) );
}

class HitCounterTest : public ::testing::Test
{
protected:
  void SetUp() override
  {
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

TEST_F( HitCounterTest, range )
{
  auto                   timestamps = h.range( timestamp( 5, 0, 0 ), timestamp( 19, 0, 0 ) );
  std::vector<timestamp> expected   = { timestamp( 5, 5, 15 ), timestamp( 10, 15, 6 ), timestamp( 12, 10, 1 ),
                                      timestamp( 18, 54, 30 ) };

  EXPECT_EQ( timestamps, expected );
}

// Problem 133
TEST( Problem_133, Given_Case )
{
  /*
     10
    /  \
   5    30
       /  \
     22    35
  */
  auto * root        = new pbtNode( 10, nullptr );
  root->left         = new pbtNode( 5, root );
  root->right        = new pbtNode( 30, root );
  root->right->left  = new pbtNode( 22, root->right );
  root->right->right = new pbtNode( 35, root->right );

  EXPECT_EQ( nextElement( root->right->left ), 30 );
  EXPECT_EQ( nextElement( root->left ), 10 );
  EXPECT_EQ( nextElement( root ), 22 );
}

// Problem 133
TEST( Problem_133, Test_Class )
{
  int         arr[] = { 0, 0, 0, 18, 0, 0, 0, 1, 0, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 4, 9 };
  int         size  = sizeof( arr ) / sizeof( int );
  SparseArray sArr;
  ASSERT_NO_FATAL_FAILURE( sArr.init( arr, size ) );

  for( int i = 0; i < size; i++ ) { EXPECT_EQ( sArr.get( i ), arr[i] ); }

  ASSERT_NO_FATAL_FAILURE( sArr.set( 2, 1000 ) );
  EXPECT_EQ( sArr.get( 2 ), 1000 );
}