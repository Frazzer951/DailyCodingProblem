#ifndef PROBLEMS_041_050_PROBLEM_047_HPP
#define PROBLEMS_041_050_PROBLEM_047_HPP

#pragma once

/* EASY
Given a array of numbers representing the stock prices of a company in
chronological order, write a function that calculates the maximum profit you
could have made from buying and selling that stock once. You must buy before you
can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could
buy the stock at 5 dollars and sell it at 10 dollars.
*/
#include <vector>

inline int max_profit( std::vector<int> prices ) {
  int profit = 0;
  for ( int i = 0; i < prices.size() - 1; i++ ) {
    for ( int j = i; j < prices.size(); j++ ) {
      if ( prices[j] - prices[i] > profit ) profit = prices[j] - prices[i];
    }
  }
  return profit;
}
#endif
