#pragma once

/* EASY
Given an integer, find the next permutation of it in absolute order. For example, given 48975, the next permutation
would be 49578.
*/

#include <vector>

inline int get_next_perm( int _num )
{
  std::vector<int> num;

  while( _num > 0 )
  {
    num.push_back( _num % 10 );
    _num = _num / 10;
  }

  std::reverse( num.begin(), num.end() );
  int n = num.size();

  int tail_start = n - 1;
  while( tail_start >= 0 && num[tail_start - 1] > num[tail_start] ) tail_start -= 1;

  int swap = tail_start;
  while( swap < n && num[tail_start - 1] < num[swap] ) swap += 1;
  swap -= 1;

  int temp            = num[tail_start - 1];
  num[tail_start - 1] = num[swap];
  num[swap]           = temp;

  int start = tail_start;
  int end   = num.size() - 1;
  while( start < end )
  {
    int temp   = num[start];
    num[start] = num[end];
    num[end]   = temp;
    start++;
    end--;
  }

  _num = 0;

  for( int i = 0; i < num.size(); i++ ) { _num += num[i] * pow( 10, num.size() - i - 1 ); }

  return _num;
}