#ifndef PROBLEMS_051_060_PROBLEM_051_HPP
#define PROBLEMS_051_060_PROBLEM_051_HPP

#pragma once

/* MEDIUM
Given a function that generates perfectly random numbers between 1 and k
(inclusive), where k is an input, write a function that shuffles a deck of cards
represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations of the deck is equally likely.
*/
#include <cstdlib>
#include <vector>

inline std::vector<int> shuffle( std::vector<int> arr ) {
  int const n = (int) arr.size();

  for ( int i = 0; i < n - 1; i++ ) {
    int const j    = rand() % ( n - 1 - i ) + i;
    int const temp = arr[i];
    arr[i]         = arr[j];
    arr[j]         = temp;
  }
  return arr;
}
#endif
