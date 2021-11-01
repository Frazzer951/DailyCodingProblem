#ifndef PROBLEMS_051_060_PROBLEM_058_HPP
#define PROBLEMS_051_060_PROBLEM_058_HPP

#pragma once

/* MEDIUM
An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in faster than
linear time. If the element doesn't exist in the array, return null.

For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4
(the index of 8 in the array).

You can assume all the integers in the array are unique.
*/

#include <vector>

inline int shifted_array_search( std::vector<int> lst, int num )
{
  int i    = (int) lst.size() / 2;
  int dist = i / 2;

  while( true )
  {
    if( lst[0] > lst[i] && lst[i - 1] > lst[i] ) break;
    if( dist == 0 ) break;
    if( lst[0] <= lst[i] ) i = i + dist;
    else if( lst[i - 1] <= lst[i] )
      i = i - dist;
    else
      break;

    dist = dist / 2;
  }

  int low  = i;
  int high = i - 1;
  dist     = (int) lst.size() / 2;

  while( true )
  {
    if( dist == 0 ) return -1;

    int guess_ind = ( low + dist ) % (int) lst.size();
    int guess     = lst[guess_ind];
    if( guess == num ) return guess_ind;

    if( guess < num ) low = ( low + dist ) % (int) lst.size();
    if( guess > num ) high = ( (int) lst.size() + high - dist ) % (int) lst.size();

    dist = dist / 2;
  }
}
#endif
