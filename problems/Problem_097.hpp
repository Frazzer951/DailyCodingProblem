#pragma once

/* MEDIUM
Write a map implementation with a get function that lets you
retrieve the value of a key at a particular time.

It should contain the following methods:

set(key, value, time): sets key to value for t = time.
get(key, time): gets the key at t = time.
The map should work like this. If we set a key at a particular time,
it will maintain that value forever or until it gets set at a later
time. In other words, when we get a key at a time, it should return
the value that was set for that key set at the most recent time.

Consider the following examples:

d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 2) # set key 1 to value 2 at time 2
d.get(1, 1) # get key 1 at time 1 should be 1
d.get(1, 3) # get key 1 at time 3 should be 2
d.set(1, 1, 5) # set key 1 to value 1 at time 5
d.get(1, 0) # get key 1 at time 0 should be null
d.get(1, 10) # get key 1 at time 10 should be 1
d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 0) # set key 1 to value 2 at time 0
d.get(1, 0) # get key 1 at time 0 should be 2
*/

#include <map>
#include <vector>

inline std::size_t bisect_left( std::vector<int> a, int x )
{
  for( std::size_t i = 0; i < a.size(); i++ )
  {
    if( a[i] >= x ) return i;
  }
  return a.size();
}

class TimeMap
{
  std::vector<int> keys;
  std::vector<int> values;

public:
  int get( int key )
  {
    if( keys.empty() )
      return 0;
    std::size_t i = bisect_left( keys, key );
    if( keys.size() == i )
      return values[i - 1];
    if( keys[i] == key )
      return values[i];
    if( i == 0 )
      return 0;
    else
      return values[i - 1];
  }

  void set( int key, int value )
  {
    std::size_t i = bisect_left( keys, key );
    if( keys.size() == i )
    {
      keys.push_back( key );
      values.push_back( value );
    }
    else if( keys[i] == key )
      values[i] = value;
    else
    {
      keys.insert( keys.begin() + i + 1, key );
      values.insert( values.begin() + i + 1, value );
    }
  }
};

class MultiTimeMap
{
  std::map<int, TimeMap> map;

public:
  void set( int key, int value, int time )
  {
    map[key].set( time, value );
  }

  int get( int key, int time )
  {
    TimeMap time_map = map[key];
    return time_map.get( time );
  }
};