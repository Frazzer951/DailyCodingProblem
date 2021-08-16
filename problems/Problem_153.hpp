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

int smallestWordDistance( std::string w1, std::string w2, std::vector<std::string> words )
{
  std::multimap<std::string, int> indecies;
  for( int i = 0; i < words.size(); i++ )
  {
    if( words[i] == w1 || words[i] == w2 ) { indecies.emplace( words[i], i ); }
  }
  int smallest = (int) words.size();

  auto w1_it = indecies.find( w1 );
  auto w2_it = indecies.find( w2 );

  std::vector<int> w1_indecies;
  std::vector<int> w2_indecies;

  while( w1_it != indecies.end() && w1_it->first == w1 )
  {
    w1_indecies.push_back( w1_it->second );
    w1_it++;
  }
  while( w2_it != indecies.end() && w2_it->first == w2 )
  {
    w2_indecies.push_back( w2_it->second );
    w2_it++;
  }

  for( int i = 0; i < w1_indecies.size(); i++ )
  {
    for( int j = 0; j < w2_indecies.size(); j++ )
    {
      int distance = std::abs( w1_indecies[i] - w2_indecies[j] ) - 1;
      smallest     = std::min( smallest, distance );
    }
  }

  return smallest;
}