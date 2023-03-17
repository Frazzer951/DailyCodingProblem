#ifndef PROBLEMS_081_090_PROBLEM_090_HPP
#define PROBLEMS_081_090_PROBLEM_090_HPP

#pragma once

/* MEDIUM
Given an integer n and a list of integers l, write a function that randomly
generates a number from 0 to n-1 that isn't in l (uniform).
*/
#include <vector>

inline int randNotInL( const int &n, const std::vector<int> &l ) {
  int x = rand() % n;

  bool included = false;
  for ( int const i : l ) {
    if ( i == x ) {
      included = true;
      break;
    }
  }

  if ( included ) x = randNotInL( n, l );

  return x;
}
#endif
