#pragma once

/* HARD
Given an array of integers, find the first missing positive integer in linear time and constant space.
In other words, find the lowest positive integer that does not exist in the array.
The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
*/

#include <algorithm>
#include <iostream>

int findMissingPositive( int arr[], int size )
{
  std::sort( arr, arr + size );

  int missing = 1;

  for( auto i = 0; i < size; ++i )
  {
    if( arr[i] > 0 && arr[i] == missing ) { missing++; }
  }
  return missing;
}

void testArray( int arr[], int size )
{
  std::cout << "For the array: ";
  for( int i = 0; i < size; ++i ) { std::cout << arr[i] << ' '; }
  int missing = findMissingPositive( arr, size );
  std::cout << " the missing number is " << missing << '\n';
}

int prob_4()
{
  std::cout << "\nProblem 4:\n";

  int arr[] = { 3, 4, -1, 1 };
  testArray( arr, 4 );

  int arr2[] = { 1, 2, 0 };
  testArray( arr2, 3 );

  return 0;
}