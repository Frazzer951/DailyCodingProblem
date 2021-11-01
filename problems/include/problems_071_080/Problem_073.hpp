#ifndef PROBLEMS_071_080_PROBLEM_073_HPP
#define PROBLEMS_071_080_PROBLEM_073_HPP

#pragma once

/* EASY
Given the head of a singly linked list, reverse it in-place.
*/

#include "slNode.hpp"

inline void reverse_slList( slList<int> & list )
{
  slNode<int> * prev = nullptr;
  slNode<int> * next = nullptr;
  slNode<int> * curr = list.head;

  while( curr != nullptr )
  {
    next       = curr->next;
    curr->next = prev;
    prev       = curr;
    curr       = next;
  }
  list.head = list.tail;

  slNode<int> * last = prev;
  while( last->next != nullptr ) last = last->next;
  list.tail = last;
}
#endif
