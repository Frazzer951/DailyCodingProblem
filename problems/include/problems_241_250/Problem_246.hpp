#ifndef PROBLEMS_241_250_PROBLEM_246_HPP
#define PROBLEMS_241_250_PROBLEM_246_HPP

#pragma once

/* MEDIUM
Given a list of words, determine whether the words can be chained to form a
circle. A word X can be placed in front of another word Y in a circle if the
last character of X is same as the first character of Y.

For example, the words ['chair', 'height', 'racket', 'touch', 'tunic'] can form
the following circle: chair --> racket --> touch --> height --> tunic --> chair.
*/

#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

inline std::set<char> find_component( std::map<char, std::vector<char>> graph, std::set<char> visited,
                                      char current_word )
{
  visited.insert( current_word );

  for( auto neighbor : graph[current_word] )
  {
    if( visited.find( neighbor ) == visited.end() ) { find_component( graph, visited, neighbor ); }
  }

  return visited;
}

inline bool is_connected( std::map<char, std::vector<char>> graph )
{
  char           start     = graph.begin()->first;
  std::set<char> component = find_component( graph, std::set<char>(), start );

  std::map<char, std::vector<char>> reversed_graph;
  for( auto & [key, values] : graph )
  {
    for( auto v : values ) { reversed_graph[v].push_back( key ); }
  }
  std::set<char> reversed_component = find_component( graph, std::set<char>(), start );
  return component == reversed_component;
}


inline bool are_degrees_equal( const std::map<char, std::vector<char>> & graph )
{
  std::map<char, int> in_degree;
  std::map<char, int> out_degree;

  for( const auto & [key, values] : graph )
  {
    for( auto v : values )
    {
      out_degree[key]++;
      in_degree[v]++;
    }
  }

  return in_degree == out_degree;
}

inline std::map<char, std::vector<char>> make_graph( const std::vector<std::string> & words )
{
  std::map<char, std::vector<char>> graph;
  for( auto word : words ) { graph[word[0]].push_back( word[word.size() - 1] ); }
  return graph;
}

inline bool can_chain( const std::vector<std::string> & words )
{
  std::map<char, std::vector<char>> graph         = make_graph( words );
  bool                              degrees_equal = are_degrees_equal( graph );
  bool                              connected     = is_connected( graph );

  return degrees_equal && connected;
}
#endif
