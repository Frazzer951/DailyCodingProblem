#ifndef PROBLEMS_121_130_PROBLEM_125_HPP
#define PROBLEMS_121_130_PROBLEM_125_HPP


#pragma once

/* EASY
Given the root of a binary search tree, and a target K, return two nodes in the
tree whose sum equals K.

For example, given the following tree and K of 20

    10
   /   \
 5      15
       /  \
     11    15


Return the nodes 5 and 15.
*/
#include <vector>

#include "btNode.hpp"

inline btNode<int> * search( btNode<int> * node, int val )
{
  if( node == nullptr ) return nullptr;

  if( node->value == val ) return node;
  if( node->value < val ) return search( node->right, val );
  return search( node->left, val );
}

inline std::vector<btNode<int> *> iter_tree( btNode<int> * root )
{
  std::vector<btNode<int> *> nodes;
  if( root != nullptr )
  {
    for( auto * node : iter_tree( root->left ) ) nodes.push_back( node );

    nodes.push_back( root );

    for( auto * node : iter_tree( root->right ) ) nodes.push_back( node );
  }
  return nodes;
}

inline std::pair<btNode<int> *, btNode<int> *> two_sum( btNode<int> * root, int K )
{
  for( auto * node_one : iter_tree( root ) )
  {
    auto * node_two = search( root, K - node_one->value );

    if( node_two != nullptr ) return std::make_pair( node_one, node_two );
  }
  return std::make_pair( nullptr, nullptr );
}
#endif
