#pragma once

/* HARD
Find an efficient algorithm to find the smallest distance (measured in number of words) between any two given words in a
string.

For example, given words "hello", and "world" and a text content of "dog cat hello cat dog dog hello cat world", return
1 because there's only one word "cat" in between the two words.
*/

#include <cmath>
#include <map>
#include <string>
#include <vector>

inline int smallestWordDistance( const std::string & w1, const std::string & w2, std::vector<std::string> words )
{
  std::multimap<std::string, int> indexes;
  for( int i = 0; i < words.size(); i++ )
  {
    if( words[i] == w1 || words[i] == w2 ) { indexes.emplace( words[i], i ); }
  }
  int smallest = (int) words.size();

  auto w1_it = indexes.find( w1 );
  auto w2_it = indexes.find( w2 );

  std::vector<int> w1_indexes;
  std::vector<int> w2_indexes;

  while( w1_it != indexes.end() && w1_it->first == w1 )
  {
    w1_indexes.push_back( w1_it->second );
    w1_it++;
  }
  while( w2_it != indexes.end() && w2_it->first == w2 )
  {
    w2_indexes.push_back( w2_it->second );
    w2_it++;
  }

  for( int w1_index : w1_indexes )
  {
    for( int w2_index : w2_indexes )
    {
      int distance = std::abs( w1_index - w2_index ) - 1;
      smallest     = std::min( smallest, distance );
    }
  }

  return smallest;
}