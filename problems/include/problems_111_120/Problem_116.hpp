#ifndef PROBLEMS_111_120_PROBLEM_116_HPP
#define PROBLEMS_111_120_PROBLEM_116_HPP


#pragma once

/* MEDIUM
Generate a finite, but an arbitrarily large binary tree quickly in O(1).

That is, generate() should return a tree whose size is unbounded but finite.
*/
#include "btNode.hpp"

inline btNode<int> * generate()
{
  auto * root = new btNode( 0 );

  if( ( std::rand() % 100 ) < 50 )
  {
    root->left = generate();
  }
  if( ( std::rand() % 100 ) < 50 )
  {
    root->right = generate();
  }

  return root;
}
#endif
