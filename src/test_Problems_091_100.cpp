#include "Problem_091.hpp"
#include "Problem_092.hpp"
#include "Problem_093.hpp"
#include "Problem_094.hpp"
#include "Problem_095.hpp"
#include "Problem_096.hpp"
#include "Problem_097.hpp"
#include "Problem_098.hpp"

#include "gtest/gtest.h"

// Problem 92
TEST( Problem_92, Given_Case )
{
  /*
  For example, given {'CSC300': ['CSC100', 'CSC200'],
                      'CSC200': ['CSC100'],
                      'CSC100': []},
  should return ['CSC100', 'CSC200', 'CSCS300'].
  */

  std::map<std::string, std::vector<std::string>> course_dependencies = { { "CSC300", { "CSC100", "CSC200" } }, { "CSC200", { "CSC100" } }, { "CSC100", {} } };

  std::vector<std::string> expected = { "CSC100", "CSC200", "CSC300" };
  std::vector<std::string> result   = course_order( course_dependencies );

  EXPECT_EQ( expected, result );
}

// Problem 93
TEST( Problem_93, Test_Case_1 )
{
  auto * root = new btNode( 'f' );

  root->left             = new btNode( 'g' );
  root->left->left       = new btNode( 'e' );
  root->left->left->left = new btNode( 'a' );
  root->left->right      = new btNode( 'i' );

  root->right               = new btNode( 'h' );
  root->right->right        = new btNode( 'k' );
  root->right->right->right = new btNode( 'l' );
  root->right->left         = new btNode( 'b' );
  root->right->right->left  = new btNode( 'c' );

  btNode * result      = largest_subBST( root );
  int      result_size = largest_subBST_size( root );

  EXPECT_EQ( root->right, result );
  EXPECT_EQ( 5, result_size );
}