#pragma once

/* EASY
You are given a list of data entries that represent entries and exits of groups of people into a building. An entry
looks like this:

{"timestamp": 1526579928, count: 3, "type": "enter"}

This means 3 people entered the building. An exit looks like this:

{"timestamp": 1526580382, count: 2, "type": "exit"}

This means that 2 people exited the building. timestamp is in Unix time.

Find the busiest period in the building, that is, the time with the most people in the building. Return it as a pair of
(start, end) timestamps. You can assume the building always starts off and ends up empty, i.e. with 0 people inside.
*/

#include <algorithm>
#include <string>
#include <vector>

enum class Type { enter, exit };

struct Timelog
{
  long timestamp;
  int  count;
  Type type;
};

inline bool Timelog_sorter( Timelog const & lhs, Timelog const & rhs ) { return lhs.timestamp < rhs.timestamp; }

inline std::pair<long, long> busiest_period( std::vector<Timelog> entries )
{
  std::pair<long, long> period;
  int                   num_people     = 0;
  int                   max_num_people = 0;

  // Sort the entries by timestamp
  std::sort( entries.begin(), entries.end(), Timelog_sorter );

  // Keep track of the number of people at each entry.
  for( int i = 0; i < entries.size(); i++ )
  {
    Timelog entry = entries[i];
    if( entry.type == Type::enter ) num_people += entry.count;
    else
      num_people -= entry.count;

    if( num_people > max_num_people )
    {
      max_num_people = num_people;
      period         = { entry.timestamp, entries[i + 1].timestamp };
    }
  }
  return period;
}