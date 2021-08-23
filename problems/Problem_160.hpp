#pragma once

/* HARD
Given a tree where each edge has a weight, compute the length of the longest path in the tree.

For example, given the following tree:

   a
  /|\
 b c d
    / \
   e   f
  / \
 g   h
and the weights: a-b: 3, a-c: 5, a-d: 8, d-e: 2, d-f: 4, e-g: 1, e-h: 1, the longest path would be c -> a -> d -> f,
with a length of 17.

The path does not have to pass through the root, and each node can have any amount of children.
*/

#include <limits>
#include <vector>

struct Node
{
  char                                val;
  std::vector<std::pair<int, Node *>> children;
};

inline std::pair<int, int> longest_height_and_path( Node * root )
{
  int longest_path_so_far = std::numeric_limits<int>::min();
  int highest             = 0;
  int second_highest      = 0;
  for( auto & [length, child] : root->children )
  {
    auto [height, longest_path_length] = longest_height_and_path( child );

    longest_path_so_far = std::max( longest_path_so_far, longest_path_length );

    if( height + length > highest )
    {
      second_highest = highest;
      highest        = height + length;
    }
    else if( height + length > second_highest )
    {
      second_highest = height + length;
    }
  }

  return { highest, std::max( longest_path_so_far, highest + second_highest ) };
}

inline int longest_path( Node * root )
{
  auto [height, path] = longest_height_and_path( root );
  return path;
}