#ifndef PROBLEMS_211_220_PROBLEM_215_HPP
#define PROBLEMS_211_220_PROBLEM_215_HPP


#pragma once

/* MEDIUM
The horizontal distance of a binary tree node describes how far left or right
the node will be when the tree is printed out.

More rigorously, we can define it as follows:

 * The horizontal distance of the root is 0.
 * The horizontal distance of a left child is hd(parent) - 1.
 * The horizontal distance of a right child is hd(parent) + 1.

For example, for the following tree, hd(1) = -2, and hd(6) = 0.

             5
          /     \
        3         7
      /  \      /   \
    1     4    6     9
   /                /
  0                8


The bottom view of a tree, then, consists of the lowest node at each horizontal
distance. If there are two nodes at the same depth and horizontal distance,
either is acceptable.

For this tree, for example, the bottom view could be [0, 1, 3, 6, 8, 9].

Given the root to a binary tree, return its bottom view.
*/
#include <iostream>
#include <map>
#include <vector>

#include "btNode.hpp"

inline void traverse( btNode<int> * root, std::map<int, std::pair<int, int>> & positions, int depth = 0,
                      int distance = 0 )
{
  positions[root->value] = { depth, distance };                                                // Current
  if( root->left != nullptr ) traverse( root->left, positions, depth + 1, distance - 1 );      // Left
  if( root->right != nullptr ) traverse( root->right, positions, depth + 1, distance + 1 );    // Right
}

inline std::vector<int> bottomView( btNode<int> * root )
{
  std::map<int, std::pair<int, int>> positions;
  traverse( root, positions );

  std::map<int, std::pair<int, int>> lowestDistatHeight;

  for( auto & [val, depDis] : positions )
  {
    if( lowestDistatHeight.find( depDis.second ) == lowestDistatHeight.end() )
    {
      lowestDistatHeight[depDis.second] = { depDis.first, val };
    }
    else
    {
      if( depDis.first > lowestDistatHeight[depDis.second].first )
      {
        lowestDistatHeight[depDis.second] = { depDis.first, val };
      }
    }
  }

  std::vector<int> bottom;

  bottom.reserve( lowestDistatHeight.size() );
  for( auto & [dis, depVal] : lowestDistatHeight )
  {
    bottom.push_back( depVal.second );
  }

  return bottom;
}
#endif
