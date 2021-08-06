#pragma once

/* HARD
You're given a string consisting solely of (, ), and *. * can represent either a (, ), or an empty string. Determine
whether the parentheses are balanced.

For example, (()* and (*) are balanced. )*( is not balanced.
*/

#include <string>

inline bool balanced( const std::string & s )
{
  int low  = 0;
  int high = 0;
  for( char c : s )
  {
    if( c == '(' )
    {
      low++;
      high++;
    }
    else if( c == ')' )
    {
      low = std::max( low - 1, 0 );
      high--;
    }
    else if( c == '*' )
    {
      low = std::max( low - 1, 0 );
      high++;
    }
    if( high < 0 ) return false;
  }
  return low == 0;
}