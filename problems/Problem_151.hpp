#pragma once

/* MEDIUM
Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C, replace the color of the
given pixel and all adjacent same colored pixels with C.

For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:

B B W
W W W
W W W
B B B
Becomes

B B G
G G G
G G G
B B B
*/

#include <vector>

inline bool inRange( std::vector<std::vector<char>> v, int x, int y )
{
  return ( x >= 0 && x < v.size() ) && ( y >= 0 && y < v[0].size() );
}

inline std::vector<std::vector<char>> pixleReplace( std::vector<std::vector<char>> pixelMatrix, std::pair<int, int> loc,
                                                    char newPixle )
{
  char curPixle                      = pixelMatrix[loc.first][loc.second];
  pixelMatrix[loc.first][loc.second] = newPixle;

  if( inRange( pixelMatrix, loc.first - 1, loc.second ) && pixelMatrix[loc.first - 1][loc.second] == curPixle )
    pixelMatrix = pixleReplace( pixelMatrix, std::make_pair( loc.first - 1, loc.second ), newPixle );
  if( inRange( pixelMatrix, loc.first + 1, loc.second ) && pixelMatrix[loc.first + 1][loc.second] == curPixle )
    pixelMatrix = pixleReplace( pixelMatrix, std::make_pair( loc.first + 1, loc.second ), newPixle );
  if( inRange( pixelMatrix, loc.first, loc.second - 1 ) && pixelMatrix[loc.first][loc.second - 1] == curPixle )
    pixelMatrix = pixleReplace( pixelMatrix, std::make_pair( loc.first, loc.second - 1 ), newPixle );
  if( inRange( pixelMatrix, loc.first, loc.second + 1 ) && pixelMatrix[loc.first][loc.second + 1] == curPixle )
    pixelMatrix = pixleReplace( pixelMatrix, std::make_pair( loc.first - 1, loc.second + 1 ), newPixle );

  return pixelMatrix;
}