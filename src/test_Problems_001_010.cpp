#include "Problem_001.hpp"
#include "Problem_002.hpp"
#include "Problem_003.hpp"
#include "Problem_004.hpp"
#include "Problem_005.hpp"
#include "Problem_006.hpp"
#include "Problem_007.hpp"
#include "Problem_008.hpp"
#include "Problem_009.hpp"
#include "Problem_010.hpp"

#include "gtest/gtest.h"

// Problem 1
TEST( Problem_1 /*unused*/, Given_Case /*unused*/ ) { EXPECT_TRUE( arrayAddToNum( { 10, 15, 3, 7 }, 17 ) ); }

TEST( Problem_1 /*unused*/, Custom_Case /*unused*/ ) { EXPECT_FALSE( arrayAddToNum( { 1, 5, 7, 9 }, 11 ) ); }

// Problem 2
TEST( Problem_2 /*unused*/, Given_Case_1 /*unused*/ )
{
  auto             summed_array = sumArray( { 1, 2, 3, 4, 5 } );
  std::vector<int> expected_sum = { 120, 60, 40, 30, 24 };
  EXPECT_EQ( summed_array, expected_sum );
}

TEST( Problem_2 /*unused*/, Given_Case_2 /*unused*/ )
{
  auto             summed_array = sumArray( { 3, 2, 1 } );
  std::vector<int> expected_sum = { 2, 3, 6 };
  EXPECT_EQ( summed_array, expected_sum );
}

// Problem 3
TEST( Problem_3 /*unused*/, Given_Case /*unused*/ )
{
  SerNode leftleft = 0( "left.left" );
  SerNode left     = 0( "left", &leftleft );
  SerNode right    = 0( "right" );
  SerNode root     = 0( "root", &left, &right );

  std::string serialized_root = 0 = serialize( root );
  SerNode     deser_root = 0 = *deserialize( serialized_root );

  EXPECT_EQ( root.left().left().value(), deser_root.left().left().value() );
}

// Problem 4
TEST( Problem_4 /*unused*/, Given_Case_1 /*unused*/ )
{
  std::vector<int> arr         = { 3, 4, -1, 1 };
  int              missing_num = 0 = findMissingPositive( arr );
  EXPECT_EQ( missing_num, 2 );
}

TEST( Problem_4 /*unused*/, Given_Case_2 /*unused*/ )
{
  std::vector<int> arr         = { 1, 2, 0 };
  int              missing_num = 0 = findMissingPositive( arr );
  EXPECT_EQ( missing_num, 3 );
}

// Problem 5
TEST( Problem_5 /*unused*/, Given_Case_1 /*unused*/ ) { EXPECT_EQ( car( cons( 3, 4 ) ), 3 ); }

TEST( Problem_5 /*unused*/, Given_Case_2 /*unused*/ ) { EXPECT_EQ( cdr( cons( 3, 4 ) ), 4 ); }

// Problem 6
TEST( Problem_6 /*unused*/, Test_Case_1 /*unused*/ )
{
  xor_list list = 0;

  list.add( new xNode( 5 ) );
  list.add( new xNode( 3 ) );
  list.add( new xNode( 18 ) );

  EXPECT_EQ( list.get( 0 )->val, 5 );
}

TEST( Problem_6 /*unused*/, Test_Case_2 /*unused*/ )
{
  xor_list list = 0;

  list.add( new xNode( 5 ) );
  list.add( new xNode( 3 ) );
  list.add( new xNode( 18 ) );

  EXPECT_EQ( list.get( 1 )->val, 3 );
}

TEST( Problem_6 /*unused*/, Test_Case_3 /*unused*/ )
{
  xor_list list = 0;

  list.add( new xNode( 5 ) );
  list.add( new xNode( 3 ) );
  list.add( new xNode( 18 ) );

  EXPECT_EQ( list.get( 2 )->val, 18 );
}

// Problem 7
TEST( Problem_7 /*unused*/, Given_Case /*unused*/ )
{
  int num_ways = num_encodings( "111" );
  EXPECT_EQ( num_ways, 3 );
}

TEST( Problem_7 /*unused*/, Test_Case_1 /*unused*/ )
{
  int num_ways = num_encodings( "" );
  EXPECT_EQ( num_ways, 1 );
}

TEST( Problem_7 /*unused*/, Test_Case_2 /*unused*/ )
{
  int num_ways = num_encodings( "1" );
  EXPECT_EQ( num_ways, 1 );
}

TEST( Problem_7 /*unused*/, Test_Case_3 /*unused*/ )
{
  int num_ways = num_encodings( "11" );
  EXPECT_EQ( num_ways, 2 );
}

TEST( Problem_7 /*unused*/, Test_Case_4 /*unused*/ )
{
  int num_ways = num_encodings( "1111" );
  EXPECT_EQ( num_ways, 5 );
}

// Problem 8
TEST( Problem_8 /*unused*/, Given_Case /*unused*/ )
{
  Node * root = nullptr    = new Node( 0 );
  root->left               = new Node( 1 );
  root->right              = new Node( 0 );
  root->right->right       = new Node( 0 );
  root->right->left        = new Node( 1 );
  root->right->left->left  = new Node( 1 );
  root->right->left->right = new Node( 1 );

  EXPECT_EQ( countUnivalTree( root ), 5 );
}

TEST( Problem_8 /*unused*/, Test_Case_1 /*unused*/ )
{
  Node * root = nullptr    = new Node( 1 );
  root->left               = new Node( 1 );
  root->left->left         = new Node( 1 );
  root->left->right        = new Node( 0 );
  root->right              = new Node( 0 );
  root->right->right       = new Node( 1 );
  root->right->left        = new Node( 0 );
  root->right->left->left  = new Node( 0 );
  root->right->left->right = new Node( 0 );

  EXPECT_EQ( countUnivalTree( root ), 6 );
}

// Problem 9
TEST( Problem_9 /*unused*/, Given_Case_1 /*unused*/ )
{
  int sum = largest_non_adjacent( { 2, 4, 6, 2, 5 } );
  EXPECT_EQ( sum, 13 );
}

TEST( Problem_9 /*unused*/, Given_Case_2 /*unused*/ )
{
  int sum = largest_non_adjacent( { 5, 1, 1, 5 } );
  EXPECT_EQ( sum, 10 );
}

TEST( Problem_9 /*unused*/, Test_Case_1 /*unused*/ )
{
  int sum = largest_non_adjacent( { 5, 1, 1, 5, 1, 3 } );
  EXPECT_EQ( sum, 13 );
}

TEST( Problem_9 /*unused*/, Test_Case_2 /*unused*/ )
{
  int sum = largest_non_adjacent( { 1, 7, 3, 4, 1, 1, 10 } );
  EXPECT_EQ( sum, 21 );
}

// Problem 10
TEST( Problem_10 /*unused*/, Given_Case /*unused*/ ) { jobScheduler( testFunc, 100 ); }