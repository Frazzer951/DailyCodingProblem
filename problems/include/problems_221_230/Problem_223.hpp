#ifndef PROBLEMS_221_230_PROBLEM_223_HPP
#define PROBLEMS_221_230_PROBLEM_223_HPP

#pragma once

/* HARD
Typically, an implementation of in-order traversal of a binary tree has O(h)
space complexity, where h is the height of the tree. Write a program to compute
the in-order traversal of a binary tree using O(1) space.
*/
#include <string>

#include "btNode.hpp"

inline std::string inOrderTraversal( btNode<int> *root ) {
  std::string result;
  auto       *curr = root;

  while ( curr != nullptr ) {
    if ( curr->left == nullptr ) {
      result += std::to_string( curr->value ) + " ";
      curr   = curr->right;
    } else {
      auto *desc = curr->left;
      while ( desc->right != nullptr && desc->right != curr ) { desc = desc->right; }

      if ( desc->right == nullptr ) {
        desc->right = curr;
        curr        = curr->left;
      } else {
        desc->right = nullptr;
        result      += std::to_string( curr->value ) + " ";
        curr        = curr->right;
      }
    }
  }
  return result;
}
#endif
