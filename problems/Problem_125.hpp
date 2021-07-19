#pragma once

/*
Given the root of a binary search tree, and a target K, return two nodes in the tree whose sum equals K.

For example, given the following tree and K of 20

    10
   /   \
 5      15
       /  \
     11    15
Return the nodes 5 and 15.
*/

#include <vector>

#include "Futils.hpp"

inline ibtNode * search( ibtNode * node, int val )
{
  if( node == nullptr ) return nullptr;

  if( node->value == val ) return node;
  if( node->value < val ) return search( node->right, val );
  return search( node->left, val );
}

inline std::vector<ibtNode *> iter_tree( ibtNode * root )
{
  std::vector<ibtNode *> nodes;
  if( root != nullptr )
  {
    for( auto * node : iter_tree( root->left ) ) nodes.push_back( node );

    nodes.push_back( root );

    for( auto * node : iter_tree( root->right ) ) nodes.push_back( node );
  }
  return nodes;
}

inline std::pair<ibtNode *, ibtNode *> two_sum( ibtNode * root, int K )
{
  for( auto * node_one : iter_tree( root ) )
  {
    auto * node_two = search( root, K - node_one->value );

    if( node_two != nullptr ) return std::make_pair( node_one, node_two );
  }
  return std::make_pair( nullptr, nullptr );
}
