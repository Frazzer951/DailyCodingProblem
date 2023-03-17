#ifndef PROBLEMS_231_240_PROBLEM_234_HPP
#define PROBLEMS_231_240_PROBLEM_234_HPP

#pragma once

/* HARD
Recall that the minimum spanning tree is the subset of edges of a tree that
connect all its vertices with the smallest possible total edge weight. Given an
undirected graph with weighted edges, compute the maximum weight spanning tree.
*/
#include <algorithm>
#include <set>
#include <vector>

struct UndirectedGraph {
  int                                              n;
  std::vector<std::pair<std::pair<int, int>, int>> edges;
  UndirectedGraph( int n ) : n( n ) {}

  void add_edge( int u, int v, int w ) {
    edges.emplace_back( std::make_pair( u, v ), w );
    edges.emplace_back( std::make_pair( v, u ), w );
  }
};

struct DisjointSet {
  std::vector<int> parent;
  std::vector<int> sizes;
  DisjointSet( int n ) : parent( n ), sizes( n ) {
    for ( int i = 0; i < n; ++i ) {
      parent[i] = i;
      sizes[i]  = 1;
    }
  }

  int find( int x ) {
    int root = x;
    if ( parent[root] != root ) root = parent[root];

    int step = x;
    while ( step != root ) {
      step         = parent[step];
      parent[step] = root;
    }
    return root;
  }

  void join( int v1, int v2 ) {
    int const s1 = find( v1 );
    int const s2 = find( v2 );

    int small = 0;
    int big   = 0;
    if ( sizes[s1] < sizes[s2] ) {
      small = s1;
      big   = s2;
    } else {
      small = s2;
      big   = s1;
    }
    parent[small] = big;
    sizes[big]    += sizes[small];
  }
};

inline std::set<std::pair<std::pair<int, int>, int>> max_spanning_tree( const UndirectedGraph &graph ) {
  std::set<std::pair<std::pair<int, int>, int>> tree;
  int const                                     n = graph.n;
  DisjointSet                                   ds( n );
  auto                                          edges = graph.edges;

  std::sort( edges.begin(), edges.end(), []( const auto &a, const auto &b ) { return a.second < b.second; } );

  for ( const auto &edge : edges ) {
    int const u = edge.first.first;
    int const v = edge.first.second;
    if ( ds.find( u ) != ds.find( v ) ) {
      tree.insert( edge );
      ds.join( u, v );
    }
  }

  return ( tree.size() == n - 1 ) ? tree : std::set<std::pair<std::pair<int, int>, int>>();
}
#endif
