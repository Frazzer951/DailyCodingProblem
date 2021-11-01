#ifndef PROBLEMS_181_190_PROBLEM_182_HPP
#define PROBLEMS_181_190_PROBLEM_182_HPP

#pragma once

/* MEDIUM
A graph is minimally-connected if it is connected and there is no edge that can
be removed while still leaving the graph connected. For example, any binary tree
is minimally-connected.

Given an undirected graph, check if the graph is minimally-connected. You can
choose to represent the graph as either an adjacency matrix or adjacency list.
*/

#include <map>
#include <vector>

struct gNode
{
  int                  val;
  std::vector<gNode *> connections;
};

inline bool isMinConHelper( gNode * node, gNode * cameFrom, std::map<gNode *, bool> & visited )
{
  if( visited[node] ) return false;

  visited[node] = true;

  for( gNode * n : node->connections )
  {
    if( n == cameFrom ) continue;
    if( !isMinConHelper( n, node, visited ) ) { return false; }
  }
  return true;
}

inline bool isMinimallyConnected( gNode * node )
{
  std::map<gNode *, bool> visited;
  return isMinConHelper( node, nullptr, visited );
}
#endif
