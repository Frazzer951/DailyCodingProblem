#ifndef PROBLEMS_221_230_PROBLEM_230_HPP
#define PROBLEMS_221_230_PROBLEM_230_HPP


#pragma once

/* MEDIUM
You are given N identical eggs and access to a building with k floors. Your task
is to find the lowest floor that will cause an egg to break, if dropped from
that floor. Once an egg breaks, it cannot be dropped again. If an egg breaks
when dropped from the xth floor, you can assume it will also break when dropped
from any floor greater than x.

Write an algorithm that finds the minimum number of trial drops it will take, in
the worst case, to identify this floor.

For example, if N = 1 and k = 5, we will need to try dropping the egg at every
floor, beginning with the first, until we reach the fifth floor, so our solution
will be 5.
*/
#include <limits>

inline int min_drops( int eggs, int floors )
{
  std::vector<std::vector<int>> trials =
      std::vector( eggs + 1, std::vector( floors + 1, std::numeric_limits<int>::max() ) );

  for( int i = 0; i <= eggs; i++ ) { trials[i][0] = 0; }
  for( int i = 1; i <= eggs; i++ )
  {
    for( int j = 1; j <= floors; j++ )
    {
      std::vector<int> options;
      for( int x = 1; x <= j; x++ ) { options.push_back( std::max( trials[i - 1][x - 1], trials[i][j - x] ) ); }
      int min = std::numeric_limits<int>::max();
      for( auto & option : options ) { min = std::min( min, option ); }
      trials[i][j] = 1 + min;
    }
  }
  return trials[eggs][floors];
}
#endif
