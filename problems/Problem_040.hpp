#pragma once

/* HARD
Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find
and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.
*/

#include <vector>

using namespace std;

/*
def find_unique(arr):
    result_arr = [0] * 32
    for num in arr:
        for i in range(32):
            bit = num >> i & 1
            result_arr[i] = (result_arr[i] + bit) % 3

    result = 0
    for i, bit in enumerate(result_arr):
        if bit:
            result += 2 ** i

    return result
*/

int nonRepeatInt( vector<int> v )
{
  vector<int> result_arr( 32, 0 );
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
    if( result_arr[i] ) { result += (int)std::pow( 2, i ); }
  }

  return result;
}