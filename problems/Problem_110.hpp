#pragma once

/* MEDIUM
Given a binary tree, return all paths from the root to leaves.

For example, given the tree:

   1
  / \
 2   3
    / \
   4   5
Return [[1, 2], [1, 3, 4], [1, 3, 5]].
*/

#include <vector>

#include "Futils.hpp"
inline std::vector<std::vector<int>> getPaths( ibtNode * node )
{
  if( node->left == nullptr && node->right == nullptr )
    return std::vector<std::vector<int>>( 1, std::vector<int>( 1, node->value ) );

  std::vector<std::vector<int>> paths;

  if( node->left != nullptr )
  {
    auto left = getPaths( node->left );
    for( auto v : left )
    {
      v.insert( v.begin(), node->value );
      paths.push_back( v );
    }
  }
  if( node->right != nullptr )
  {
    auto right = getPaths( node->right );
    for( auto v : right )
    {
      v.insert( v.begin(), node->value );
      paths.push_back( v );
    }
  }
  return paths;
}