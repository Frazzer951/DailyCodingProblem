#ifndef PROBLEMS_011_020_PROBLEM_014_HPP
#define PROBLEMS_011_020_PROBLEM_014_HPP


#pragma once

/* MEDIUM
The area of a circle is defined as πr^2. Estimate π to 3 decimal places using a
Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
*/
#include <cstdlib>
#include <iostream>

inline double monteCarloPi( int n )
{
  // PI = 4 * (Points in circle)/(Total Points)

  double inCircle = 0;
  double total    = 0;

  for( int i = 0; i < n; ++i )
  {
    double x = ( (double) rand() ) / (double) RAND_MAX;
    double y = ( (double) rand() ) / (double) RAND_MAX;

    total++;

    if( x * x + y * y <= 1 ) { inCircle++; }
  }

  double PI_Guess = 4.0 * inCircle / total;

  return PI_Guess;
}

inline int prob_14()
{
  std::cout << "\nProblem 14\n";

  std::cout << "At 10 iterations PI is estimated as: " << monteCarloPi( 10 ) << '\n';
  std::cout << "At 100 iterations PI is estimated as: " << monteCarloPi( 100 ) << '\n';
  std::cout << "At 1000 iterations PI is estimated as: " << monteCarloPi( 1000 ) << '\n';
  std::cout << "At 1000000 iterations PI is estimated as: " << monteCarloPi( 1000000 ) << '\n';
  // std::cout << "At 10000000 iterations PI is estimated as: " << monteCarloPi( 10000000 ) << '\n';
  // std::cout << "At 100000000 iterations PI is estimated as: " << monteCarloPi( 100000000 ) << '\n';

  return 0;
}
#endif
