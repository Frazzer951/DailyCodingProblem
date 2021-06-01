#pragma once

/* EASY
Given a list of possibly overlapping intervals,
return a new list of intervals where all
overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)],
you should return [(1, 3), (4, 10), (20, 25)].
*/

#include <vector>

inline std::vector<std::pair<int, int>> get_overlaping( std::pair<int, int> interval, std::vector<std::pair<int, int>> intervals )
{
  std::vector<std::pair<int, int>> overlaping;

  for( std::pair<int, int> cur_interval : intervals )
  {
    if( interval == cur_interval ) continue;

    if( ( interval.first > cur_interval.first && interval.first < cur_interval.second )
        || ( interval.second > cur_interval.first && interval.second < cur_interval.second )
        || ( cur_interval.first > interval.first && cur_interval.first < interval.second )
        || ( cur_interval.second > interval.first && cur_interval.second < interval.second )
        || ( interval.first < cur_interval.first && interval.second > cur_interval.second ) )
    {
      overlaping.push_back( cur_interval );
    }
  }
  return overlaping;
}

inline std::vector<std::pair<int, int>> merge_overlaping_intervals( std::vector<std::pair<int, int>> intervals )
{
  std::vector<std::pair<int, int>> merged;

  while( !intervals.empty() )
  {
    auto cur_interval = intervals[0];
    intervals.erase( std::find( intervals.begin(), intervals.end(), cur_interval ) );
    while( true )
    {
      auto overlap = get_overlaping( cur_interval, intervals );
      if( overlap.empty() )
      {
        merged.push_back( cur_interval );
        break;
      }
      int min = cur_interval.first;
      int max = cur_interval.second;
      for( auto interval : overlap )
      {
        min = ( interval.first < min ) ? interval.first : min;
        max = ( interval.second > max ) ? interval.second : max;
        intervals.erase( std::find( intervals.begin(), intervals.end(), interval ) );
      }
      cur_interval = std::make_pair( min, max );
    }
  }
  return merged;
}