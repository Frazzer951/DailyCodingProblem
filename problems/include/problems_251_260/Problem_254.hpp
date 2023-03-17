#ifndef PROBLEMS_251_260_PROBLEM_254_HPP
#define PROBLEMS_251_260_PROBLEM_254_HPP

#pragma once

#include "Futils.hpp"
#include "btNode.hpp"

/* MEDIUM
Recall that a full binary tree is one in which each node is either a leaf node,
or has two children. Given a binary tree, convert it to a full one by removing
nodes with only one child.

For example, given the following tree:

         0
      /     \
    1         2
  /            \
3                 4
  \             /   \
    5          6     7


You should convert it to:

     0
  /     \
5         4
        /   \
       6     7
*/

inline btNode<int> *trim_tree( btNode<int> *node ) {
  if ( node == nullptr ) return nullptr;
  if ( node->left == nullptr && node->right == nullptr ) return node;
  if ( node->left != nullptr && node->right != nullptr ) {
    node->left  = trim_tree( node->left );
    node->right = trim_tree( node->right );
    return node;
  }
  if ( node->left != nullptr && node->right == nullptr ) { return trim_tree( node->left ); }
  if ( node->left == nullptr && node->right != nullptr ) { return trim_tree( node->right ); }
  return nullptr;
}

#endif
