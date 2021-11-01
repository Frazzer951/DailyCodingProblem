#ifndef PROBLEMS_201_210_PROBLEM_204_HPP
#define PROBLEMS_201_210_PROBLEM_204_HPP

#pragma once

/* EASY
Given a complete binary tree, count the number of nodes in faster than O(n)
time. Recall that a complete binary tree has every level filled except the last,
and the nodes in the last level are filled starting from the left.
*/

#include "btNode.hpp"

inline int findDepthLeft( btNode<int> * root )
{
  int depth = 0;

  while( root->left != nullptr )
  {
    root = root->left;
    depth++;
  }

  return depth;
}

inline int findDepthRight( btNode<int> * root )
{
  int depth = 0;

  while( root->right != nullptr )
  {
    root = root->right;
    depth++;
  }

  return depth;
}

inline int getCount( btNode<int> * root )
{
  if( root == nullptr ) return 0;

  int left  = findDepthLeft( root );
  int right = findDepthRight( root );

  if( left == right ) return ( 2 << left ) - 1;

  return getCount( root->left ) + getCount( root->right ) + 1;
}
#endif
