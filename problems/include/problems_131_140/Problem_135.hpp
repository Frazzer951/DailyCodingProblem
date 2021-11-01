#pragma once

/* EASY
Given a binary tree, find a minimum path sum from root to a leaf.

For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.

  10
 /  \
5    5
 \     \
   2    1
       /
     -1
*/

#include <limits>

#include "btNode.hpp"

inline int minPathSum( btNode<int> * root )
{
  if( root == nullptr ) return 0;
  if( root->left == nullptr && root->right == nullptr ) return root->value;

  int left  = std::numeric_limits<int>::max();
  int right = std::numeric_limits<int>::max();

  if( root->left != nullptr ) left = minPathSum( root->left );
  if( root->right != nullptr ) right = minPathSum( root->right );

  return root->value + std::min( left, right );
}