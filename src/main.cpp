#include "main.hpp"

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
TEST( Problem_1, Given_Case ) { EXPECT_TRUE( arrayAddToNum( { 10, 15, 3, 7 }, 17 ) ); }

TEST( Problem_1, Custom_Case ) { EXPECT_FALSE( arrayAddToNum( { 1, 5, 7, 9 }, 11 ) ); }

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
TEST( Problem_5, Given_Case_1 ) { EXPECT_EQ( car( cons( 3, 4 ) ), 3 ); }

TEST( Problem_5, Given_Case_2 ) { EXPECT_EQ( cdr( cons( 3, 4 ) ), 4 ); }

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
TEST( Problem_10, Given_Case ) { jobScheduler( testFunc, 100 ); }

// Problem 11
TEST( Problem_11, Given_Case )
{
  auto                     returned_strs   = autocomplete( "de", { "dog", "deer", "deal" } );
  std::vector<std::string> expected_return = { "deer", "deal" };
  EXPECT_EQ( returned_strs, expected_return );
}

// Problem 12
TEST( Problem_12, Given_Case ) { EXPECT_EQ( countWays( 4 ), 5 ); }

TEST( Problem_12, Test_Case_1 ) { EXPECT_EQ( countWays( 1 ), 1 ); }

TEST( Problem_12, Test_Case_2 ) { EXPECT_EQ( countWays( 2 ), 2 ); }

TEST( Problem_12, Test_Case_3 ) { EXPECT_EQ( countWays( 3 ), 3 ); }

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
// TEST( Problem_17, Given_Case ) { FAIL(); }

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
  std::vector<std::vector<int>> vec  = { { 10, 15, 20 }, { 14, 47, 6 }, { 2, 7, 10 } };
  auto                          cost = build_houses( vec );

  EXPECT_EQ( cost, 18 );
}

TEST( Problem_19, Test_Case_2 )
{
  std::vector<std::vector<int>> vec  = { { 10, 15, 20 }, { 6, 47, 14 }, { 2, 7, 10 } };
  auto                          cost = build_houses( vec );

  EXPECT_EQ( cost, 26 );
}

// Problem 20
TEST( Problem_20, Test_Case_1 )
{
  // A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10
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
  // A = 3 -> 7 -> 16 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10
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

// Problem 21
TEST( Problem_21, Given_Case )
{
  std::vector<std::pair<int, int>> schedule    = { std::make_pair( 30, 75 ),
                                                std::make_pair( 0, 50 ),
                                                std::make_pair( 60, 150 ) };
  int                              roomsNeeded = findMinRoomsNeeded( schedule );

  EXPECT_EQ( roomsNeeded, 2 );
}

TEST( Problem_21, Test_Case )
{
  std::vector<std::pair<int, int>> schedule    = { std::make_pair( 0, 75 ),
                                                std::make_pair( 25, 100 ),
                                                std::make_pair( 80, 100 ),
                                                std::make_pair( 50, 75 ) };
  int                              roomsNeeded = findMinRoomsNeeded( schedule );

  EXPECT_EQ( roomsNeeded, 3 );
}

// Problem 22
TEST( Problem_22, Given_Case_1 )
{
  // For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should
  // return ['the', 'quick', 'brown', 'fox'].

  std::vector<std::string> wordSet  = { "quick", "brown", "the", "fox" };
  std::string              str      = "thequickbrownfox";
  std::vector<std::string> expected = { "the", "quick", "brown", "fox" };
  auto                     result   = decompressString( wordSet, str );

  EXPECT_EQ( result, expected );
}

TEST( Problem_22, Given_Case_2 )
{
  // Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either
  // ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].

  std::vector<std::string> wordSet  = { "bed", "bath", "bedbath", "and", "beyond" };
  std::string              str      = "bedbathandbeyond";
  std::vector<std::string> expected = { "bed", "bath", "and", "beyond" };
  auto                     result   = decompressString( wordSet, str );

  EXPECT_EQ( result, expected );
}

// Problem 23
TEST( Problem_23, Given_Case )
{
  /*
  [[f, f, f, f],
   [t, t, f, t],
   [f, f, f, f],
   [f, f, f, f]]
  and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number of steps required to reach the end is
  7, since we would need to go through (1, 2) because there is a wall everywhere else on the second row.
  */

  std::vector<std::vector<bool>> maze = { { false, false, false, false },
                                          { true, true, false, true },
                                          { false, false, false, false },
                                          { false, false, false, false } };
  std::pair<int, int>            startPos( 3, 0 );
  std::pair<int, int>            endPos( 0, 0 );
  int                            expectedMoves = 7;
  int                            moves         = stepsToSolveMaze( maze, startPos, endPos );

  EXPECT_EQ( moves, expectedMoves );
}

TEST( Problem_23, Test_Case )
{
  std::vector<std::vector<bool>> maze = { { false, false, false, false },
                                          { true, true, false, true },
                                          { false, false, false, false },
                                          { false, false, false, false } };
  std::pair<int, int>            startPos( 3, 3 );
  std::pair<int, int>            endPos( 0, 0 );
  int                            expectedMoves = 6;
  int                            moves         = stepsToSolveMaze( maze, startPos, endPos );

  EXPECT_EQ( moves, expectedMoves );
}

// Problem 24
TEST( Problem_24, Test_Case )
{
  lbtNode * root = new lbtNode( 10 );
  lbtNode * a    = new lbtNode( 12 );
  lbtNode * b    = new lbtNode( 34 );
  lbtNode * c    = new lbtNode( 75 );
  lbtNode * d    = new lbtNode( 11 );
  lbtNode * e    = new lbtNode( 28 );
  lbtNode * f    = new lbtNode( 19 );
  lbtNode * g    = new lbtNode( 23 );
  lbtNode * h    = new lbtNode( 99 );

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

// Problem 25
TEST( Problem_25, Given_Case_1 )
{
  EXPECT_TRUE( regex( "ray", "ra." ) );
  EXPECT_FALSE( regex( "raymond", "ra." ) );
}

TEST( Problem_25, Given_Case_2 )
{
  EXPECT_TRUE( regex( "chat", ".*at" ) );
  EXPECT_FALSE( regex( "chats", ".*at" ) );
}

// Problem 26
TEST( Problem_26, Test_Case )
{
  slList list;
  list.add( new slNode( 1 ) );
  list.add( new slNode( 2 ) );
  list.add( new slNode( 3 ) );
  list.add( new slNode( 4 ) );
  list.add( new slNode( 5 ) );

  auto rmNode = getKthLastNode( list, 2 );

  EXPECT_EQ( rmNode->value, 4 );
}

// Problem 27
TEST( Problem_27, Given_Case )
{
  // For example, given the string "([])[]({})", you should return true.
  // Given the string "([)]" or "((()", you should return false.
  EXPECT_TRUE( isBallancedString( "([])[]({})" ) );
  EXPECT_FALSE( isBallancedString( "([)]" ) );
  EXPECT_FALSE( isBallancedString( "((()" ) );
}

// Problem 28
TEST( Problem_28, Given_Case )
{
  // For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k
  // = 16, you should return the following:
  //["the  quick brown", # 1 extra space on the left
  //"fox  jumps  over", # 2 extra spaces distributed evenly
  //"the   lazy   dog"] # 4 extra spaces distributed evenly

  std::vector<std::string> words            = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };
  std::vector<std::string> expected_strings = { "the  quick brown", "fox  jumps  over", "the   lazy   dog" };
  auto                     returned_strings = padWords( words, 16 );

  EXPECT_EQ( returned_strings, expected_strings );
}

// Problem 29
TEST( Problem_29, Given_case )
{
  std::string expected_encode = "4A3B2C1D2A";
  std::string expected_decode = "AAAABBBCCDAA";
  std::string encode          = runLengthEncode( "AAAABBBCCDAA" );
  std::string decode          = runLengthDecode( encode );

  EXPECT_EQ( encode, expected_encode );
  EXPECT_EQ( decode, expected_decode );
}

TEST( Problem_29, Test_case )
{
  std::string expected_encode = "2B3G2R1E";
  std::string expected_decode = "BBGGGRRE";
  std::string encode          = runLengthEncode( "BBGGGRRE" );
  std::string decode          = runLengthDecode( encode );

  EXPECT_EQ( encode, expected_encode );
  EXPECT_EQ( decode, expected_decode );
}

// Problem 30
TEST( Problem_30, Given_Case_1 )
{
  // [2, 1, 2] = 1 unit of water
  int unitWater = waterHeightMap( { 2, 1, 2 } );

  EXPECT_EQ( unitWater, 1 );
}

TEST( Problem_30, Given_Case_2 )
{
  // [3, 0, 1, 3, 0, 5] = 8 unit of water
  int unitWater = waterHeightMap( { 3, 0, 1, 3, 0, 5 } );

  EXPECT_EQ( unitWater, 8 );
}

// Problem 31
TEST( Problem_31, Given_Case )
{
  //�kitten� and �sitting� is three
  int result   = strDistance( "kitten", "sitting" );
  int expected = 3;

  EXPECT_EQ( result, expected );
}

// Problem 32
// TEST( Problem_32, Given_Case ) { FAIL(); }

// Problem 33
TEST( Problem_33, Given_Case )
{
  // For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:
  // 2 1.5 2 3.5 2 2 2

  std::vector<double> result   = runningMedian( { 2, 1, 5, 7, 2, 0, 5 } );
  std::vector<double> expected = { 2, 1.5, 2, 3.5, 2, 2, 2 };

  EXPECT_EQ( result, expected );
}

// Problem 34
TEST( Problem_34, Given_Case_1 )
{
  std::string result   = makePalindrome( "race" );
  std::string expected = "ecarace";

  EXPECT_EQ( result, expected );
}

TEST( Problem_34, Given_Case_2 )
{
  std::string result   = makePalindrome( "google" );
  std::string expected = "elgoogle";

  EXPECT_EQ( result, expected );
}

// Problem 35
TEST( Problem_35, Given_Case )
{
  std::vector<char> result = { 'G', 'B', 'R', 'R', 'B', 'R', 'G' };
  rgbSort( result );
  std::vector<char> expected = { 'R', 'R', 'R', 'G', 'G', 'B', 'B' };

  EXPECT_EQ( result, expected );
}

// Problem 36
TEST( Problem_36, Test_Case )
{
  BST * tree = new BST( 10 );
  tree->Insert( tree, 6 );
  tree->Insert( tree, 14 );
  tree->Insert( tree, 67 );
  tree->Insert( tree, 14 );
  tree->Insert( tree, 50 );

  int result   = findSecondLargetNode( tree );
  int expected = 50;

  EXPECT_EQ( result, expected );
}

// Problem 37
TEST( Problem_37, Given_Case )
{
  // {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}
  auto                          result   = getPowderSet( { 1, 2, 3 } );
  std::vector<std::vector<int>> expected = { {}, { 1 }, { 2 }, { 1, 2 }, { 3 }, { 1, 3 }, { 2, 3 }, { 1, 2, 3 } };

  EXPECT_EQ( result, expected );
}

// Problem 38
TEST( Problem_38, Test_Case )
{
  int result   = n_queens( 1 );
  int expected = 1;

  EXPECT_EQ( result, expected );
}

TEST( Problem_38, Test_Case_2 )
{
  int result   = n_queens( 4 );
  int expected = 2;

  EXPECT_EQ( result, expected );
}

TEST( Problem_38, Test_Case_3 )
{
  int result   = n_queens( 8 );
  int expected = 92;

  EXPECT_EQ( result, expected );
}

// Problem 39
/*TEST( Problem_39, Test_Case )
{
  CGOL();
  FAIL();
}*/

// Problem 40
TEST( Problem_40, Given_Case_1 )
{
  // Given [6, 1, 3, 3, 3, 6, 6], return 1.
  int result   = nonRepeatInt( { 6, 1, 3, 3, 3, 6, 6 } );
  int expected = 1;

  EXPECT_EQ( result, expected );
}

TEST( Problem_40, Given_Case_2 )
{
  // Given [13, 19, 13, 13], return 19.
  int result   = nonRepeatInt( { 13, 19, 13, 13 } );
  int expected = 19;

  EXPECT_EQ( result, expected );
}

// Problem 41
TEST( Problem_41, Given_Case_1 )
{
  // Given [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport 'YUL',
  // return ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

  std::vector<std::pair<std::string, std::string>> flights = { std::make_pair( "SFO", "HKO" ),
                                                               std::make_pair( "YYZ", "SFO" ),
                                                               std::make_pair( "YUL", "YYZ" ),
                                                               std::make_pair( "HKO", "ORD" ) };

  std::vector<std::string> result   = getItinerary( flights, "YUL" );
  std::vector<std::string> expected = { "YUL", "YYZ", "SFO", "HKO", "ORD" };

  EXPECT_EQ( result, expected );
}

TEST( Problem_41, Given_Case_2 )
{
  // Given [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', return null.

  std::vector<std::pair<std::string, std::string>> flights = { std::make_pair( "SFO", "COM" ),
                                                               std::make_pair( "COM", "YYZ" ) };

  std::vector<std::string> result   = getItinerary( flights, "COM" );
  std::vector<std::string> expected = {};

  EXPECT_EQ( result, expected );
}

TEST( Problem_41, Given_Case_3 )
{
  // Given [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', return ['A', 'B', 'C', 'A', 'C']

  std::vector<std::pair<std::string, std::string>> flights = { std::make_pair( "A", "B" ),
                                                               std::make_pair( "A", "C" ),
                                                               std::make_pair( "B", "C" ),
                                                               std::make_pair( "C", "A" ) };

  std::vector<std::string> result   = getItinerary( flights, "A" );
  std::vector<std::string> expected = { "A", "B", "C", "A", "C" };

  EXPECT_EQ( result, expected );
}

// Problem 42
TEST( Problem_42, Given_Case )
{
  // given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24
  auto             result   = subset_sum( { 12, 1, 61, 5, 9, 2 }, 24 );
  std::vector<int> expected = { 12, 1, 9, 2 };

  EXPECT_EQ( result, expected );
}

// Problem 43
TEST( Problem_43, Test_Push )
{
  stack testStack;
  testStack.push( 10 );

  EXPECT_EQ( testStack.top->val, 10 );
}

TEST( Problem_43, Test_Pop )
{
  stack testStack;
  testStack.push( 15 );

  int result   = testStack.pop();
  int expected = 15;

  EXPECT_EQ( result, expected );
}

TEST( Problem_43, Test_Pop_Exception )
{
  stack testStack;

  EXPECT_ANY_THROW( testStack.pop() );
}

TEST( Problem_43, Test_getMax )
{
  stack testStack;
  testStack.push( 15 );
  testStack.push( 18 );
  testStack.push( 2 );

  int result   = testStack.getMax();
  int expected = 18;

  EXPECT_EQ( result, expected );
}

TEST( Problem_43, Test_getMax_Exception )
{
  stack testStack;

  EXPECT_ANY_THROW( testStack.getMax() );
}

// Problem 44
TEST( Problem_44, Given_Case_1 )
{
  // The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4,3).
  int result   = outOfOrder( { 2, 4, 1, 3, 5 } );
  int expected = 3;

  EXPECT_EQ( result, expected );
}

TEST( Problem_44, Given_Case_2 )
{
  // The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.

  int result   = outOfOrder( { 5, 4, 3, 2, 1 } );
  int expected = 10;

  EXPECT_EQ( result, expected );
}