#pragma once

/* EASY
Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
*/

#include "FUtils.h"

unsigned int length( slNode * head )
{
  if( head->next == NULL ) { return 1; }
  return 1 + length( head->next );
}

slNode * findNodeIntersect( slNode * a, slNode * b )
{
  unsigned int m    = length( a );
  unsigned int n    = length( b );
  slNode *     curA = a;
  slNode *     curB = b;

  if( m > n )
  {
    for( unsigned int i = 0; i < m - n; ++i ) curA = curA->next;
  }
  else
  {
    for( unsigned int i = 0; i < n - m; ++i ) curB = curB->next;
  }

  while( curA != curB )
  {
    curA = curA->next;
    curB = curB->next;
  }

  return curA;
}