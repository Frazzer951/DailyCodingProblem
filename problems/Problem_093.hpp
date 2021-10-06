#pragma once

/* HARD
This problem was asked by Apple.

Given a tree, find the largest tree/subtree that is a BST.

Given a tree, return the size of the largest tree/subtree that is a BST.
*/

#include "Problem_089.hpp"
#include "btNode.hpp"

inline int btSize( btNode<char> * node )
{
  if( node == nullptr ) return 0;

  int left  = btSize( node->left );
  int right = btSize( node->right );

  return 1 + left + right;
}

inline btNode<char> * largest_subBST( btNode<char> * root )
{
  if( validateBST( root ) ) return root;

  btNode<char> * left  = largest_subBST( root->left );
  btNode<char> * right = largest_subBST( root->right );

  int left_size  = btSize( left );
  int right_size = btSize( right );

  return ( left_size > right_size ) ? left : right;
}

inline int largest_subBST_size( btNode<char> * root )
{
  auto * largest = largest_subBST( root );
  return btSize( largest );
}