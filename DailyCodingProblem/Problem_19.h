#pragma once

/* MEDIUM
A builder is looking to build a row of N houses that can be of K
different colors. He has a goal of minimizing cost while ensuring that
no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents
the cost to build the nth house with kth color, return the minimum cost
which achieves this goal.
*/

#include <vector>

#include "FUtils.h"

int build_houses( std::vector<std::vector<int>> matrix )
{
  int              k = matrix[0].size();
  std::vector<int> soln_row( k, 0 );

  for( auto row : matrix )
  {
    std::vector<int> new_row;
    for( unsigned int i = 0; i < row.size(); ++i ) { new_row.push_back( getIntVecMin( soln_row, i ) + row[i] ); }
    soln_row = new_row;
  }
  return getIntVecMin( soln_row );
}