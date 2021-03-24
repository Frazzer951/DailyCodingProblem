/*
A univalve tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of univalve subtrees.

For example, the following tree has 5 univalve subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1
*/

#include <iostream>

struct Node
{
  int           data;
  struct Node * left;
  struct Node * right;

  Node( int val )
  {
    data = val;

    left  = NULL;
    right = NULL;
  }
};

bool sameChildren( Node * root )
{
  if( root == NULL ) return true;
  if( root->left == NULL && root->right == NULL ) return true;

  if( root->data != root->left->data ) return false;
  if( root->data != root->right->data ) return false;

  return sameChildren( root->left ) && sameChildren( root->right );
}

int countUnivalTree( Node * root )
{
  if( root == NULL ) return 0;

  if( root->left == NULL && root->right == NULL )
  {
    return 1;
  }
  int count = 0;

  if( sameChildren( root ) ) count++;

  return count + countUnivalTree( root->left ) + countUnivalTree( root->right );
}

int prob_8()
{
  std::cout << "\nProblem 8\n";

  struct Node * root       = new Node( 0 );
  root->left               = new Node( 1 );
  root->right              = new Node( 0 );
  root->right->right       = new Node( 0 );
  root->right->left        = new Node( 1 );
  root->right->left->left  = new Node( 1 );
  root->right->left->right = new Node( 1 );

  std::cout << "The tree of root has " << countUnivalTree( root ) << " univalve subtrees\n";

  struct Node * root2       = new Node( 1 );
  root2->left               = new Node( 1 );
  root2->left->left         = new Node( 1 );
  root2->left->right        = new Node( 0 );
  root2->right              = new Node( 0 );
  root2->right->right       = new Node( 1 );
  root2->right->left        = new Node( 0 );
  root2->right->left->left  = new Node( 0 );
  root2->right->left->right = new Node( 0 );

  std::cout << "The tree of root2 has " << countUnivalTree( root2 ) << " univalve subtrees\n";

  return 0;
}