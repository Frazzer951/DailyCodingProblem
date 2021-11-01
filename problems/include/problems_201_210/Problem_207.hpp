#ifndef PROBLEMS_201_210_PROBLEM_207_HPP
#define PROBLEMS_201_210_PROBLEM_207_HPP

#pragma once

/* MEDIUM
Given an undirected graph G, check whether it is bipartite. Recall that a graph
is bipartite if its vertices can be divided into two independent sets, U and V,
such that no edge connects vertices of the same set.
*/

#include <map>
#include <queue>
#include <vector>

inline bool helper( std::map<int, std::vector<int>> graph, int start, std::vector<int> & colors )
{
  std::queue<int> queue;
  queue.push( start );
  colors[start] = 1;
  while( !queue.empty() )
  {
    int vertex = queue.front();
    queue.pop();

    for( int neighbor : graph[vertex] )
    {
      if( colors[neighbor] == 0 )
      {
        colors[neighbor] = -colors[vertex];
        queue.push( neighbor );
      }
      else if( colors[neighbor] == colors[vertex] )
        return false;
    }
  }
  return true;
}

inline bool is_bipartite( const std::map<int, std::vector<int>> & graph )
{
  std::vector<int> colors( graph.size(), 0 );
  for( const auto & node : graph )
  {
    if( colors[node.first] == 0 )
    {
      if( !helper( graph, node.first, colors ) ) return false;
    }
  }
  return true;
}

#endif
