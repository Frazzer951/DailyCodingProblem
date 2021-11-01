#ifndef PROBLEMS_021_030_PROBLEM_028_HPP
#define PROBLEMS_021_030_PROBLEM_028_HPP

#pragma once

/* MEDIUM
Write an algorithm to justify text. Given a sequence of words and an integer
line length k, return a list of strings which represents each line, fully
justified.

More specifically, you should have as many words as possible in each line. There
should be at least one space between each word. Pad extra spaces when necessary
so that each line has exactly length k. Spaces should be distributed as equally
as possible, with the extra spaces, if any, distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side
with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words ["the", "quick", "brown", "fox", "jumps",
"over", "the", "lazy", "dog"] and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly
*/

#include <string>
#include <vector>

inline std::vector<std::string> padWords( std::vector<std::string> words, unsigned int k )
{
  std::vector<std::string> padded_strings;

  while( !words.empty() )
  {
    size_t                   length = 0;
    std::vector<std::string> line;

    while( length < k )
    {
      if( words.empty() ) break;
      std::string word = words[0];
      if( length + word.size() + line.size() <= k )
      {
        line.push_back( word );
        words.erase( words.begin() );
        length += word.size();
      }
      else
        break;
    }
    length += line.size() - 1;
    size_t addSpaces = k - length;

    while( addSpaces > 0 )
    {
      for( unsigned int i = 0; i < line.size() - 1; i++ )
      {
        if( addSpaces <= 0 ) break;
        line[i] += ' ';
        addSpaces--;
      }
    }

    std::string temp;
    for( unsigned int i = 0; i < line.size(); i++ )
    {
      temp += line[i];
      if( i != line.size() - 1 ) temp += ' ';
    }
    padded_strings.push_back( temp );
  }
  return padded_strings;
}
#endif
