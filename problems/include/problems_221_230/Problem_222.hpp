#ifndef PROBLEMS_221_230_PROBLEM_222_HPP
#define PROBLEMS_221_230_PROBLEM_222_HPP

#pragma once

/* MEDIUM
Given an absolute pathname that may have . or .. as part of it, return the
shortest standardized path.

For example, given "/usr/bin/../bin/./scripts/../", return "/usr/bin/".
*/

#include <deque>
#include <string>

inline std::string shortestAbsolutePath( std::string path )
{
  std::deque<std::string> dq;
  std::string             result;
  std::string             temp;
  int                     i = 0;
  while( i < path.size() )
  {
    if( path[i] == '/' )
    {
      if( temp == ".." )
      {
        if( !dq.empty() ) dq.pop_back();
      }
      else if( temp != "." && !temp.empty() )
      {
        dq.push_back( temp );
      }
      temp = "";
    }
    else
    {
      temp += path[i];
    }
    i++;
  }
  if( temp == ".." )
  {
    if( !dq.empty() ) dq.pop_back();
  }
  else if( temp != "." )
  {
    dq.push_back( temp );
  }
  while( !dq.empty() )
  {
    result += "/" + dq.front();
    dq.pop_front();
  }
  if( result.empty() ) result = "/";
  return result;
}

#endif
