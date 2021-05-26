#pragma once

/* EASY
The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
*/

/* Own solution, Only works if set had 3 items
std::vector<std::vector<int>> getPowderSet( std::vector<int> set )
{
  std::vector<std::vector<int>> powerSet = { {} };

  for( int val : set ) { powerSet.push_back( { val } ); }

  for( int i = 0; i < set.size() - 1; i++ )
  {
    for( int j = i + 1; j < set.size(); j++ ) { powerSet.push_back( { set[i], set[j] } ); }
  }

  powerSet.push_back( set );

  return powerSet;
}
*/

#include <math.h>
#include <vector>

// Internet Solution from GeeksForGeeks
std::vector<std::vector<int>> getPowderSet( std::vector<int> set )
{
  std::vector<std::vector<int>> powerSet;
  // set_size of power set of a set with set_size n is (2**n -1)
  unsigned int pow_set_size = (unsigned int) pow( 2, set.size() );
  unsigned int counter, j;

  // Run from counter 000..0 to 111..1
  for( counter = 0; counter < pow_set_size; counter++ )
  {
    std::vector<int> subset;
    for( j = 0; j < set.size(); j++ )
    {
      // Check if jth bit in the counter is set. If set then print jth element from set
      if( counter & ( 1 << j ) ) subset.push_back( set[j] );
    }
    powerSet.push_back( subset );
  }
  // std::sort( powerSet.begin(), powerSet.end() );
  return powerSet;
}
