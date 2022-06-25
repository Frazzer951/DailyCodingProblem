#ifndef PROBLEMS_241_250_PROBLEM_241_HPP
#define PROBLEMS_241_250_PROBLEM_241_HPP


#pragma once

/* EASY
In academia, the h-index is a metric used to calculate the impact of a
researcher's papers. It is calculated as follows:

A researcher has index h if at least h of her N papers have h citations each. If
there are multiple h satisfying this formula, the maximum is chosen.

For example, suppose N = 5, and the respective citations of each paper are [4,
3, 0, 1, 5]. Then the h-index would be 3, since the researcher has 3 papers with
at least 3 citations.

Given a list of paper citations of a researcher, calculate their h-index.
*/
inline int hIndex( const int & n, const int citations[] )
{
  std::vector<int> counts( n );
  for( int i = 0; i < n; ++i )
  {
    for( int j = 0; j < citations[i]; ++j )
    {
      counts[j]++;
    }
  }
  int h = 0;
  for( int i = n - 1; i >= 0; --i )
  {
    if( counts[i] >= i + 1 )
    {
      h = i + 1;
      break;
    }
  }
  return h;
}
#endif
