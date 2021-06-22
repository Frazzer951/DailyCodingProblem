#pragma once

/* MEDIUM
Given an unsorted array of integers,
find the length of the longest consecutive
elements sequence.

For example, given [100, 4, 200, 1, 3, 2],
the longest consecutive element sequence is [1, 2, 3, 4].
Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include <unordered_set>
#include <vector>

int findLongestConseqSubseq( std::vector<int> arr )
{
  std::unordered_set<int> S;
  int                     ans = 0;
  int                     n   = (int) arr.size();

  // Hash all the array elements
  for( int i = 0; i < n; i++ )
    S.insert( arr[i] );

  // check each possible sequence from
  // the start then update optimal length
  for( int i = 0; i < n; i++ )
  {
    // if current element is the starting
    // element of a sequence
    if( S.find( arr[i] - 1 ) == S.end() )
    {
      // Then check for next elements
      // in the sequence
      int j = arr[i];
      while( S.find( j ) != S.end() )
        j++;

      // update  optimal length if
      // this length is more
      ans = std::max( ans, j - arr[i] );
    }
  }
  return ans;
}