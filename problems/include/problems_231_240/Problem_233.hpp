#ifndef PROBLEMS_231_240_PROBLEM_233_HPP
#define PROBLEMS_231_240_PROBLEM_233_HPP


#pragma once

/* EASY
Implement the function fib(n), which returns the nth number in the Fibonacci
sequence, using only O(1) space.
*/
inline int fib( int n )
{
  if( n == 0 ) return 0;
  if( n == 1 ) return 1;
  return fib( n - 1 ) + fib( n - 2 );
}
#endif
