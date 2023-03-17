#ifndef PROBLEMS_231_240_PROBLEM_237_HPP
#define PROBLEMS_231_240_PROBLEM_237_HPP

#pragma once

/* EASY
A tree is symmetric if its data and shape remain unchanged when it is reflected
about the root node. The following tree is an example:

        4
      / | \
    3   5   3
  /           \
9              9


Given a k-ary tree, determine whether it is symmetric.
*/
#include "btNode.hpp"

inline bool isSymmetric( btNode<int> *left, btNode<int> *right ) {
  if ( left == nullptr && right == nullptr ) return true;
  if ( left == nullptr || right == nullptr ) return false;
  return left->value == right->value && isSymmetric( left->left, right->right ) && isSymmetric( left->right, right->left );
}

#endif
