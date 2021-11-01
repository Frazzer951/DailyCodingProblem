#ifndef PROBLEMS_061_070_PROBLEM_067_HPP
#define PROBLEMS_061_070_PROBLEM_067_HPP

#pragma once

/* HARD
Implement an LFU (Least Frequently Used) cache. It should be able to be
initialized with a cache size n, and contain the following methods:

 * set(key, value): sets key to value. If there are already n items in the cache
   and we are adding a new item, then it should also remove the least frequently
   used item. If there is a tie, then the least recently used key should be
   removed.
 * get(key): gets the value at key. If no such key exists, return null.

Each operation should run in O(1) time.
*/

#include <deque>
#include <map>
#include <string>

inline int get_deque_index( std::deque<std::string> dq, const std::string & value )
{
  for( int i = 0; i < dq.size(); i++ )
  {
    if( dq[i] == value ) return i;
  }
  return -1;
}

struct LFUCache
{
  int                                        capacity;
  std::map<std::string, std::pair<int, int>> val_map;
  std::map<int, std::deque<std::string>>     freq_map;
  int                                        min_freq = 0;

  LFUCache( int _capacity ) : capacity( _capacity ) {};

  int get( const std::string & key )
  {
    // If key doesn't exist, return None.
    if( val_map.find( key ) == val_map.end() ) return 0;


    // First, we look up the val and frequency in our val_map.
    auto & [val, freq] = val_map[key];

    // We need to then increment the frequency of our key,
    // so we'll take it out of the current bucket and put it
    // into the next frequency's bucket. If it was the last thing
    // in the current bucket and the lowest frequency, (e.g. 1 to 2),
    // then we'll make sure to update our min_freq so we can keep
    // track of what to evict.
    freq_map[freq].erase( freq_map[freq].begin() + get_deque_index( freq_map[freq], key ) );
    if( freq_map[freq].empty() )
    {
      if( min_freq == freq ) min_freq += 1;
    }

    // Update our dicts as usual.
    val_map[key] = std::make_pair( val, freq + 1 );
    freq_map[freq + 1].push_back( key );
    return val;
  }

  void set( const std::string & key, int val )
  {
    if( capacity == 0 ) return;

    if( val_map.find( key ) == val_map.end() )
    {
      // Evict the least frequently used key by popping left
      // from the lowest-frequency key, since it's ordered by
      // time (because we use append).
      if( val_map.size() >= capacity )
      {
        std::string to_evict = freq_map[min_freq].front();
        freq_map[min_freq].pop_front();
        val_map.erase( to_evict );
      }
      // Add our key to val_map and freq_map
      val_map[key] = std::make_pair( val, 1 );
      freq_map[1].push_back( key );
      min_freq = 1;
    }
    else
    {
      // Update the entry and increase the frequency of the key,
      // updating the minimum frequency if necessary.
      auto & [_, freq] = val_map[key];
      freq_map[freq].erase( freq_map[freq].begin() + get_deque_index( freq_map[freq], key ) );
      if( freq_map[freq].empty() )
      {
        if( freq == min_freq ) min_freq += 1;
      }

      val_map[key] = std::make_pair( val, freq + 1 );
      freq_map[freq + 1].push_back( key );
    }
  }
};
#endif
