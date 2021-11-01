#pragma once

/* MEDIUM
Given a linked list of numbers and a pivot k, partition the linked list so that
all nodes less than k come before nodes greater than or equal to k.

For example, given the linked list 5 -> 1 -> 8 -> 0 -> 3 and k = 3, the solution
could be 1 -> 0 -> 5 -> 8 -> 3.
*/

#include "slNode.hpp"

inline slList<int> partition( slNode<int> * head, int pivot )
{
  slList<int> newList;

  while( head != nullptr )
  {
    if( head->value < pivot ) { newList.insert( new slNode( head->value ) ); }
    else
    {
      newList.add( new slNode( head->value ) );
    }
    head = head->next;
  }
  return newList;
}