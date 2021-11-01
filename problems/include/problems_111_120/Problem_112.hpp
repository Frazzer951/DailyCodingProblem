#ifndef PROBLEMS_111_120_PROBLEM_112_HPP
#define PROBLEMS_111_120_PROBLEM_112_HPP

#pragma once

/* HARD
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in
the tree. Assume that each node in the tree also has a pointer to its parent.

According to the definition of LCA on Wikipedia
[https://en.wikipedia.org/wiki/Lowest_common_ancestor]: �The lowest common
ancestor is defined between two nodes v and w as the lowest node in T that has
both v and w as descendants (where we allow a node to be a descendant of
itself).�
*/
#include <map>

struct pbtNode
{
  int       value;
  pbtNode * parent;
  pbtNode * left;
  pbtNode * right;

  pbtNode( int v, pbtNode * p = nullptr ) : value( v ), parent( p ), left( nullptr ), right( nullptr ) {}
};

inline pbtNode * pbtLCA( pbtNode * a, pbtNode * b )
{
  std::map<pbtNode *, bool> nodes;
  auto *                    cur = a->parent;
  while( cur != nullptr )
  {
    nodes[cur] = true;
    cur        = cur->parent;
  }
  cur = b->parent;
  while( cur != nullptr )
  {
    if( nodes[cur] ) return cur;
    cur = cur->parent;
  }
  return nullptr;
}
#endif
