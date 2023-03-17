#ifndef PROBLEMS_171_180_PROBLEM_177_HPP
#define PROBLEMS_171_180_PROBLEM_177_HPP

#pragma once

/* EASY
Given a linked list and a positive integer k, rotate the list to the right by k
places.

For example, given the linked list 7 -> 7 -> 3 -> 5 and k = 2, it should become
3 -> 5 -> 7 -> 7.

Given the linked list 1 -> 2 -> 3 -> 4 -> 5 and k = 3, it should become 3 -> 4
-> 5 -> 1 -> 2.
*/
#include "slNode.hpp"

inline slNode<int> *rotate( slNode<int> *head, int k ) {
  slNode<int> *fast = head;
  slNode<int> *slow = head;

  for ( int i = 0; i < k; i++ ) fast = fast->next;

  while ( fast->next != nullptr ) {
    slow = slow->next;
    fast = fast->next;
  }

  slNode<int> *new_head = slow->next;
  fast->next            = head;
  slow->next            = nullptr;

  return new_head;
}
#endif
