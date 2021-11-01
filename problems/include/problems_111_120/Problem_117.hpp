#pragma once

/* EASY
Given a binary tree, return the level of the tree with minimum sum.
*/

#include <map>
#include <queue>

#include "btNode.hpp"

inline int minimum_level_sum( btNode<int> * root )
{
  std::queue<std::pair<btNode<int> *, int>> queue;
  queue.push( std::make_pair( root, 0 ) );
  std::map<int, int> level_to_sum;


  while( !queue.empty() )
  {
    auto & [node, level] = queue.front();
    queue.pop();
    level_to_sum[level] += node->value;

    if( node->right != nullptr ) queue.push( std::make_pair( node->right, level + 1 ) );

    if( node->left != nullptr ) queue.push( std::make_pair( node->left, level + 1 ) );
  }

  int min_level = 0;

  for( auto it : level_to_sum )
  {
    if( level_to_sum[it.first] < level_to_sum[min_level] ) min_level = it.first;
  }

  return min_level;
}