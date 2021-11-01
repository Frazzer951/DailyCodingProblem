#ifndef PROBLEMS_211_220_PROBLEM_217_HPP
#define PROBLEMS_211_220_PROBLEM_217_HPP

#pragma once

/* HARD
We say a number is sparse if there are no adjacent ones in its binary
representation. For example, 21 (10101) is sparse, but 22 (10110) is not. For a
given input N, find the smallest sparse number greater than or equal to N.

Do this in faster than O(N log N) time.
*/

inline bool isSparse( int x )
{
  bool last = false;
  for( int i = 0; i < 32; i++ )
  {
    bool bit = ( x & ( 1 << i ) ) != 0;
    if( bit && last ) return false;
    last = bit;
  }
  return true;
}

inline int nextSparse( int x )
{
  while( !isSparse( x ) ) { x++; }
  return x;
}
#endif
