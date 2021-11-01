#ifndef PROBLEMS_131_140_PROBLEM_134_HPP
#define PROBLEMS_131_140_PROBLEM_134_HPP

#pragma once

/* EASY
You have a large array with most of the elements as zero.

Use a more space-efficient data structure, SparseArray, that implements the same
interface:

 * init(arr, size): initialize with the original large array and size.
 * set(i, val): updates index at i with val.
 * get(i): gets the value at index i.
*/

#include <map>

class SparseArray
{
  std::map<int, int> values;

public:
  void init( const int arr[], int size )
  {
    for( int i = 0; i < size; i++ )
    {
      if( arr[i] != 0 ) { values[i] = arr[i]; }
    }
  }
  void set( int i, int val ) { values[i] = val; }

  int get( int i ) { return values[i]; }
};
#endif
