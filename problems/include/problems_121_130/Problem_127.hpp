#pragma once

/* EASY
Let's represent an integer in a linked list format by having each node represent
a digit in the number. The nodes make up the number in reversed order.

For example, the following linked list:

1 -> 2 -> 3 -> 4 -> 5


is the number 54321.

Given two linked lists in this format, return their sum in the same linked list
format.

For example, given

9 -> 9


5 -> 2


return 124 (99 + 25) as:

4 -> 2 -> 1
*/

#include "slNode.hpp"

inline slNode<int> * sum( slNode<int> * x, slNode<int> * y )
{
  auto *        sumNum    = new slNode( ( x->value + y->value ) % 10 );
  slNode<int> * cur       = sumNum;
  int           remainder = ( x->value + y->value ) / 10;
  x                       = x->next;
  y                       = y->next;
  while( x != nullptr || y != nullptr )
  {
    int curSum = remainder;
    if( x != nullptr )
    {
      curSum += x->value;
      x = x->next;
    }
    if( y != nullptr )
    {
      curSum += y->value;
      y = y->next;
    }

    remainder = curSum / 10;
    curSum    = curSum % 10;

    cur->next = new slNode( curSum );
    cur       = cur->next;
  }

  if( remainder > 0 ) cur->next = new slNode( remainder );

  return sumNum;
}