#ifndef PROBLEMS_091_100_PROBLEM_094_HPP
#define PROBLEMS_091_100_PROBLEM_094_HPP

#pragma once

/* EASY
Given a binary tree of integers, find the maximum path sum between two nodes.
The path must go through at least one node, and does not need to go through the
root.
*/
#include <limits>

#include "btNode.hpp"

inline std::pair<int, int> helper( btNode<int> *root ) {
  if ( root == nullptr ) return std::make_pair( std::numeric_limits<int>::min(), 0 );

  auto      left         = helper( root->left );
  int const left_max_sum = left.first;
  int const left_path    = left.second;

  auto      right         = helper( root->right );
  int const right_max_sum = right.first;
  int const right_path    = right.second;

  // Calculates the maximum path through the root
  int const root_max_sum = std::max( 0, left_path ) + root->value + std::max( 0, right_path );
  // Find the maximum path, including or excluding the root
  int const max_sum      = std::max( left_max_sum, std::max( root_max_sum, right_max_sum ) );
  // Find the maximum path including and ending at the root
  int const root_path    = std::max( left_path, std::max( right_path, 0 ) ) + root->value;

  return std::make_pair( max_sum, root_path );
}

inline int max_path_sum( btNode<int> *root ) {
  // Return only the maximum path
  return helper( root ).first;
}
#endif
