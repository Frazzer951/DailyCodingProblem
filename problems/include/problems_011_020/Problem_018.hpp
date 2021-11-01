#ifndef PROBLEMS_011_020_PROBLEM_018_HPP
#define PROBLEMS_011_020_PROBLEM_018_HPP

#pragma once

/* HARD
Given an array of integers and a number k, where 1 <= k <= length of the array,
compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7,
8, 8], since:

 * 10 = max(10, 5, 2)
 * 7 = max(5, 2, 7)
 * 8 = max(2, 7, 8)
 * 8 = max(7, 8, 7)

Do this in O(n) time and O(k) space. You can modify the input array in-place and
you do not need to store the results. You can simply print them out as you
compute them.
*/

#include <iostream>
#include <vector>

#include "Futils.hpp"

inline std::vector<int> compSubArrMax( std::vector<int> arr, int k )
{
  std::vector<int> returnVec;

  for( unsigned int i = 0; i + k <= arr.size(); ++i )
  {
    std::vector<int> subVec;
    subVec.reserve( k );
    for( int j = 0; j < k; ++j ) { subVec.push_back( arr[j + i] ); }
    returnVec.push_back( getIntVecMax( subVec ) );
  }

  return returnVec;
}

inline int prob_18()
{
  std::cout << "\nProblem 18\n";

  auto vec = compSubArrMax( { 10, 5, 2, 7, 8, 7 }, 3 );

  std::cout << "The max values for each sub-array or [10, 5, 2, 7, 8, 7] is " << intVecToStr( vec ) << '\n';

  return 0;
}
#endif
