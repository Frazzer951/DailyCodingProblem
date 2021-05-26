#pragma once

#include <iostream>
#include <vector>

/* MEDIUM
Given the root to a binary search tree, find the second largest node in the tree.
*/

// C++ program to demonstrate insertion
// in a BST recursively.

class BST
{
public:
  int  data;
  BST *left, *right;

  // Default constructor.
  BST() :
    data( 0 ), left( NULL ), right( NULL ) {}

  // Parameterized constructor.
  BST( int value )
  {
    data = value;
    left = right = NULL;
  }

  // Insert function.
  BST * Insert( BST * root, int value )
  {
    if( !root )
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
    if( !root ) { return; }
    Inorder( root->left );
    std::cout << root->data << std::endl;
    Inorder( root->right );
  }
};

void revInorder( BST * node, int & count, int & val )
{
  if( node == NULL || count == 2 ) return;

  if( node->right ) revInorder( node->right, count, val );

  count++;

  if( count == 2 )
  {
    val = node->data;
    return;
  }

  if( node->left ) revInorder( node->left, count, val );
}

int findSecondLargetNode( BST * root )
{
  int count = 0;
  int val;
  revInorder( root, count, val );
  return val;
}