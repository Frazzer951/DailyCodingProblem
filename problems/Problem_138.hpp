#pragma once

/* HARD
Find the minimum number of coins required to make n cents.

You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.

For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.
*/

#include <vector>

inline int minimum_coins( int n )
{
  int DENOMINATIONS[] = { 1, 5, 10, 25 };

  if( n == 0 ) return 0;
  for( int d : DENOMINATIONS )
  {
    if( n == d ) return 1;
  }
  int min = 1 + minimum_coins( n - DENOMINATIONS[0] );
  for( int d : DENOMINATIONS )
  {
    if( ( n - d ) >= 0 )
    {
      int temp = 1 + minimum_coins( n - d );
      min      = std::min( min, temp );
    }
  }
  return min;
}