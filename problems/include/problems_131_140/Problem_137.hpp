#ifndef PROBLEMS_131_140_PROBLEM_137_HPP
#define PROBLEMS_131_140_PROBLEM_137_HPP

#pragma once

/* MEDIUM
Implement a bit array.

A bit array is a space efficient array that holds a value of 1 or 0 at each
index.

 * init(size): initialize the array with size
 * set(i, val): updates index at i with val where val is either 1 or 0.
 * get(i): gets the value at index i.
*/

class bitarray
{
  bool * arr;

public:
  bitarray( const int & size ) : arr( new bool[size] )
  {
    for( int i = 0; i < size; i++ ) arr[i] = false;
  }
  void set( std::size_t i, bool val ) { arr[i] = val; }
  bool get( std::size_t i ) { return arr[i]; }
};
#endif
