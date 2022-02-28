#include "gtest/gtest.h"

#include "problems_001_010/Problem_001.hpp"
#include "problems_001_010/Problem_002.hpp"
#include "problems_001_010/Problem_003.hpp"
#include "problems_001_010/Problem_004.hpp"
#include "problems_001_010/Problem_005.hpp"
#include "problems_001_010/Problem_006.hpp"
#include "problems_001_010/Problem_007.hpp"
#include "problems_001_010/Problem_008.hpp"
#include "problems_001_010/Problem_009.hpp"
#include "problems_001_010/Problem_010.hpp"


// Problem 001
TEST( Problem_1, Given_Case ) { EXPECT_TRUE( arrayAddToNum( { 10, 15, 3, 7 }, 17 ) ); }

TEST( Problem_1, Custom_Case ) { EXPECT_FALSE( arrayAddToNum( { 1, 5, 7, 9 }, 11 ) ); }

// Problem 002
TEST( Problem_2, Given_Case_1 )
{
  auto             summed_array = sumArray( { 1, 2, 3, 4, 5 } );
  std::vector<int> expected_sum = { 120, 60, 40, 30, 24 };
  EXPECT_EQ( summed_array, expected_sum );
}

TEST( Problem_2, Given_Case_2 )
{
  auto             summed_array = sumArray( { 3, 2, 1 } );
  std::vector<int> expected_sum = { 2, 3, 6 };
  EXPECT_EQ( summed_array, expected_sum );
}

// Problem 003
TEST( Problem_3, Given_Case )
{
  SerNode leftleft( "left.left" );
  SerNode left( "left", &leftleft );
  SerNode right( "right" );
  SerNode root( "root", &left, &right );

  std::string serialized_root = serialize( root );
  SerNode     deser_root      = *deserialize( serialized_root );

  EXPECT_EQ( root.left().left().value(), deser_root.left().left().value() );
}

// Problem 004
TEST( Problem_4, Given_Case_1 )
{
  std::vector<int> arr         = { 3, 4, -1, 1 };
  int              missing_num = findMissingPositive( arr );
  EXPECT_EQ( missing_num, 2 );
}

TEST( Problem_4, Given_Case_2 )
{
  std::vector<int> arr         = { 1, 2, 0 };
  int              missing_num = findMissingPositive( arr );
  EXPECT_EQ( missing_num, 3 );
}

// Problem 005
TEST( Problem_5, Given_Case_1 ) { EXPECT_EQ( car( cons( 3, 4 ) ), 3 ); }

TEST( Problem_5, Given_Case_2 ) { EXPECT_EQ( cdr( cons( 3, 4 ) ), 4 ); }

// Problem 006
TEST( Problem_6, Test_Case_1 )
{
  xor_list list;

  list.add( new xNode( 5 ) );
  list.add( new xNode( 3 ) );
  list.add( new xNode( 18 ) );

  EXPECT_EQ( list.get( 0 )->val, 5 );
}

TEST( Problem_6, Test_Case_2 )
{
  xor_list list;

  list.add( new xNode( 5 ) );
  list.add( new xNode( 3 ) );
  list.add( new xNode( 18 ) );

  EXPECT_EQ( list.get( 1 )->val, 3 );
}

TEST( Problem_6, Test_Case_3 )
{
  xor_list list;

  list.add( new xNode( 5 ) );
  list.add( new xNode( 3 ) );
  list.add( new xNode( 18 ) );

  EXPECT_EQ( list.get( 2 )->val, 18 );
}

// Problem 007
TEST( Problem_7, Given_Case )
{
  int num_ways = num_encodings( "111" );
  EXPECT_EQ( num_ways, 3 );
}

TEST( Problem_7, Test_Case_1 )
{
  int num_ways = num_encodings( "" );
  EXPECT_EQ( num_ways, 1 );
}

TEST( Problem_7, Test_Case_2 )
{
  int num_ways = num_encodings( "1" );
  EXPECT_EQ( num_ways, 1 );
}

TEST( Problem_7, Test_Case_3 )
{
  int num_ways = num_encodings( "11" );
  EXPECT_EQ( num_ways, 2 );
}

TEST( Problem_7, Test_Case_4 )
{
  int num_ways = num_encodings( "1111" );
  EXPECT_EQ( num_ways, 5 );
}


// Problem 008
TEST( Problem_8, Given_Case )
{
  Node * root              = new Node( 0 );
  root->left               = new Node( 1 );
  root->right              = new Node( 0 );
  root->right->right       = new Node( 0 );
  root->right->left        = new Node( 1 );
  root->right->left->left  = new Node( 1 );
  root->right->left->right = new Node( 1 );

  EXPECT_EQ( countUnivalTree( root ), 5 );
}

TEST( Problem_8, Test_Case_1 )
{
  Node * root              = new Node( 1 );
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

// Problem 009
TEST( Problem_9, Given_Case_1 )
{
  int sum = largest_non_adjacent( { 2, 4, 6, 2, 5 } );
  EXPECT_EQ( sum, 13 );
}

TEST( Problem_9, Given_Case_2 )
{
  int sum = largest_non_adjacent( { 5, 1, 1, 5 } );
  EXPECT_EQ( sum, 10 );
}

TEST( Problem_9, Test_Case_1 )
{
  int sum = largest_non_adjacent( { 5, 1, 1, 5, 1, 3 } );
  EXPECT_EQ( sum, 13 );
}

TEST( Problem_9, Test_Case_2 )
{
  int sum = largest_non_adjacent( { 1, 7, 3, 4, 1, 1, 10 } );
  EXPECT_EQ( sum, 21 );
}

// Problem 010
TEST( Problem_10, Given_Case ) { jobScheduler( testFunc, 100 ); }