#ifndef PROBLEMS_211_220_PROBLEM_220_HPP
#define PROBLEMS_211_220_PROBLEM_220_HPP

#pragma once

/* MEDIUM
In front of you is a row of N coins, with values v1, v1, ..., vn.

You are asked to play the following game. You and an opponent take turns
choosing either the first or last coin from the row, removing it from the row,
and receiving the value of the coin.

Write a program that returns the maximum amount of money you can win with
certainty, if you move first, assuming your opponent plays optimally.
*/
#include <vector>

inline int max_profit_coin_game( std::vector<int> coins ) {
  int                           const n = coins.size();
  std::vector<std::vector<int>> profit( n, std::vector( n, 0 ) );

  for ( int i = 0; i < n; i++ ) profit[i][i] = coins[i];

  for ( int i = 0; i < n - 1; i++ ) profit[i][i + 1] = std::max( profit[i][i], profit[i + 1][i + 1] );

  for ( int gap = 2; gap < n; gap++ ) {
    for ( int i = 0; i < n - gap; i++ ) {
      int const j              = i + gap;
      int const left           = profit[i][j - 2];
      int const diagonal       = profit[i + 1][j - 1];
      int const bottom         = profit[i + 2][j];
      profit[i][i + gap] = std::max( coins[i] + std::min( diagonal, bottom ), coins[j] + std::min( left, diagonal ) );
    }
  }
  return profit[0][n - 1];
}
#endif
