#ifndef PROBLEMS_231_240_PROBLEM_240_HPP
#define PROBLEMS_231_240_PROBLEM_240_HPP

#pragma once

/* HARD
There are N couples sitting in a row of length 2 * N. They are currently ordered
randomly, but would like to rearrange themselves so that each couple's partners
can sit side by side.

What is the minimum number of swaps necessary for this to happen?
*/

#include <vector>

inline std::vector<int> sortPairs( std::vector<int> arr )
{
  std::vector<int> sorted( arr.size() );
  for( int i = 0; i < arr.size(); i++ ) { sorted[i] = arr[i]; }
  for( int i = 0; i < arr.size(); i += 2 )
  {
    for( int j = i + 1; j < arr.size(); j++ )
    {
      if( sorted[i] == sorted[j] )
      {
        if( j == i + 1 ) break;
        int temp      = sorted[i + 1];
        sorted[i + 1] = sorted[j];
        sorted[j]     = temp;
        break;
      }
    }
  }
  return sorted;
}

#endif
