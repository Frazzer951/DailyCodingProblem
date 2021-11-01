#pragma once

/* MEDIUM
Given a linked list, sort it in O(n log n) time and constant space.

For example, the linked list 4 -> 1 -> -3 -> 99 should become -3 -> 1 -> 4 -> 99
.
*/

#include <iostream>

struct LNode
{
  int     data;
  LNode * next;
};


inline bool operator==( const LNode & lhs, const LNode & rhs )
{
  if( lhs.data != rhs.data ) return false;
  if( lhs.next == nullptr && rhs.next != nullptr ) return false;
  if( lhs.next != nullptr && rhs.next == nullptr ) return false;
  if( lhs.next == nullptr && rhs.next == nullptr ) return true;
  return *lhs.next == *rhs.next;
}

inline std::ostream & operator<<( std::ostream & os, const LNode & n )
{
  os << n.data;
  if( n.next != nullptr ) { os << " -> " << *n.next; }
  return os;
}

inline void push( LNode ** head, int newData )
{
  auto * newNode = new LNode();
  newNode->data  = newData;
  newNode->next  = *head;
  *head          = newNode;
}

inline LNode * SortedMerge( LNode * a, LNode * b )
{
  LNode * result = nullptr;

  if( a == nullptr ) return b;
  if( b == nullptr ) return a;

  if( a->data <= b->data )
  {
    result       = a;
    result->next = SortedMerge( a->next, b );
  }
  else
  {
    result       = b;
    result->next = SortedMerge( a, b->next );
  }

  return result;
}

inline void FrontBackSplit( LNode * source, LNode ** front, LNode ** back )
{
  LNode * fast = source->next;
  LNode * slow = source;

  while( fast != nullptr )
  {
    fast = fast->next;
    if( fast != nullptr )
    {
      slow = slow->next;
      fast = fast->next;
    }
  }

  *front     = source;
  *back      = slow->next;
  slow->next = nullptr;
}

inline void MergeSort( LNode ** headRef )
{
  LNode * head = *headRef;
  LNode * a    = nullptr;
  LNode * b    = nullptr;

  if( head == nullptr || head->next == nullptr ) { return; }

  FrontBackSplit( head, &a, &b );

  MergeSort( &a );
  MergeSort( &b );

  *headRef = SortedMerge( a, b );
}
