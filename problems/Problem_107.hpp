#pragma once

/* EASY
Print the nodes in a binary tree level-wise.
For example, the following should print 1, 2, 3, 4, 5.

  1
 / \
2   3
   / \
  4   5
*/

#include <vector>

#include "Futils.hpp"
inline std::vector<int> bt_traverse( ibtNode * root )
{
  if( root == nullptr ) return {};

  std::vector<int> traverse = { root->value };

  auto left  = bt_traverse( root->left );
  auto right = bt_traverse( root->right );

  traverse.insert( traverse.end(), left.begin(), left.end() );
  traverse.insert( traverse.end(), right.begin(), right.end() );

  return traverse;
}