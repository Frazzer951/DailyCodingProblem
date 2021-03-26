/* MEDIUM
Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.
*/

#include <Windows.h>
#include <iostream>

void test()
{
  std::cout << "Running function test\n";
}

void jobScheduler( void f(), int n )
{
  Sleep( n );
  f();
}

int prob_10()
{
  std::cout << "\nProblem 10\n";

  jobScheduler( test, 1000 );

  return 0;
}