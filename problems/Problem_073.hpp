#pragma once

/* EASY
Given the head of a singly linked list, reverse it in-place.
*/

#include "Futils.hpp"

void reverse_slList( slList & list )
{
  slNode * prev = nullptr;
  slNode * next = nullptr;
  slNode * curr = list.head;

  while( curr != nullptr )
  {
    next       = curr->next;
    curr->next = prev;
    prev       = curr;
    curr       = next;
  }
  list.head = list.tail;

  slNode * last = prev;
  while( last->next != nullptr ) last = last->next;
  list.tail = last;
}