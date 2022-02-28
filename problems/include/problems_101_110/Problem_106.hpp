#ifndef PROBLEMS_101_110_PROBLEM_106_HPP
#define PROBLEMS_101_110_PROBLEM_106_HPP


#pragma once

/* MEDIUM
Given an integer list where each number represents the number of hops you can
make, determine whether you can reach to the last index starting at index 0.

For example, [2, 0, 1, 0] returns True while [1, 1, 0, 1] returns False.
*/
#include <vector>

inline bool validate_hops( std::vector<int> hops )
{
  int index = 0;

  while( index <= hops.size() )
  {
    if( hops[index] == 0 ) break;
    index += hops[index];
  }

  return index == hops.size() - 1;
}
#endif
