#pragma once

/* HARD
This problem was asked by Apple.

Given a tree, find the largest tree/subtree that is a BST.

Given a tree, return the size of the largest tree/subtree that is a BST.
*/

#include "Futils.hpp"
#include "Problem_089.hpp"

inline int btSize( btNode * node )
{
  if( node == nullptr ) return 0;

  int left  = btSize( node->left );
  int right = btSize( node->right );

  return 1 + left + right;
}

inline btNode * largest_subBST( btNode * root )
{
  if( validateBST( root ) ) return root;

  btNode * left  = largest_subBST( root->left );
  btNode * right = largest_subBST( root->right );

  int left_size  = btSize( left );
  int right_size = btSize( right );

  return ( left_size > right_size ) ? left : right;
}

inline int largest_subBST_size( btNode * root )
{
  auto * largest = largest_subBST( root );
  return btSize( largest );
}