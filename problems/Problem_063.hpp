#pragma once

/* EASY
Given a 2D matrix of characters and a target word,
write a function that returns whether the word can
be found in the matrix by going left-to-right, or
up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]

and the target word 'FOAM', you should return true,
since it's the leftmost column. Similarly, given the
target word 'MASS', you should return true, since
it's the last row.
*/

#include <string>
#include <vector>

bool findWord( std::vector<std::vector<char>> letters, std::string word )
{
  if( letters.size() < word.size() && letters[0].size() < word.size() ) return false;

  bool wordFound;

  // First Go Trough Columns
  for( int i = 0; i < letters.size(); i++ )
  {
    if( letters[i][0] == word[0] )
    {
      wordFound = true;
      for( int j = 0; j < word.size(); j++ )
      {
        if( letters[i][j] != word[j] )
        {
          wordFound = false;
          break;
        }
      }
      if( wordFound ) return true;
    }
  }

  // Second Go Trough Rows
  for( int i = 0; i < letters.size(); i++ )
  {
    if( letters[0][i] == word[0] )
    {
      wordFound = true;
      for( int j = 0; j < word.size(); j++ )
      {
        if( letters[j][i] != word[j] )
        {
          wordFound = false;
          break;
        }
      }
      if( wordFound ) return true;
    }
  }

  return false;
}