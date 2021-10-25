#pragma once

/* EASY
Let's define a "sevenish" number to be one which is either a power of 7, or the
sum of unique powers of 7. The first few sevenish numbers are 1, 7, 8, 49, and
so on. Create an algorithm to find the nth sevenish number.
*/

#include <cmath>

inline int nthSevenish( int n )
{
  int answer   = 0;
  int bitPlace = 0;
  while( n > 0 )
  {
    if( n & 1 ) { answer += pow( 7, bitPlace ); }
    n >>= 1;
    bitPlace++;
  }
  return answer;
}