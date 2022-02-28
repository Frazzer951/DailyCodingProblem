#ifndef PROBLEMS_201_210_PROBLEM_206_HPP
#define PROBLEMS_201_210_PROBLEM_206_HPP


#pragma once

/* EASY
A permutation can be specified by an array P, where P[i] represents the location
of the element at i in the permutation. For example, [2, 1, 0] represents the
permutation where elements at the index 0 and 2 are swapped.

Given an array and a permutation, apply the permutation to the array. For
example, given the array ["a", "b", "c"] and the permutation [2, 1, 0], return
["c", "b", "a"].
*/
#include <vector>

inline std::vector<char> genPermutation( std::vector<char> arr, std::vector<int> permutation )
{
  std::vector<char> perm( arr.size() );

  for( int i = 0; i < permutation.size(); i++ ) { perm[permutation[i]] = arr[i]; }

  return perm;
}
#endif
