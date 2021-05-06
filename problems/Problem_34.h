#pragma once

#include <string>

/* Medium
Given a string, find the palindrome that can be made by inserting the fewest number of characters as possible anywhere
in the word. If there is more than one palindrome of minimum length that can be made, return the lexicographically
earliest one (the first one alphabetically).

For example, given the string "race", you should return "ecarace", since we can add three letters to it (which is the
smallest amount to make a palindrome). There are seven other palindromes that can be made from "race" by adding three
letters, but "ecarace" comes first alphabetically.

As another example, given the string "google", you should return "elgoogle".
*/

bool isPalindrome( std::string str )
{
  std::string reverse = str;
  std::reverse( reverse.begin(), reverse.end() );

  return reverse == str;
}

std::string makePalindrome( std::string s )
{
  if( isPalindrome( s ) ) return s;

  if( s[0] == s[s.size() - 1] ) { return s[0] + makePalindrome( s.substr( 1, s.size() - 2 ) ) + s[s.size() - 1]; }
  else
  {
    std::string one = s[0] + makePalindrome( s.substr( 1 ) ) + s[0];
    std::string two = s[s.size() - 1] + makePalindrome( s.substr( 0, s.size() - 1 ) ) + s[s.size() - 1];

    if( one.size() < two.size() ) return one;
    else if( two.size() < one.size() )
      return two;
    else
      return min( one, two );
  }
}
