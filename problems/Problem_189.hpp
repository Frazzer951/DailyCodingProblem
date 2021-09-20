#pragma once

/* EASY
Given an array of elements, return the length of the longest subarray where all its elements are distinct.

For example, given the array [5, 1, 3, 5, 2, 3, 4, 1], return 5 as the longest subarray of distinct elements is
[5, 2, 3, 4, 1].
*/

#include <map>
#include <vector>

inline int longestSubArray( std::vector<int> nums )
{
  int longest = 0;

  for( int i = 0; i < nums.size(); i++ )
  {
    if( nums.size() - i < longest ) break;
    std::map<int, bool> seen;
    bool                broke = false;
    for( int j = i; j < nums.size(); j++ )
    {
      if( seen[nums[j]] )
      {
        longest = std::max( longest, j - i );
        broke   = true;
        break;
      }
      seen[nums[j]] = true;
    }
    if( !broke ) longest = ( longest > nums.size() - i ) ? longest : nums.size() - i;
  }
  return longest;
}