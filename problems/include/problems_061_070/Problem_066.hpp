#ifndef PROBLEMS_061_070_PROBLEM_066_HPP
#define PROBLEMS_061_070_PROBLEM_066_HPP

#pragma once

/* MEDIUM
Assume you have access to a function toss_biased() which returns 0 or 1 with a
probability that's not 50-50 (but also not 0-100 or 100-0). You do not know the
bias of the coin.

Write a function to simulate an unbiased coin toss.
*/
inline bool toss_biased() {
  int const BIAS     = 66;
  int const rand_num = rand() % 100 + 1;
  return rand_num > BIAS;
}

inline bool toss_fair() {
  bool const t1 = toss_biased();
  bool const t2 = toss_biased();

  if ( t1 && !t2 ) return true;
  if ( !t1 && t2 ) return false;

  return toss_fair();
}
#endif
