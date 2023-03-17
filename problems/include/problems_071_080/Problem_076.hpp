#ifndef PROBLEMS_071_080_PROBLEM_076_HPP
#define PROBLEMS_071_080_PROBLEM_076_HPP

#pragma once

/* MEDIUM
You are given an N by M 2D matrix of lowercase letters. Determine the minimum
number of columns that can be removed to ensure that each row is ordered from
top to bottom lexicographically. That is, the letter at each column is
lexicographically later as you go down each row. It does not matter whether each
row itself is ordered lexicographically.

For example, given the following table:

cba
daf
ghi


This is not ordered because of the a in the center. We can remove the second
column to make it ordered:

ca
df
gi


So your function should return 1, since we only needed to remove 1 column.

As another example, given the following table:

abcdef


Your function should return 0, since the rows are already ordered (there's only
one row).

As another example, given the following table:

zyx
wvu
tsr


Your function should return 3, since we would need to remove all the columns to
order it.
*/
#include <vector>

inline int rows_to_remove( std::vector<std::string> arr ) {
  if ( arr.size() == 1 ) return 0;

  int count = 0;

  for ( int i = 0; i < arr.size(); i++ ) {
    for ( int j = 0; j < arr[0].size() - 1; j++ ) {
      char const a = arr[j][i];
      char const b = arr[j + 1][i];
      if ( a > b ) {
        count++;
        break;
      }
    }
  }
  return count;
}
#endif
