#ifndef PROBLEMS_061_070_PROBLEM_070_HPP
#define PROBLEMS_061_070_PROBLEM_070_HPP

#pragma once

/* EASY
A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.
*/
#include <string>

inline int perfecet_num( int n ) {
  std::string n_str  = std::to_string( n );
  int const   length = (int) n_str.size();
  int         sum    = 0;

  for ( int i = 0; i < length; i++ ) { sum += (int) n_str[i] - 48; }

  if ( sum == 10 ) return n;

  int const needed = 10 - sum;
  n_str            += std::to_string( needed );

  return ( perfecet_num( std::stoi( n_str ) ) );
}
#endif
