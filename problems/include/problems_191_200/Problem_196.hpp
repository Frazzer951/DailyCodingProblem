#ifndef PROBLEMS_191_200_PROBLEM_196_HPP
#define PROBLEMS_191_200_PROBLEM_196_HPP


#pragma once

/* EASY
Given the root of a binary tree, find the most frequent subtree sum. The subtree
sum of a node is the sum of all values under a node, including the node itself.

For example, given the following tree:

  5
 / \
2  -5


Return 2 as it occurs twice: once as the left leaf, and once as the sum of 2 + 5
- 5.
*/
#include <functional>
#include <map>

#include "btNode.hpp"

inline int frequen_subtree_sum( btNode<int> * root )
{
  if( root == nullptr ) return 0;

  std::map<int, int> counter;

  std::function<int( btNode<int> * )> getSubTreeSum = [&]( btNode<int> * node )
  {
    if( node == nullptr ) return 0;
    int s = node->value + getSubTreeSum( node->left ) + getSubTreeSum( node->right );
    counter[s]++;
    return s;
  };

  getSubTreeSum( root );
  auto max = std::max_element( counter.begin(), counter.end(),
                               []( const std::pair<int, int> & p1, const std::pair<int, int> & p2 )
                               { return p1.second < p2.second; } );
  return max->first;
}
#endif
