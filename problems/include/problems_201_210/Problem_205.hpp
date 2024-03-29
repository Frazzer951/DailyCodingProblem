#ifndef PROBLEMS_201_210_PROBLEM_205_HPP
#define PROBLEMS_201_210_PROBLEM_205_HPP

#pragma once

/* EASY
Given an integer, find the next permutation of it in absolute order. For
example, given 48975, the next permutation would be 49578.
*/
#include <algorithm>
#include <cmath>
#include <vector>

inline int get_next_perm( int _num ) {
  std::vector<int> num;

  while ( _num > 0 ) {
    num.push_back( _num % 10 );
    _num = _num / 10;
  }

  std::reverse( num.begin(), num.end() );
  int const n = (int) num.size();

  int tail_start = n - 1;
  while ( tail_start >= 0 && num[tail_start - 1] > num[tail_start] ) tail_start -= 1;

  int swap = tail_start;
  while ( swap < n && num[tail_start - 1] < num[swap] ) swap += 1;
  swap -= 1;

  int const temp      = num[tail_start - 1];
  num[tail_start - 1] = num[swap];
  num[swap]           = temp;

  int start = tail_start;
  int end   = (int) num.size() - 1;
  while ( start < end ) {
    int const temp = num[start];
    num[start]     = num[end];
    num[end]       = temp;
    start++;
    end--;
  }

  _num = 0;

  for ( int i = 0; i < num.size(); i++ ) { _num += num[i] * (int) pow( 10, (int) num.size() - i - 1 ); }

  return _num;
}
#endif
