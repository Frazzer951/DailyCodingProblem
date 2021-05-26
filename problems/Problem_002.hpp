#pragma once

/* HARD
Given an array of integers, return a new array such that each element at index i of the new array is the product of all
the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3,
2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <iostream>
#include <string>
#include <vector>

inline std::vector<int> sumArray( std::vector<int> arr )
{
  std::vector<int> sum;
  for( unsigned int i = 0; i < arr.size(); ++i )
  {
    int runningSum = 1;
    for( unsigned int j = 0; j < arr.size(); ++j )
    {
      if( j != i ) runningSum *= arr[j];
    }
    sum.push_back( runningSum );
  }
  return sum;
}

inline std::string vectorToString( std::vector<int> const & v )
{
  std::string str;
  for(int i : v) str += std::to_string( i ) + " ";
  return str;
}

inline void checkArray( std::vector<int> const & v )
{
  std::vector<int> sumedArray = sumArray( v );

  std::cout << "The array [ " << vectorToString( v ) << "] summed to [ " << vectorToString( sumedArray ) << "]\n";
}

inline int prob_2()
{
  std::cout << "\nProblem 2:\n";

  checkArray( { 1, 2, 3, 4, 5 } );
  checkArray( { 3, 2, 1 } );

  return 0;
}