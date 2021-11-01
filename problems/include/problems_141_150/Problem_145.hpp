#pragma once

/* EASY
Given the head of a singly linked list, swap every two nodes and return its
head.

For example, given 1 -> 2 -> 3 -> 4, return 2 -> 1 -> 4 -> 3.
*/

#include "slNode.hpp"

inline slNode<int> * swapEveryTwo( slNode<int> * root )
{
  slNode<int> * prev = nullptr;
  slNode<int> * cur  = root;
  slNode<int> * next = root->next;
  root               = next;

  while( cur != nullptr && next != nullptr )
  {
    if( prev != nullptr ) prev->next = next;
    cur->next  = next->next;
    next->next = cur;

    prev = cur;
    cur  = cur->next;
    if( cur != nullptr ) next = cur->next;
  }

  return root;
}