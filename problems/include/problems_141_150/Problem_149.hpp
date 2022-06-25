#ifndef PROBLEMS_141_150_PROBLEM_149_HPP
#define PROBLEMS_141_150_PROBLEM_149_HPP


#pragma once

/* HARD
Given a list of numbers L, implement a method sum(i, j) which returns the sum
from the sublist L[i:j] (including i, excluding j).

For example, given L = [1, 2, 3, 4, 5], sum(1, 3) should return sum([2, 3]),
which is 5.

You can assume that you can do some pre-processing. sum() should be optimized
over the pre-processing step.
*/
#include <vector>

inline std::vector<int> sumPreprocess( std::vector<int> L )
{
  for( int i = 1; i < L.size(); i++ )
  {
    L[i] = L[i] + L[i - 1];
  }
  return L;
}

inline int sum( std::vector<int> L, int i, int j )
{
  if( j == 0 ) return 0;
  if( i == 0 ) return L[j - 1];
  return L[j - 1] - L[i - 1];
}
#endif
