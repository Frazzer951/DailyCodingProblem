#ifndef PROBLEMS_121_130_PROBLEM_129_HPP
#define PROBLEMS_121_130_PROBLEM_129_HPP

#pragma once

/* MEDIUM
Given a real number n, find the square root of n. For example, given n = 9,
return 3.
*/
#include <cmath>

inline double squareroot( double n, double error = 0.00000000000001 ) {
  double lo    = 0.0;
  double hi    = n;
  double guess = ( lo + hi ) / 2.0;

  while ( std::abs( std::pow( guess, 2 ) - n ) >= error ) {
    if ( std::pow( guess, 2 ) > n )
      hi = guess;
    else
      lo = guess;
    guess = ( lo + hi ) / 2.0;
  }
  return guess;
}
#endif
