#pragma once

/* MEDIUM
Given the root to a binary search tree, find the second largest node in the
tree.
*/

#include <iostream>
#include <vector>

class BST
{
public:
  int  data { 0 };
  BST *left { nullptr }, *right { nullptr };

  // Default constructor.
  BST() = default;

  // Parameterized constructor.
  BST( int value ) : data( value ) { left = right = nullptr; }

  // Insert function.
  BST * Insert( BST * root, int value )
  {
    if( root == nullptr )
    {
      // Insert the first node, if root is NULL.
      return new BST( value );
    }

    // Insert data.
    if( value > root->data )
    {
      // Insert right node data, if the 'value'
      // to be inserted is greater than 'root' node data.

      // Process right nodes.
      root->right = Insert( root->right, value );
    }
    else
    {
      // Insert left node data, if the 'value'
      // to be inserted is greater than 'root' node data.

      // Process left nodes.
      root->left = Insert( root->left, value );
    }

    // Return 'root' node, after insertion.
    return root;
  }

  // Inorder traversal function.
  // This gives data in sorted order.
  void Inorder( BST * root )
  {
    if( root == nullptr ) { return; }
    Inorder( root->left );
    std::cout << root->data << std::endl;
    Inorder( root->right );
  }
};

inline void revInorder( BST * node, int & count, int & val )
{
  if( node == nullptr || count == 2 ) return;

  if( node->right != nullptr ) revInorder( node->right, count, val );

  count++;

  if( count == 2 )
  {
    val = node->data;
    return;
  }

  if( node->left != nullptr ) revInorder( node->left, count, val );
}

inline int findSecondLargetNode( BST * root )
{
  int count = 0;
  int val   = 0;
  revInorder( root, count, val );
  return val;
}