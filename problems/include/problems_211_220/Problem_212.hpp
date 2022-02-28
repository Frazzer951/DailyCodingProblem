#ifndef PROBLEMS_211_220_PROBLEM_212_HPP
#define PROBLEMS_211_220_PROBLEM_212_HPP


#pragma once

/* EASY
Spreadsheets often use this alphabetical encoding for its columns: "A", "B",
"C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....

Given a column number, return its alphabetical column id. For example, given 1,
return "A". Given 27, return "AA".
*/
#include <string>

inline std::string colLetter( int col )
{
  std::string letters;

  while( col > 0 )
  {
    int cur = col % 26;
    if( cur == 0 ) cur = 26;
    letters += char( cur + 64 );
    col -= 26;
  }

  return letters;
}
#endif
