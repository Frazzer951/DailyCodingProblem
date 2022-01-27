#ifndef PROBLEMS_241_250_PROBLEM_247_HPP
#define PROBLEMS_241_250_PROBLEM_247_HPP

#pragma once

/* EASY
Given a binary tree, determine whether or not it is height-balanced. A
height-balanced binary tree can be defined as one in which the heights of the
two subtrees of any node never differ by more than one.
*/

#include "btNode.hpp"

int get_height( btNode<int> * node )
{
  if( node == nullptr ) return 0;
  return 1 + std::max( get_height( node->left ), get_height( node->right ) );
}

bool is_height_balanced( btNode<int> * root )
{
  if( root == nullptr ) return true;
  int l_h = get_height( root->left );
  int r_h = get_height( root->right );
  if( abs( l_h - r_h ) > 1 ) return false;
  return is_height_balanced( root->left ) && is_height_balanced( root->right );
}

#endif
