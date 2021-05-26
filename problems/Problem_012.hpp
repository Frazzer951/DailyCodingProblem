#pragma once

/* HARD
There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N,
write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive
integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
*/

#include <iostream>

inline int fib( int n )
{
  if( n <= 1 ) return n;

  return fib( n - 1 ) + fib( n - 2 );
}

inline int countWays( int n ) { return fib( n + 1 ); }

inline int prob_12()
{
  std::cout << "\nProblem 12\n";

  std::cout << "You can climb a 1 step stair case " << countWays( 1 ) << " ways.\n";
  std::cout << "You can climb a 2 step stair case " << countWays( 2 ) << " ways.\n";
  std::cout << "You can climb a 3 step stair case " << countWays( 3 ) << " ways.\n";
  std::cout << "You can climb a 4 step stair case " << countWays( 4 ) << " ways.\n";

  return 0;
}