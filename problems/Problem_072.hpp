#pragma once

/* HARD
In a directed graph, each node is assigned an uppercase letter.
We define a path's value as the number of most frequently-occurring
letter along that path. For example, if a path in the graph goes
through "ABACA", the value of the path is 3, since there are 3
occurrences of 'A' on the path.

Given a graph with n nodes and m directed edges, return the largest
value path of the graph. If the largest value is infinite,
then return null.

The graph is represented with a string and an edge list. The i-th
character represents the uppercase letter of the i-th node.
Each tuple in the edge list (i, j) means there is a directed edge
from the i-th node to the j-th node. Self-edges are possible, as well as multi-edges.

For example, the following input graph:

ABACA
[(0, 1),
 (0, 2),
 (2, 3),
 (3, 4)]
Would have maximum value 3 using the path of vertices [0, 2, 3, 4], (A, A, C, A).

The following input graph:

A
[(0, 0)]
Should return null, since we have an infinite loop.
*/

#include <map>
#include <string>
#include <vector>

inline int pathScore( const std::string& path )
{
  std::map<char, int> counts;
  int                 max_count = 0;
  for( char c : path )
  {
    counts[c]++;
  }
  for( auto & [_, count] : counts )
  {
    max_count = ( count > max_count ) ? count : max_count;
  }
  return max_count;
}

inline int best_score( const std::vector<std::vector<int>>& paths, std::string nodes )
{
  int best_score = 0;
  for( const std::vector<int>& v : paths )
  {
    std::string path;
    for( int i : v )
    {
      if( i == -1 ) return -1;
      path += nodes[i];
    }
    int score  = pathScore( path );
    best_score = ( score > best_score ) ? score : best_score;
  }
  return best_score;
}

inline bool isLoop( const std::vector<int>& cur_path, int cur_index )
{
  for( int i : cur_path )
  {
    if( i == cur_index ) return true;
  }
  return false;
}

inline std::vector<std::vector<int>> follow_path( int index, std::map<int, std::vector<int>> edge_map, std::vector<int> cur_path = std::vector<int>() )
{
  if( edge_map[index].empty() ) return std::vector<std::vector<int>>( 1, std::vector<int>( 1, index ) );

  if( !cur_path.empty() && isLoop( cur_path, index ) ) return std::vector<std::vector<int>>( 1, std::vector<int>( 1, -1 ) );

  cur_path.push_back( index );

  std::vector<std::vector<int>> paths;

  for( int i = 0; i < edge_map[index].size(); i++ )
  {
    auto sub_paths = follow_path( edge_map[index][i], edge_map, cur_path );

    for( std::vector<int> path : sub_paths )
    {
      path.insert( path.begin(), index );
      paths.push_back( path );
    }
  }

  return paths;
}

inline int pathValue( const std::string& nodes, const std::vector<std::pair<int, int>>& edges )
{
  std::map<int, std::vector<int>> edge_map;

  for( auto & [from, to] : edges )
  {
    edge_map[from].push_back( to );
  }

  std::vector<std::vector<int>> paths;

  for( int i = 0; i < nodes.size(); i++ )
  {
    auto i_paths = follow_path( i, edge_map );

    for( const std::vector<int>& path : i_paths )
    {
      paths.push_back( path );
    }
  }

  return best_score( paths, nodes );
}