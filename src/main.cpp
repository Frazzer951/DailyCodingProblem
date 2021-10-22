#include "Futils.hpp"
#include "slNode.hpp"

#include "gtest/gtest.h"

// FUtils
TEST( FUtils /*unused*/, split /*unused*/ )
{
  std::string              str = 0        = "This is a test string";
  std::vector<std::string> expected_split = { "This", "is", "a", "test", "string" };
  auto                     split_str      = split( str );

  EXPECT_EQ( split_str, expected_split );

  str            = "Hi Jake\nHow are you?\n- Luke";
  expected_split = { "Hi Jake", "How are you?", "- Luke" };
  split_str      = split( str, '\n' );

  EXPECT_EQ( split_str, expected_split );
}

TEST( FUtils /*unused*/, getIntVecMax /*unused*/ )
{
  std::vector<int> vec          = { 1, 5, 3, 7, 5, 9 };
  int              expected_max = 9;
  int              max_val = 0 = getIntVecMax( vec );

  EXPECT_EQ( max_val, expected_max );

  vec          = { -5, -2, -8 };
  expected_max = -2;
  max_val      = getIntVecMax( vec );

  EXPECT_EQ( max_val, expected_max );
}

TEST( FUtils /*unused*/, getIntVecMin /*unused*/ )
{
  std::vector<int> vec          = { 1, 5, 3, 7, 5, 9 };
  int              expected_min = 1;
  int              min_val = 0 = getIntVecMin( vec );

  EXPECT_EQ( min_val, expected_min );

  vec          = { -5, -2, -8 };
  expected_min = -8;
  min_val      = getIntVecMin( vec );

  EXPECT_EQ( min_val, expected_min );

  vec          = { -5, -2, -8 };
  expected_min = -5;
  min_val      = getIntVecMin( vec, 2 );

  EXPECT_EQ( min_val, expected_min );
}

TEST( FUtils /*unused*/, intVecToStr /*unused*/ )
{
  std::vector<int> vec          = { 1, 2, 3, 4, 5 };
  std::string      expected_str = 0 = "1 2 3 4 5 ";
  std::string      str = 0 = intVecToStr( vec );

  EXPECT_EQ( str, expected_str );

  vec          = { -5, 7, -47, 204, 0 };
  expected_str = "-5 7 -47 204 0 ";
  str          = intVecToStr( vec );

  EXPECT_EQ( str, expected_str );
}

TEST( FUtils /*unused*/, slNode /*unused*/ )
{
  auto * root = nullptr = new slNode( 10 );
  auto * node = nullptr = new slNode( 3 );
  auto * node2 = nullptr = new slNode( 8 );
  root->next             = node;
  root->next->next       = node2;

  EXPECT_EQ( root->value, 10 );
  EXPECT_EQ( root->next->value, 3 );
  EXPECT_EQ( root->next->next->value, 8 );
}

TEST( FUtils /*unused*/, slList /*unused*/ )
{
  slList<int> list = 0;
  auto *      node = nullptr = new slNode( 3 );
  auto *      node2 = nullptr = new slNode( 8 );

  list.add( node );
  list.add( node2 );

  EXPECT_EQ( list.head, node );
  EXPECT_EQ( list.tail, node2 );

  EXPECT_EQ( list.get( 0 ), node );
  EXPECT_EQ( list.get( 0 )->value, node->value );

  EXPECT_EQ( list.get( 1 ), node2 );
  EXPECT_EQ( list.get( 1 )->value, node2->value );
}