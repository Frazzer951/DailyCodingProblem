#ifndef PROBLEMS_021_030_PROBLEM_021_HPP
#define PROBLEMS_021_030_PROBLEM_021_HPP

#pragma once

/* EASY
Given an array of time intervals (start, end) for classroom lectures (possibly
overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/
#include <vector>

inline int findMinRoomsNeeded( std::vector<std::pair<int, int>> schedule ) {
  if ( schedule.empty() ) return 0;
  std::vector<std::pair<int, int>> conflictingLecture;

  auto curClass = schedule[0];
  for ( unsigned int i = 1; i < schedule.size(); ++i ) {
    auto comClass = schedule[i];
    if ( ( curClass.first >= comClass.first && curClass.first < comClass.second )
         || ( curClass.second > comClass.first && curClass.second <= comClass.second )
         || ( curClass.first < comClass.first && curClass.second > comClass.second ) ) {
      conflictingLecture.push_back( schedule[i] );
    }
  }

  return 1 + findMinRoomsNeeded( conflictingLecture );
}
#endif
