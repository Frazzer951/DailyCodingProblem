#pragma once

/* MEDIUM
Given a pivot x, and a list lst, partition the list into three parts.

The first part contains all elements in lst that are less than x
The second part contains all elements in lst that are equal to x
The third part contains all elements in lst that are larger than x
Ordering within a part can be arbitrary.

For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].
*/

#include <vector>

inline std::vector<int> partition( std::vector<int> lst, int x )
{
  std::vector<int> less;
  std::vector<int> eq;
  std::vector<int> great;

  for( int i = 0; i < lst.size(); i++ )
  {
    if( lst[i] < x ) { less.push_back( lst[i] ); }
    else if( lst[i] == x )
    {
      eq.push_back( lst[i] );
    }
    else
    {
      great.push_back( lst[i] );
    }
  }
  less.insert( less.end(), eq.begin(), eq.end() );
  less.insert( less.end(), great.begin(), great.end() );

  return less;
}