#pragma once

/* MEDIUM
Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.
*/

#ifdef _WIN32
#  include <Windows.h>
#else
#  include <unistd.h>
#endif

#include <iostream>

inline void testFunc() { std::cout << "Running function test\n"; }

inline void jobScheduler( void f(), int n )
{
#ifdef _WIN32
  Sleep( n );
#else
  usleep( n * 1000 );    // takes microseconds
#endif

  f();
}

inline int prob_10()
{
  std::cout << "\nProblem 10\n";

  jobScheduler( testFunc, 10 );

  return 0;
}