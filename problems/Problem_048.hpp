#pragma once

/* MEDIUM
Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

For example, given the following preorder traversal:

[a, b, d, e, c, f, g]

And the following inorder traversal:

[d, b, e, a, f, c, g]

You should return the following tree:

    a
   / \
  b   c
 / \ / \
d  e f  g
*/

#include <vector>

#include "btNode.hpp"

inline int get_index( std::vector<btNode<char> *> v, btNode<char> * node )
{
  for( int i = 0; i < v.size(); i++ )
  {
    if( v[i] == node ) return i;
  }
  return -1;
}

// Function to slice a given vector
// from range X to Y
inline std::vector<btNode<char> *> slicing( std::vector<btNode<char> *> & arr, int X, int Y )
{
  // Starting and Ending iterators
  auto start = arr.begin() + X;
  auto end   = arr.begin() + Y + 1;

  // To store the sliced vector
  std::vector<btNode<char> *> result( Y - X + 1 );

  // Copy vector using copy function()
  copy( start, end, result.begin() );

  // Return the final sliced vector
  return result;
}

inline btNode<char> * reconstruct( std::vector<btNode<char> *> preorder, std::vector<btNode<char> *> inorder )
{
  if( preorder.size() == 1 && inorder.size() == 1 ) { return preorder[0]; }

  btNode<char> * root   = preorder[0];
  int      root_i = get_index( inorder, root );

  //    root.left = reconstruct(preorder[1:1 + root_i], inorder[0:root_i])
  //    root.right = reconstruct(preorder[1 + root_i:], inorder[root_i + 1:])

  root->left  = reconstruct( slicing( preorder, 1, 1 + root_i ), slicing( inorder, 0, root_i ) );
  root->right = reconstruct( slicing( preorder, 1 + root_i, (int) preorder.size() - 1 ),
                             slicing( inorder, root_i + 1, (int) inorder.size() - 1 ) );

  return root;
}