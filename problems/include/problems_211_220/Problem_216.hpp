#pragma once

/* MEDIUM
Given a number in Roman numeral [https://en.wikipedia.org/wiki/Roman_numerals]
format, convert it to decimal.

The values of Roman numerals are as follows:

{
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}


In addition, note that the Roman numeral system uses subtractive notation
[https://en.wikipedia.org/wiki/Subtractive_notation] for numbers such as IV and
XL.

For the input XIV, for instance, you should return 14.
*/

#include <map>
#include <string>

inline int romanToInt( std::string roman )
{
  std::map<char, int> values = { { 'M', 1000 }, { 'D', 500 }, { 'C', 100 }, { 'L', 50 },
                                 { 'X', 10 },   { 'V', 5 },   { 'I', 1 } };
  int                 num    = 0;
  for( int i = 0; i < roman.length(); i++ )
  {
    if( i + 1 < roman.length() )
    {
      if( values[roman[i + 1]] > values[roman[i]] )
      {
        num += values[roman[i + 1]] - values[roman[i]];
        i++;
      }
      else
      {
        num += values[roman[i]];
      }
    }
  }
  return num;
}