#ifndef PROBLEMS_161_170_PROBLEM_164_HPP
#define PROBLEMS_161_170_PROBLEM_164_HPP


#pragma once

/* MEDIUM
You are given an array of length n + 1 whose elements belong to the set {1, 2,
..., n}. By the pigeonhole principle, there must be a duplicate. Find it in
linear time and space.
*/
#include <map>
#include <vector>

inline int findDuplicate( const std::vector<int> & arr )
{
  std::map<int, int> counts;
  for( int x : arr )
  {
    counts[x]++;
    if( counts[x] > 1 ) return x;
  }
  return 0;
}
#endif
