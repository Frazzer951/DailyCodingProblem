#ifndef PROBLEMS_011_020_PROBLEM_015_HPP
#define PROBLEMS_011_020_PROBLEM_015_HPP

#pragma once

/* MEDIUM
Given a stream of elements too large to store in memory, pick a random element
from the stream with uniform probability.
*/
#include <cstdlib>
#include <iostream>
#include <vector>

inline int randElement( std::vector<int> v ) {
  int const index = (int) ( rand() % v.size() );

  return v[index];
}

inline int prob_15() {
  std::cout << "\nProblem 15\n";

  std::cout << "A random element from the list [10, 15, 12, 67, 21, 43] is " << randElement( { 10, 15, 12, 67, 21, 43 } )
            << ".\n";
  std::cout << "A random element from the list [10, 15, 12, 67, 21, 43] is " << randElement( { 10, 15, 12, 67, 21, 43 } )
            << ".\n";
  std::cout << "A random element from the list [10, 15, 12, 67, 21, 43] is " << randElement( { 10, 15, 12, 67, 21, 43 } )
            << ".\n";
  std::cout << "A random element from the list [10, 15, 12, 67, 21, 43] is " << randElement( { 10, 15, 12, 67, 21, 43 } )
            << ".\n";

  return 0;
}
#endif
