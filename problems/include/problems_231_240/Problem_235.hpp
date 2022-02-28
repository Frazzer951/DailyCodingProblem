#ifndef PROBLEMS_231_240_PROBLEM_235_HPP
#define PROBLEMS_231_240_PROBLEM_235_HPP


#pragma once

/* HARD
Given an array of numbers of length N, find both the minimum and maximum using
less than 2 * (N - 2) comparisons.
*/
#include <vector>

inline std::pair<int, int> min_and_max( std::vector<int> arr )
{
  if( arr.size() == 1 ) return std::make_pair( arr[0], arr[0] );
  if( arr.size() == 2 )
    return ( arr[0] < arr[1] ) ? std::make_pair( arr[0], arr[1] ) : std::make_pair( arr[1], arr[0] );

  int  n = (int) arr.size() / 2;
  auto l = min_and_max( std::vector<int>( arr.begin(), arr.begin() + n ) );
  auto r = min_and_max( std::vector<int>( arr.begin() + n, arr.end() ) );
  return std::make_pair( std::min( l.first, r.first ), std::max( l.second, r.second ) );
}
#endif
