#pragma once

/*
Determine whether a tree is a valid binary search tree.

A binary search tree is a tree with two children, left
and right, and satisfies the constraint that the key
in the left child must be less than or equal to the
root and the key in the right child must be greater
than or equal to the root.
*/

#include "Futils.hpp"

inline bool validateBST( btNode * node )
{
  if( node == nullptr ) return true;
  if( node->left == nullptr && node->right == nullptr ) return true;

  if( node->left != nullptr && node->left->value > node->value ) return false;
  if( node->right != nullptr && node->right->value < node->value ) return false;

  return validateBST( node->left ) && validateBST( node->right );
}