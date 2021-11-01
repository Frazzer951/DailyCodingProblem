#ifndef PROBLEMS_041_050_PROBLEM_050_HPP
#define PROBLEMS_041_050_PROBLEM_050_HPP

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

#include "btNode.hpp"

inline char PLUS   = '+';
inline char MINUS  = '-';
inline char TIMES  = '*';
inline char DIVIDE = '/';

inline int evaluate( btNode<char> root )
{
  if( root.value == PLUS ) return evaluate( *root.left ) + evaluate( *root.right );
  if( root.value == MINUS ) return evaluate( *root.left ) - evaluate( *root.right );
  if( root.value == TIMES ) return evaluate( *root.left ) * evaluate( *root.right );
  if( root.value == DIVIDE ) return evaluate( *root.left ) / evaluate( *root.right );
  return root.value - 48;
}
#endif
