#pragma once

/* MEDIUM
Given a list of integers and a number K,
return which contiguous elements of the list sum to K.

For example, if the list is [1, 2, 3, 4, 5] and K is 9,
then it should return [2, 3, 4], since 2 + 3 + 4 = 9.
*/

#include <vector>

inline std::vector<int> continuousSum( std::vector<int> nums, int k )
{
  if( nums.size() == 1 ) return { k };

  int left  = 0;
  int right = 1;
  int sum   = nums[left] + nums[right];

  while( sum != k )
  {
    if( sum > k )
    {
      sum -= nums[left];
      left++;
    }
    else
    {
      right++;
      sum += nums[right];
    }
  }
  return std::vector<int>( nums.begin() + left, nums.begin() + right + 1 );
}