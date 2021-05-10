#pragma once

/* HARD
Given a string, find the longest palindromic contiguous substring. If there are more than one with the maximum length,
return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb". The longest palindromic substring of "bananas"
is "anana".
*/

#include <string>

/*
def is_palindrome(s):
    return s[::-1] == s

def longest_palindrome(s):
    longest = ''
    for i in range(len(s) - 1):
        for j in range(1, len(s)):
            substring = s[i:j]
            if is_palindrome(substring) and len(substring) > len(longest):
                longest = substring
    return longest
*/

bool is_palindrome( std::string s )
{
  std::string temp = s;
  std::reverse( temp.begin(), temp.end() );

  return s == temp;
}

std::string longest_palindrome( std::string s )
{
  std::string longest = "";
  for( int i = 0; i < s.length() - 1; i++ )
  {
    for( int j = 1; j < s.length(); j++ )
    {
      std::string substring = s.substr( i, j - i );
      if( is_palindrome( substring ) && substring.length() > longest.length() ) { longest = substring; }
    }
  }
  return longest;
}