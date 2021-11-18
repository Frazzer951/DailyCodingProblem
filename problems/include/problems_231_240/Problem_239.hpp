#ifndef PROBLEMS_231_240_PROBLEM_239_HPP
#define PROBLEMS_231_240_PROBLEM_239_HPP

#pragma once

/* MEDIUM
One way to unlock an Android phone is through a pattern of swipes across a 1-9
keypad.

For a pattern to be valid, it must satisfy the following:

 * All of its keys must be distinct.
 * It must not connect two keys by jumping over a third key, unless that key has
   already been used.

For example, 4 - 2 - 1 - 7 is a valid pattern, whereas 2 - 1 - 7 is not.

Find the total number of valid unlock patterns of length N, where 1 <= N <= 9.
*/

#include <map>
#include <set>

inline int num_paths( int current, std::map<std::pair<int, int>, int> jumps, std::set<int> & visited, int n )
{
  if( n - 1 == 0 ) return 1;

  int path = 0;
  for( int next_number = 1; next_number < 10; next_number++ )
  {
    if( visited.find( next_number ) == visited.end() )
    {
      if( jumps.find( { current, next_number } ) == jumps.end()
          || visited.find( jumps[{ current, next_number }] ) != visited.end() )
      {
        visited.insert( next_number );
        path += num_paths( next_number, jumps, visited, n - 1 );
        visited.erase( next_number );
      }
    }
  }
  return path;
}

inline int unlock_combinations( int n )
{
  std::map<std::pair<int, int>, int> jumps = { { { 1, 3 }, 2 }, { { 1, 7 }, 4 }, { { 1, 9 }, 5 }, { { 2, 8 }, 5 },
                                               { { 3, 1 }, 2 }, { { 3, 7 }, 5 }, { { 3, 9 }, 6 }, { { 4, 6 }, 5 },
                                               { { 6, 4 }, 5 }, { { 7, 1 }, 4 }, { { 7, 3 }, 5 }, { { 7, 9 }, 8 },
                                               { { 8, 2 }, 5 }, { { 9, 1 }, 5 }, { { 9, 3 }, 6 }, { { 9, 7 }, 8 } };
  std::set<int> v1 = {1};
  std::set<int> v2 = {2};
  std::set<int> v5 = {5};
  return 4 * num_paths( 1, jumps, v1, n ) + 4 * num_paths( 2, jumps, v2, n )
       + 1 * num_paths( 5, jumps, v5, n );
}

#endif
