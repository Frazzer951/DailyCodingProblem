#ifndef PROBLEMS_241_250_PROBLEM_249_HPP
#define PROBLEMS_241_250_PROBLEM_249_HPP


#pragma once

/* HARD
Given an array of integers, find the maximum XOR of any two elements.
*/
#include <vector>

inline int max_xor( std::vector<int> arr )
{
  int max_xor = 0;
  for( int i = 0; i < arr.size(); i++ )
  {
    for( int j = i + 1; j < arr.size(); j++ )
    {
      int cur_xor = arr[i] ^ arr[j];
      if( cur_xor > max_xor )
      {
        max_xor = cur_xor;
      }
    }
  }
  return max_xor;
}
#endif
