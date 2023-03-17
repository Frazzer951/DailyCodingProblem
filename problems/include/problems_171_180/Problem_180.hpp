#ifndef PROBLEMS_171_180_PROBLEM_180_HPP
#define PROBLEMS_171_180_PROBLEM_180_HPP

#pragma once

/* MEDIUM
Given a stack of N elements, interleave the first half of the stack with the
second half reversed using only one other queue. This should be done in-place.

Recall that you can only push or pop from a stack, and enqueue or dequeue from a
queue.

For example, if the stack is [1, 2, 3, 4, 5], it should become [1, 5, 2, 4, 3].
If the stack is [1, 2, 3, 4], it should become [1, 4, 2, 3].

Hint: Try working backwards from the end state.
*/
#include <queue>
#include <stack>

inline std::stack<int> interleave( std::stack<int> s ) {
  std::queue<int> q;

  size_t const size = s.size();

  for ( int i = 0; i < size; i++ ) {
    q.push( s.top() );
    s.pop();
  }

  for ( int i = 0; i < size / 2; i++ ) {
    q.push( q.front() );
    q.pop();
  }

  for ( int i = 0; i < int( ( (double) size / 2.0 ) + 0.5 ); i++ ) {
    s.push( q.front() );
    q.pop();
  }

  for ( int i = 0; i < size / 2; i++ ) {
    q.push( s.top() );
    s.pop();
    q.push( q.front() );
    q.pop();
  }
  if ( !s.empty() ) {
    q.push( s.top() );
    s.pop();
  }

  while ( !q.empty() ) {
    s.push( q.front() );
    q.pop();
  }

  return s;
}
#endif
