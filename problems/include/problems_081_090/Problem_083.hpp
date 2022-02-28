#ifndef PROBLEMS_081_090_PROBLEM_083_HPP
#define PROBLEMS_081_090_PROBLEM_083_HPP


#pragma once

/* MEDIUM
Invert a binary tree.

For example, given the following tree:

    a
   / \
  b   c
 / \  /
d   e f


should become:

  a
 / \
 c  b
 \  / \
  f e  d
*/
#include "btNode.hpp"

inline void invert_B_Tree( btNode<char> * node )
{
  if( node == nullptr ) return;
  if( node->left == nullptr && node->right == nullptr ) return;

  // Invert Left Node
  invert_B_Tree( node->left );

  // Invert Right Node
  invert_B_Tree( node->right );

  // Invert Self
  auto * tmp  = node->left;
  node->left  = node->right;
  node->right = tmp;
}
#endif
