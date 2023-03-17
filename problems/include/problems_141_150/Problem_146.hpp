#ifndef PROBLEMS_141_150_PROBLEM_146_HPP
#define PROBLEMS_141_150_PROBLEM_146_HPP

#pragma once

/* MEDIUM
Given a binary tree where all nodes are either 0 or 1, prune the tree so that
subtrees containing all 0s are removed.

For example, given the following tree:

   0
  / \
 1   0
    / \
   1   0
  / \
 0   0


should be pruned to:

   0
  / \
 1   0
    /
   1


We do not remove the tree at the root or its left child because it still has a 1
as a descendant.
*/
#include "btNode.hpp"

inline bool isZeroBranch( btNode<int> *node ) {
  if ( node == nullptr ) return false;
  if ( node->value == 1 ) return false;
  if ( node->value == 0 && ( node->left == nullptr || isZeroBranch( node->left ) )
       && ( node->right == nullptr || isZeroBranch( node->right ) ) )
    return true;
  return isZeroBranch( node->left ) && isZeroBranch( node->right );
}

inline btNode<int> *pruneZeroBranches( btNode<int> *root ) {
  if ( root == nullptr ) return root;
  if ( isZeroBranch( root ) ) return nullptr;

  root->left  = pruneZeroBranches( root->left );
  root->right = pruneZeroBranches( root->right );

  return root;
}
#endif
