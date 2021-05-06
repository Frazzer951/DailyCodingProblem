#pragma once

#include <algorithm>
#include <vector>

/* EASY
Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the
list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2
1.5
2
3.5
2
2
2
*/

std::vector<double> runningMedian( std::vector<double> v )
{
  std::vector<double> medians;
  std::vector<double> running;

  for( int i = 0; i < v.size(); i++ )
  {
    running.push_back( v[i] );
    std::sort( running.begin(), running.end() );

    size_t middle = running.size() / 2;
    if( running.size() % 2 == 0 ) { medians.push_back( ( running[middle - 1] + running[middle] ) / 2.0 ); }
    else
    {
      medians.push_back( running[middle] );
    }
  }
  return medians;
}