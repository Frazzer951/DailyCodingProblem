#ifndef PROBLEMS_171_180_PROBLEM_179_HPP
#define PROBLEMS_171_180_PROBLEM_179_HPP


#pragma once

/* MEDIUM
Given the sequence of keys visited by a postorder traversal of a binary search
tree, reconstruct the tree.

For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the
following tree:

    5
   / \
  3   7
 / \   \
2   4   8
*/
#include <vector>

#include "btNode.hpp"

inline btNode<int> * add( btNode<int> * root, int x )
{
  if( root == nullptr )
  {
    root = new btNode( x );
    return root;
  }

  if( x > root->value ) { root->right = add( root->right, x ); }
  else
  {
    root->left = add( root->left, x );
  }
  return root;
}

inline btNode<int> * createBSTfromPostOrder( std::vector<int> values )
{
  btNode<int> * newTree = nullptr;

  for( auto it = values.rbegin(); it != values.rend(); ++it ) { newTree = add( newTree, *it ); }

  return newTree;
}
#endif
