#pragma once

/* EASY
Using a function rand7() that returns an integer from 1 to 7 (inclusive)
with uniform probability, implement a function rand5() that returns an
integer from 1 to 5 (inclusive).
*/

#include <cstdlib>

namespace prob71
{
  inline int rand7() { return rand() % 7 + 1; }

  inline int rand5()
  {
    int r = rand7();
    if( r >= 1 && r <= 5 ) return r;
    return rand5();
  }
}    // namespace prob71