#ifndef PROBLEMS_091_100_PROBLEM_096_HPP
#define PROBLEMS_091_100_PROBLEM_096_HPP

#pragma once

/* EASY
Given a number in the form of a list of digits, return all possible
permutations.

For example, given [1,2,3], return
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]].
*/

#include <vector>

#include "problems_091_100/Problem_095.hpp"

inline std::vector<std::vector<int>> getPermutations( const std::vector<int> & nums )
{
  auto                          permutation  = nums;
  std::vector<std::vector<int>> permutations = { permutation };
  nextPermutation( permutation );

  while( permutation != nums )
  {
    permutations.push_back( permutation );
    nextPermutation( permutation );
  }

  return permutations;
}
#endif
