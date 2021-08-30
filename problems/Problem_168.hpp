#pragma once

/* MEDIUM
Given an N by N matrix, rotate it by 90 degrees clockwise.

For example, given the following matrix:

[[1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]]
you should return:

[[7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]]
Follow-up: What if you couldn't use any extra space?
*/

#include <vector>

inline std::vector<std::vector<int>> rotate90( std::vector<std::vector<int>> arr )
{
  std::vector<std::vector<int>> rotated( arr.size(), std::vector( arr[0].size(), 0 ) );

  for( int i = 0; i < arr.size(); i++ )
  {
    for( int j = 0; j < arr[i].size(); j++ ) { rotated[j][arr.size() - i - 1] = arr[i][j]; }
  }
  return rotated;
}