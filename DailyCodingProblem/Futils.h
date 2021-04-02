#pragma once

/* My Custom Functions */

#include <vector>
#include <string>

std::vector<std::string> split( std::string str, char delim = ' ' )
{
  std::vector<std::string> split_str;
  std::string              word;
  int                      i = 0;
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