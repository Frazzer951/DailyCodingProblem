#ifndef PROBLEMS_031_040_PROBLEM_040_HPP
#define PROBLEMS_031_040_PROBLEM_040_HPP

#pragma once

/* HARD
Given an array of integers where every integer occurs three times except for one
integer, which only occurs once, find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13],
return 19.

Do this in O(N) time and O(1) space.
*/

#include <cmath>
#include <vector>

inline int nonRepeatInt( const std::vector<int> & v )
{
  std::vector<int> result_arr( 32, 0 );
  for( int num : v )
  {
    for( int i = 0; i < 32; i++ )
    {
      auto bit      = num >> i & 1;
      result_arr[i] = ( result_arr[i] + bit ) % 3;
    }
  }
  int result = 0;
  for( int i = 0; i < 32; i++ )
  {
    if( result_arr[i] != 0 ) { result += (int) pow( 2, i ); }
  }

  return result;
}
#endif
