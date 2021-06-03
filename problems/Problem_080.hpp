#pragma once

/* EASY
Given the root of a binary tree, return a deepest node. For example, in the following tree, return d.

    a
   / \
  b   c
 /
d
*/

#include "Futils.hpp"

inline std::pair<int, btNode *> find_deepest_helper( btNode * node, int depth )
{
  if( node == nullptr ) return std::make_pair( 0, node );
  if( node->left == nullptr && node->right == nullptr ) return std::make_pair( depth, node );

  auto left  = find_deepest_helper( node->left, depth + 1 );
  auto right = find_deepest_helper( node->right, depth + 1 );

  return ( left.first > right.first ) ? left : right;
}

inline btNode * find_deepest( btNode * root )
{
  auto deepest = find_deepest_helper( root, 0 );

  return deepest.second;
}