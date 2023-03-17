#ifndef PROBLEMS_091_100_PROBLEM_093_HPP
#define PROBLEMS_091_100_PROBLEM_093_HPP

#pragma once

/* HARD
Given a tree, find the largest tree/subtree that is a BST.

Given a tree, return the size of the largest tree/subtree that is a BST.
*/
#include "btNode.hpp"

#include "problems_081_090/Problem_089.hpp"

inline int btSize( btNode<char> *node ) {
  if ( node == nullptr ) return 0;

  int const left  = btSize( node->left );
  int const right = btSize( node->right );

  return 1 + left + right;
}

inline btNode<char> *largest_subBST( btNode<char> *root ) {
  if ( validateBST( root ) ) return root;

  btNode<char> *left  = largest_subBST( root->left );
  btNode<char> *right = largest_subBST( root->right );

  int const left_size  = btSize( left );
  int const right_size = btSize( right );

  return ( left_size > right_size ) ? left : right;
}

inline int largest_subBST_size( btNode<char> *root ) {
  auto *largest = largest_subBST( root );
  return btSize( largest );
}
#endif
