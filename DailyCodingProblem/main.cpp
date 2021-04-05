#include <vector>

#include "FUtils.h"
#include "Problem_1.h"
#include "Problem_10.h"
#include "Problem_11.h"
#include "Problem_12.h"
#include "Problem_13.h"
#include "Problem_14.h"
#include "Problem_15.h"
#include "Problem_16.h"
#include "Problem_17.h"
#include "Problem_18.h"
#include "Problem_19.h"
#include "Problem_2.h"
#include "Problem_20.h"
#include "Problem_21.h"
#include "Problem_3.h"
#include "Problem_4.h"
#include "Problem_5.h"
#include "Problem_6.h"
#include "Problem_7.h"
#include "Problem_8.h"
#include "Problem_9.h"

#include "gtest/gtest.h"

// FUtils
TEST( FUtils, split )
{
  std::string              str            = "This is a test string";
  std::vector<std::string> expected_split = { "This", "is", "a", "test", "string" };
  auto                     split_str      = split( str );

  EXPECT_EQ( split_str, expected_split );

  str            = "Hi Jake\nHow are you?\n- Luke";
  expected_split = { "Hi Jake", "How are you?", "- Luke" };
  split_str      = split( str, '\n' );

  EXPECT_EQ( split_str, expected_split );
}

TEST( FUtils, getIntVecMax )
{
  std::vector<int> vec          = { 1, 5, 3, 7, 5, 9 };
  int              expected_max = 9;
  int              max_val      = getIntVecMax( vec );

  EXPECT_EQ( max_val, expected_max );

  vec          = { -5, -2, -8 };
  expected_max = -2;
  max_val      = getIntVecMax( vec );

  EXPECT_EQ( max_val, expected_max );
}

TEST( FUtils, getIntVecMin )
{
  std::vector<int> vec          = { 1, 5, 3, 7, 5, 9 };
  int              expected_min = 1;
  int              min_val      = getIntVecMin( vec );

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

TEST( FUtils, intVecToStr )
{
  std::vector<int> vec          = { 1, 2, 3, 4, 5 };
  std::string      expected_str = "1 2 3 4 5 ";
  std::string      str          = intVecToStr( vec );

  EXPECT_EQ( str, expected_str );

  vec          = { -5, 7, -47, 204, 0 };
  expected_str = "-5 7 -47 204 0 ";
  str          = intVecToStr( vec );

  EXPECT_EQ( str, expected_str );
}

TEST( FUtils, slNode )
{
  slNode * root    = new slNode( 10 );
  slNode * node    = new slNode( 3 );
  slNode * node2   = new slNode( 8 );
  root->next       = node;
  root->next->next = node2;

  EXPECT_EQ( root->value, 10 );
  EXPECT_EQ( root->next->value, 3 );
  EXPECT_EQ( root->next->next->value, 8 );
}

TEST( FUtils, slList )
{
  slList   list;
  slNode * node  = new slNode( 3 );
  slNode * node2 = new slNode( 8 );

  list.add( node );
  list.add( node2 );

  EXPECT_EQ( list.head, node );
  EXPECT_EQ( list.tail, node2 );

  EXPECT_EQ( list.get( 0 ), node );
  EXPECT_EQ( list.get( 0 )->value, node->value );

  EXPECT_EQ( list.get( 1 ), node2 );
  EXPECT_EQ( list.get( 1 )->value, node2->value );
}

// Problem 1
TEST( Problem_1, Given_Case )
{
  EXPECT_TRUE( arrayAddToNum( { 10, 15, 3, 7 }, 17 ) );
}

TEST( Problem_1, Custom_Case )
{
  EXPECT_FALSE( arrayAddToNum( { 1, 5, 7, 9 }, 11 ) );
}

// Problem 2
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

// Problem 3
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

// Problem 4
TEST( Problem_4, Given_Case_1 )
{
  int arr[]       = { 3, 4, -1, 1 };
  int missing_num = findMissingPositive( arr, 4 );
  EXPECT_EQ( missing_num, 2 );
}

TEST( Problem_4, Given_Case_2 )
{
  int arr[]       = { 1, 2, 0 };
  int missing_num = findMissingPositive( arr, 3 );
  EXPECT_EQ( missing_num, 3 );
}

// Problem 5
TEST( Problem_5, Given_Case_1 )
{
  EXPECT_EQ( car( cons( 3, 4 ) ), 3 );
}

TEST( Problem_5, Given_Case_2 )
{
  EXPECT_EQ( cdr( cons( 3, 4 ) ), 4 );
}

// Problem 6
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

// Problem 7
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

// Problem 8
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

// Problem 9
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

// Problem 10
TEST( Problem_10, Given_Case )
{
  jobScheduler( testFunc, 100 );
}

// Problem 11
TEST( Problem_11, Given_Case )
{
  auto                     returned_strs   = autocomplete( "de", { "dog", "deer", "deal" } );
  std::vector<std::string> expected_return = { "deer", "deal" };
  EXPECT_EQ( returned_strs, expected_return );
}

// Problem 12
TEST( Problem_12, Given_Case )
{
  EXPECT_EQ( countWays( 4 ), 5 );
}

TEST( Problem_12, Test_Case_1 )
{
  EXPECT_EQ( countWays( 1 ), 1 );
}

TEST( Problem_12, Test_Case_2 )
{
  EXPECT_EQ( countWays( 2 ), 2 );
}

TEST( Problem_12, Test_Case_3 )
{
  EXPECT_EQ( countWays( 3 ), 3 );
}

// Problem 13
TEST( Problem_13, Given_Case )
{
  auto longest = longest_substring_with_k_distinct_characters( "abcba", 2 );
  EXPECT_EQ( longest, 3 );
}

TEST( Problem_13, Test_Case_1 )
{
  auto longest = longest_substring_with_k_distinct_characters( "banana", 2 );
  EXPECT_EQ( longest, 5 );
}

TEST( Problem_13, Test_Case_2 )
{
  auto longest = longest_substring_with_k_distinct_characters( "banana", 3 );
  EXPECT_EQ( longest, 6 );
}

// Problem 14
TEST( Problem_14, Given_Case )
{
  std::cout << "At 10 iterations PI is estimated as: " << monteCarloPi( 10 ) << '\n';
  std::cout << "At 100 iterations PI is estimated as: " << monteCarloPi( 100 ) << '\n';
  std::cout << "At 1000 iterations PI is estimated as: " << monteCarloPi( 1000 ) << '\n';
  std::cout << "At 1000000 iterations PI is estimated as: " << monteCarloPi( 1000000 ) << '\n';
}

// Problem 15
TEST( Problem_15, Test_Case_1 )
{
  std::vector<int> elements = { 10, 15, 12, 67, 21, 43 };
  auto             elem     = randElement( elements );
  bool             inVec    = false;

  for( unsigned int i = 0; i < elements.size(); ++i )
  {
    if( elements[i] == elem ) { inVec = true; }
  }

  EXPECT_TRUE( inVec );
}

TEST( Problem_15, Test_Case_2 )
{
  std::vector<int> elements = { 10, 15, 12, 67, 21, 43 };
  auto             elem     = randElement( elements );
  bool             inVec    = false;

  for( unsigned int i = 0; i < elements.size(); ++i )
  {
    if( elements[i] == elem ) { inVec = true; }
  }

  EXPECT_TRUE( inVec );
}

// Problem 16
TEST( Problem_16, Test_Case_1 )
{
  Store store;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 1 ), 11237 );
}

TEST( Problem_16, Test_Case_2 )
{
  Store store;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 2 ), 11236 );
}

TEST( Problem_16, Test_Case_3 )
{
  Store store;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 3 ), 11235 );
}

TEST( Problem_16, Test_Case_4 )
{
  Store store;

  store.record( 11234 );
  store.record( 11235 );
  store.record( 11236 );
  store.record( 11237 );

  EXPECT_EQ( store.get_last( 4 ), 11234 );
}

// Problem 17
TEST( Problem_17, Given_Case )
{
  FAIL();
}

// Problem 18
TEST( Problem_18, Given_Case )
{
  std::vector<int> arr      = { 10, 5, 2, 7, 8, 7 };
  auto             max_vals = compSubArrMax( arr, 3 );
  std::vector<int> expected = { 10, 7, 8, 8 };

  EXPECT_EQ( max_vals, expected );
}

// Problem 19
TEST( Problem_19, Test_Case_1 )
{
  std::vector<std::vector<int>> vec = {
      { 10, 15, 20 },
      { 14, 47, 6 },
      { 2, 7, 10 } };
  auto cost = build_houses( vec );

  EXPECT_EQ( cost, 18 );
}

TEST( Problem_19, Test_Case_2 )
{
  std::vector<std::vector<int>> vec = {
      { 10, 15, 20 },
      { 6, 47, 14 },
      { 2, 7, 10 } };
  auto cost = build_houses( vec );

  EXPECT_EQ( cost, 26 );
}

// Problem 20
TEST( Problem_20, Test_Case_1 )
{
  //A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10
  slNode * A   = new slNode( 3 );
  slNode * A_1 = new slNode( 7 );
  slNode * B   = new slNode( 99 );
  slNode * B_1 = new slNode( 1 );
  slNode * C   = new slNode( 8 );
  slNode * D   = new slNode( 10 );

  A->next   = A_1;
  A_1->next = C;
  B->next   = B_1;
  B_1->next = C;
  C->next   = D;

  slNode * intersect = findNodeIntersect( A, B );

  EXPECT_EQ( intersect, C );
}

TEST( Problem_20, Test_Case_2 )
{
  //A = 3 -> 7 -> 16 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10
  slNode * A   = new slNode( 3 );
  slNode * A_1 = new slNode( 7 );
  slNode * A_2 = new slNode( 16 );
  slNode * B   = new slNode( 99 );
  slNode * B_1 = new slNode( 1 );
  slNode * C   = new slNode( 8 );
  slNode * D   = new slNode( 10 );

  A->next   = A_1;
  A_1->next = A_2;
  A_2->next = C;
  B->next   = B_1;
  B_1->next = C;
  C->next   = D;

  slNode * intersect = findNodeIntersect( A, B );

  EXPECT_EQ( intersect, C );
}

TEST( Problem_21, Given_Case )
{
  std::vector<std::pair<int, int>> schedule    = { std::make_pair( 30, 75 ), std::make_pair( 0, 50 ), std::make_pair( 60, 150 ) };
  int                              roomsNeeded = findMinRoomsNeeded( schedule );

  EXPECT_EQ( roomsNeeded, 2 );
}

TEST( Problem_21, Test_Case )
{
  std::vector<std::pair<int, int>> schedule    = { std::make_pair( 0, 75 ), std::make_pair( 25, 100 ), std::make_pair( 80, 100 ), std::make_pair( 50, 75 ) };
  int                              roomsNeeded = findMinRoomsNeeded( schedule );

  EXPECT_EQ( roomsNeeded, 3 );
}