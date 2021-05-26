#pragma once

/* EASY
Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of
'+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5

You should return 45, as it is (3 + 2) * (4 + 5).
*/

char PLUS   = '+';
char MINUS  = '-';
char TIMES  = '*';
char DIVIDE = '/';

inline int evaluate( btNode root )
{
  if( root.value == PLUS ) return evaluate( *root.left ) + evaluate( *root.right );
  if( root.value == MINUS )
    return evaluate( *root.left ) - evaluate( *root.right );
  else if( root.value == TIMES )
    return evaluate( *root.left ) * evaluate( *root.right );
  else if( root.value == DIVIDE )
    return evaluate( *root.left ) / evaluate( *root.right );
  else
    return root.value - 48;
}