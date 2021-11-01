#ifndef PROBLEMS_121_130_PROBLEM_130_HPP
#define PROBLEMS_121_130_PROBLEM_130_HPP

#pragma once

/* MEDIUM
Given an array of numbers representing the stock prices of a company in
chronological order and an integer k, return the maximum profit you can make
from k buys and sells. You must buy the stock before you can sell it, and you
must sell the stock before you can buy it again.

For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.
*/

#include <vector>

inline int stonks( std::vector<int> stocks, int k )
{
  int curLow    = 0;
  int curHigh   = 0;
  int profit    = 0;
  int highIndex = 0;
  int lowIndex  = 0;

  while( k != 0 )
  {
    curLow = stocks[highIndex];
    for( int i = highIndex + 1; i < stocks.size(); i++ )
    {
      if( stocks[i] < curLow )
      {
        curLow   = stocks[i];
        lowIndex = i;
      }
      else
        break;
    }

    curHigh = stocks[lowIndex];
    for( int i = lowIndex + 1; i < stocks.size(); i++ )
    {
      if( stocks[i] > curHigh )
      {
        curHigh   = stocks[i];
        highIndex = i;
      }
      else
        break;
    }
    profit += curHigh - curLow;
    k--;
  }

  return profit;
}
#endif
