#ifndef PROBLEMS_251_260_PROBLEM_255_HPP
#define PROBLEMS_251_260_PROBLEM_255_HPP

#pragma once

/* EASY
The transitive closure of a graph is a measure of which vertices are reachable
from other vertices. It can be represented as a matrix M, where M[i][j] == 1 if
there is a path between vertices i and j, and otherwise 0.

For example, suppose we are given the following graph in adjacency list form:

graph = [
    [0, 1, 3],
    [1, 2],
    [2],
    [3]
]


The transitive closure of this graph would be:

[1, 1, 1, 1]
[0, 1, 1, 0]
[0, 0, 1, 0]
[0, 0, 0, 1]


Given a graph, find its transitive closure.
*/

#include <vector>

std::vector<std::vector<int>> transitiveClosure_helper( std::vector<std::vector<int>> graph )
{
  int                           n      = graph.size();
  std::vector<std::vector<int>> result = std::vector( n, std::vector( n, 0 ) );

  for( int i = 0; i < n; i++ )
  {
    for( int j = 0; j < n; j++ )
    {
      result[i][j] = graph[i][j];
    }
  }

  for( int k = 0; k < n; k++ )
  {
    for( int i = 0; i < n; i++ )
    {
      for( int j = 0; j < n; j++ )
      {
        result[i][j] = result[i][j] | ( result[i][k] && result[k][j] );
      }
    }
  }

  return result;
}

std::vector<std::vector<int>> transitiveClosure( std::vector<std::vector<int>> graph )
{
  int                           n     = graph.size();
  std::vector<std::vector<int>> links = std::vector( n, std::vector( n, 0 ) );

  for( int i = 0; i < n; i++ )
  {
    for( int connection : graph[i] )
    {
      links[i][connection] = 1;
    }
  }

  return transitiveClosure_helper( links );
}

#endif
