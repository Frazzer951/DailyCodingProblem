#pragma once

/* MEDIUM
Implement a queue using two stacks. Recall that a queue is a FIFO (first-in,
first-out) data structure with the following methods: enqueue, which inserts an
element into the queue, and dequeue, which removes it.
*/

#include <stack>
#include <stdexcept>

class queue_s
{
  std::stack<int> s1, s2;

public:
  void enqueue( int x )
  {
    while( !s1.empty() )
    {
      s2.push( s1.top() );
      s1.pop();
    }
    s1.push( x );
    while( !s2.empty() )
    {
      s1.push( s2.top() );
      s2.pop();
    }
  }

  int dequeue()
  {
    if( s1.empty() ) { throw std::out_of_range( "There are no items in the Queue!" ); }
    int x = s1.top();
    s1.pop();
    return x;
  }
};