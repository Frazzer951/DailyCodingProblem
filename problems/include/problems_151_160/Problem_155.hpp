#pragma once

/* MEDIUM
Given a list of elements, find the majority element, which appears more than
half the time (> floor(len(lst) / 2.0)).

You can assume that such element exists.

For example, given [1, 2, 1, 1, 3, 4, 0], return 1.
*/

#include <algorithm>
#include <map>
#include <vector>

inline int majority( const std::vector<int> & elements )
{
  std::map<int, int> element_to_count;
  for( auto element : elements ) element_to_count[element] += 1;

  // Find the element with most count
  return std::max_element( element_to_count.begin(), element_to_count.end(),
                           []( const auto & p1, const auto & p2 ) { return p1.second < p2.second; } )
      ->first;
}