#ifndef FUTILS_HPP
#define FUTILS_HPP

#pragma once

/* My Custom Functions */

#include <iostream>
#include <string>
#include <vector>

inline std::vector<std::string> split( std::string str, char delim = ' ' )
{
  std::vector<std::string> split_str;
  std::string              word;
  unsigned int             i = 0;
  while( i < str.length() )
  {
    if( str[i] == delim )
    {
      split_str.push_back( word );
      word = "";
    }
    else
    {
      word += str[i];
    }
    i++;
  }
  split_str.push_back( word );
  return split_str;
}

inline int getIntVecMax( std::vector<int> v )
{
  int max = v[0];
  for( int i : v )
  {
    if( i > max ) { max = i; }
  }
  return max;
}

inline int getIntVecMin( std::vector<int> v, unsigned int exclude_index = -1 )
{
  int min = ( exclude_index == 0 ) ? v[1] : v[0];
  for( unsigned int i = 0; i < v.size(); ++i )
  {
    if( i == exclude_index ) continue;
    if( v[i] < min ) { min = v[i]; }
  }
  return min;
}

inline std::string intVecToStr( const std::vector<int> & v )
{
  std::string str;
  for( int i : v ) { str += std::to_string( i ) + ' '; }
  return str;
}

inline int sum( const std::vector<int> & v )
{
  int sum = 0;

  for( int x : v ) { sum += x; }

  return sum;
}

inline int mod( int a, int b )
{
  int r = a % b;
  return r < 0 ? r + b : r;
}

#endif
