#pragma once

/* MEDIUM
Given a matrix of 1s and 0s, return the number of "islands" in the matrix.
A 1 represents land and 0 represents water, so an island is a group of 1s
that are neighboring whose perimeter is surrounded by water.

For example, this matrix has 4 islands.

1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1
*/

#include <vector>

inline int num_islands( std::vector<std::vector<int>> island_map )
{
  std::vector<std::vector<bool>> visited( island_map.size(), std::vector( island_map[0].size(), false ) );

  int island_count = 0;

  // Loop trough all the "tiles"
  for( int i = 0; i < island_map.size(); i++ )
  {
    for( int j = 0; j < island_map[0].size(); j++ )
    {
      visited[i][j] = true;    // Current "tile" was visited
      if( island_map[i][j] != 0 )
      {    // Current "tile" is land
        if( j - 1 >= 0 )
          if( visited[i][j - 1] && ( island_map[i][j - 1] != 0 ) ) continue;    // Up
        if( i - 1 >= 0 )
          if( visited[i - 1][j] && ( island_map[i - 1][j] != 0 ) ) continue;    // Left
        if( j + 1 < island_map[0].size() )
          if( visited[i][j + 1] && ( island_map[i][j + 1] != 0 ) ) continue;    // Down
        if( i + 1 < island_map.size() )
          if( visited[i + 1][j] && ( island_map[i + 1][j] != 0 ) ) continue;    // Right
        if( j - 1 >= 0 && i - 1 >= 0 )
          if( visited[i - 1][j - 1] && ( island_map[i - 1][j - 1] != 0 ) ) continue;    // Up Left
        if( j - 1 >= 0 && i + 1 < island_map.size() )
          if( visited[i + 1][j - 1] && ( island_map[i + 1][j - 1] != 0 ) ) continue;    // Up Right
        if( j + 1 < island_map[0].size() && i - 1 >= 0 )
          if( visited[i - 1][j + 1] && ( island_map[i - 1][j + 1] != 0 ) ) continue;    // Down Left
        if( j + 1 < island_map[0].size() && i + 1 < island_map.size() )
          if( visited[i + 1][j + 1] && ( island_map[i + 1][j + 1] != 0 ) ) continue;    // Down Right

        island_count++;
      }
    }
  }
  return island_count;
}