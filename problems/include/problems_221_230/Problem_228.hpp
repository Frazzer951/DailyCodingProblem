#ifndef PROBLEMS_221_230_PROBLEM_228_HPP
#define PROBLEMS_221_230_PROBLEM_228_HPP


#pragma once

/* MEDIUM
Given a list of numbers, create an algorithm that arranges them in order to form
the largest possible integer. For example, given [10, 7, 76, 415], you should
return 77641510.
*/
#include <algorithm>
#include <string>
#include <vector>

inline int largest_possible_arrangement( std::vector<int> numbers )
{
  // sort the numbers by their most significant digit
  std::sort( numbers.begin(), numbers.end(),
             []( int a, int b ) { return std::to_string( a )[0] > std::to_string( b )[0]; } );
  int result = 0;
  for( auto & number : numbers )
  {
    result *= (int) pow( 10, std::to_string( number ).size() );
    result += number;
  }
  return result;
}
#endif
