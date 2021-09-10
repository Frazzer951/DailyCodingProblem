#pragma once

/* MEDIUM
Given the sequence of keys visited by a postorder traversal of a binary search tree, reconstruct the tree.

For example, given the sequence 2, 4, 3, 8, 7, 5, you should construct the following tree:

    5
   / \
  3   7
 / \   \
2   4   8
We will be sending the solution tomorrow, along with tomorrow's question. As always, feel free to shoot us an email if
there's anything we can help with.
*/

#include <vector>

#include "Futils.hpp"

inline ibtNode * add( ibtNode * root, int x )
{
  if( root == nullptr )
  {
    root = new ibtNode( x );
    return root;
  }

  if( x > root->value ) { root->right = add( root->right, x ); }
  else
  {
    root->left = add( root->left, x );
  }
  return root;
}

inline ibtNode * createBSTfromPostOrder( std::vector<int> values )
{
  ibtNode * newTree = nullptr;

  for( auto it = values.rbegin(); it != values.rend(); ++it ) { newTree = add( newTree, *it ); }

  return newTree;
}