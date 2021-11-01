#ifndef PROBLEMS_211_220_PROBLEM_218_HPP
#define PROBLEMS_211_220_PROBLEM_218_HPP

#pragma once

/* MEDIUM
Write an algorithm that computes the reversal of a directed graph. For example,
if a graph consists of A -> B -> C, it should become A <- B <- C.
*/

#include "slNode.hpp"

template<typename T>
inline slNode<T> * reverse( slNode<T> * root )
{
  slNode<T> * prev = nullptr;
  slNode<T> * curr = root;
  slNode<T> * next = nullptr;

  while( curr->next != nullptr )
  {
    next       = curr->next;
    curr->next = prev;
    prev       = curr;
    curr       = next;
  }

  curr->next = prev;

  return curr;
}
#endif
