#pragma once

/* My Custom Functions */

#include <string>
#include <vector>

std::vector<std::string> split( std::string str, char delim = ' ' )
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

int getIntVecMax( std::vector<int> v )
{
  int max = v[0];
  for( unsigned int i = 0; i < v.size(); ++i )
  {
    if( v[i] > max ) { max = v[i]; }
  }
  return max;
}

std::string intVecToStr( std::vector<int> v )
{
  std::string str;
  for( unsigned int i = 0; i < v.size(); ++i )
  {
    str += std::to_string( v[i] ) + ' ';
  }
  return str;
}