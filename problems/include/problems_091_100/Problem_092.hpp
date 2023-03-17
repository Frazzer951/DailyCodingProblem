#ifndef PROBLEMS_091_100_PROBLEM_092_HPP
#define PROBLEMS_091_100_PROBLEM_092_HPP

#pragma once

/* HARD
We're given a hashmap associating each courseId key with a list of courseIds
values, which represents that the prerequisites of courseId are courseIds.
Return a sorted ordering of courses such that we can finish all courses.

Return null if there is no such ordering.

For example, given {'CSC300': ['CSC100', 'CSC200'], 'CSC200': ['CSC100'],
'CSC100': []}, should return ['CSC100', 'CSC200', 'CSCS300'].
*/
#include <algorithm>
#include <map>
#include <string>
#include <vector>

inline std::vector<std::string> course_order( std::map<std::string, std::vector<std::string>> course_dependencies ) {
  std::vector<std::string> courses;
  while ( !course_dependencies.empty() ) {
    for ( auto &[course, dependencies] : course_dependencies ) {
      if ( !dependencies.empty() ) {
        for ( const auto &dep_course : dependencies ) {
          if ( std::find( courses.begin(), courses.end(), dep_course ) == courses.end() ) { continue; }
        }
      }
      courses.push_back( course );
      course_dependencies.erase( course );
      break;
    }
  }
  return courses;
}
#endif
