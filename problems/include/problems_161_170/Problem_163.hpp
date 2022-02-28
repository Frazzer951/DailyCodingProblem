#ifndef PROBLEMS_161_170_PROBLEM_163_HPP
#define PROBLEMS_161_170_PROBLEM_163_HPP


#pragma once

/* HARD
Given an arithmetic expression in Reverse Polish Notation
[https://en.wikipedia.org/wiki/Reverse_Polish_notation], write a program to
evaluate it.

The expression is given as a list of numbers and operands. For example: [5, 3,
'+'] should return 5 + 3 = 8.

For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'] should
return 5, since it is equivalent to ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) =
5.

You can assume the given expression is always valid.
*/
#include <stack>
#include <string>
#include <vector>

inline double getDouble( std::stack<std::string> & values )
{
  std::string s = values.top();
  values.pop();
  return std::atof( s.c_str() );
}

inline double solve( const std::vector<std::string> & equation )
{
  std::stack<std::string> values;
  for( const std::string & s : equation )
  {
    if( s == "+" )
    {
      double v2 = getDouble( values );
      double v1 = getDouble( values );
      values.push( std::to_string( v1 + v2 ) );
    }
    else if( s == "-" )
    {
      double v2 = getDouble( values );
      double v1 = getDouble( values );
      values.push( std::to_string( v1 - v2 ) );
    }
    else if( s == "*" )
    {
      double v2 = getDouble( values );
      double v1 = getDouble( values );
      values.push( std::to_string( v1 * v2 ) );
    }
    else if( s == "/" )
    {
      double v2 = getDouble( values );
      double v1 = getDouble( values );
      values.push( std::to_string( v1 / v2 ) );
    }
    else
    {
      values.push( s );
    }
  }
  return std::atof( values.top().c_str() );
}
#endif
