#ifndef PROBLEMS_021_030_PROBLEM_026_HPP
#define PROBLEMS_021_030_PROBLEM_026_HPP


#pragma once

/* MEDIUM
Given a singly linked list and an integer k, remove the kth last element from
the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.
*/
#include "slNode.hpp"

inline slNode<int> * getKthLastNode( slList<int> list, int k )
{
  slNode<int> * slow = list.get( 0 );
  slNode<int> * fast = list.get( 0 );

  for( int i = 0; i < k; i++ ) fast = fast->next;

  slNode<int> * prev = slow;
  while( fast != nullptr )
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next;
  }
  prev->next = slow->next;

  return slow;
}
#endif
