#pragma once

/* EASY
Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability, implement a function
rand7() that returns an integer from 1 to 7 (inclusive).
*/

#include <cstdlib>

inline int rand5() { return rand() % 5 + 1; }

inline int rand7()
{
  int r1 = rand5();
  int r2 = rand5();
  if( r2 <= 3 ) return r1;
  if( r2 == 4 )
  {
    if( r1 <= 3 ) return 6;
    else
      return rand7();
  }
  else
  {
    if( r1 <= 3 ) return 7;
    else
      return rand7();
  }
}