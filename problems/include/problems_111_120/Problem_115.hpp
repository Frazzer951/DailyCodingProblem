#pragma once

/* HARD
Given two non-empty binary trees s and t, check whether tree t has exactly the
same structure and node values with a subtree of s. A subtree of s is a tree
consists of a node in s and all of this node's descendants. The tree s could
also be considered as a subtree of itself.
*/

#include "btNode.hpp"

inline bool isSubtree( btNode<int> * s, btNode<int> * t )
{
  if( s == nullptr || t == nullptr ) return false;

  if( t->value == s->value && t == s ) return true;

  return isSubtree( s->left, t ) || isSubtree( s->right, t );
}