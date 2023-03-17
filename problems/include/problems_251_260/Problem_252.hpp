#ifndef PROBLEMS_251_260_PROBLEM_252_HPP
#define PROBLEMS_251_260_PROBLEM_252_HPP

#pragma once

/* EASY
The ancient Egyptians used to express fractions as a sum of several terms where
each numerator is one. For example, 4 / 13 can be represented as 1 / 4 + 1 / 18
+ 1 / 468.

Create an algorithm to turn an ordinary fraction a / b, where a < b, into an
Egyptian fraction.
*/

#include <Futils.hpp>
#include <vector>

inline std::vector<int> egyptianFraction( int a, int b ) {
  std::vector<int> denominators;

  while ( a != 0 ) {
    int const ceil_div = b / a + static_cast<int>( b % a != 0 );
    denominators.push_back( ceil_div );
    a = mod( -b, a );
    b = b * ( ceil_div );
  }

  return denominators;
}

#endif
