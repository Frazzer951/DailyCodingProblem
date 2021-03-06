#pragma once

/* MEDIUM
Given a node in a binary search tree, return the next bigger element, also known as the inorder successor.

For example, the inorder successor of 22 is 30.

   10
  /  \
 5    30
     /  \
   22    35
You can assume each node has a parent pointer.
*/

#include "Problem_112.hpp"

inline int nextElement( pbtNode * node )
{
  auto * curNode = node;

  if( node->right != nullptr ) { curNode = curNode->right; }
  else
  {
    curNode = curNode->parent;
    if( curNode->left == nullptr || curNode->left == node ) return curNode->value;
  }

  while( curNode->left != nullptr ) { curNode = curNode->left; }
  return curNode->value;
}