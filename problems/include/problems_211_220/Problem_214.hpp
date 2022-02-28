#ifndef PROBLEMS_211_220_PROBLEM_214_HPP
#define PROBLEMS_211_220_PROBLEM_214_HPP


#pragma once

/* EASY
Given an integer n, return the length of the longest consecutive run of 1s in
its binary representation.

For example, given 156, you should return 3.
*/
inline int longestOneRun( int x )
{
  int maxLength = 0;
  int counter   = 0;
  for( int i = 0; i < 32; i++ )
  {
    bool bit = ( x & ( 1 << i ) ) != 0;
    if( bit ) counter++;
    else
    {
      maxLength = ( counter > maxLength ) ? counter : maxLength;
      counter   = 0;
    }
  }
  return ( counter > maxLength ) ? counter : maxLength;
}
#endif
