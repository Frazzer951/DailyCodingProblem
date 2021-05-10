#pragma once

#include <vector>

/* HARD
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come
first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
*/

void swap( std::vector<char> & v, int i, int j )
{
  char temp = v[i];
  v[i]      = v[j];
  v[j]      = temp;
}

void rgbSort( std::vector<char> & v )
{
  int r = 0, g = 0, b = 0;
  for( int i = 0; i < v.size(); i++ )
  {
    switch( v[i] )
    {
      case 'R': r++; break;
      case 'G': g++; break;
      case 'B': b++; break;
    }
  }
  g += r;
  b += g;

  for( int i = 0; i < v.size(); i++ )
  {
    switch( v[i] )
    {
      case 'R':
        swap( v, i, r - 1 );
        r--;
        break;
      case 'G':
        swap( v, i, g - 1 );
        g--;
        break;
      case 'B':
        swap( v, i, b - 1 );
        b--;
        break;
    }
  }
}