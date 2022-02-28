#ifndef PROBLEMS_141_150_PROBLEM_143_HPP
#define PROBLEMS_141_150_PROBLEM_143_HPP


#pragma once

/* MEDIUM
Given a pivot x, and a list lst, partition the list into three parts.

 * The first part contains all elements in lst that are less than x
 * The second part contains all elements in lst that are equal to x
 * The third part contains all elements in lst that are larger than x

Ordering within a part can be arbitrary.

For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may
be [9, 3, 5, 10, 10, 12, 14].
*/
#include <vector>

inline std::vector<int> partition( const std::vector<int> & lst, int x )
{
  std::vector<int> less;
  std::vector<int> eq;
  std::vector<int> great;

  for( int i : lst )
  {
    if( i < x ) { less.push_back( i ); }
    else if( i == x )
    {
      eq.push_back( i );
    }
    else
    {
      great.push_back( i );
    }
  }
  less.insert( less.end(), eq.begin(), eq.end() );
  less.insert( less.end(), great.begin(), great.end() );

  return less;
}
#endif
