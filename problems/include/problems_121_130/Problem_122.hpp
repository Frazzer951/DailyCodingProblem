#ifndef PROBLEMS_121_130_PROBLEM_122_HPP
#define PROBLEMS_121_130_PROBLEM_122_HPP

#pragma once

/* MEDIUM
You are given a 2-d matrix where each cell represents number of coins in that
cell. Assuming we start at matrix[0][0], and can only move right or down, find
the maximum number of coins you can collect by the bottom right corner.

For example, in this matrix

0 3 1 1
2 0 0 4
1 5 3 1


The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.
*/

#include <vector>

inline int maxCoins( std::vector<std::vector<int>> coins )
{
  std::vector<std::vector<int>> counts( coins.size() + 1, std::vector( coins[0].size() + 1, 0 ) );
  for( int i = 0; i < counts.size(); i++ )
  {
    for( int j = 0; j < counts[0].size(); j++ )
    {
      if( i == 0 || j == 0 )
      {
        counts[i][j] = 0;
        continue;
      }
      counts[i][j] = std::max( counts[i - 1][j], counts[i][j - 1] ) + coins[i - 1][j - 1];
    }
  }
  return counts[counts.size() - 1][counts[0].size() - 1];
}
#endif
