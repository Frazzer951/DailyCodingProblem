#ifndef PROBLEMS_091_100_PROBLEM_098_HPP
#define PROBLEMS_091_100_PROBLEM_098_HPP


#pragma once

/* EASY
Given a 2D board of characters and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where
"adjacent" cells are those horizontally or vertically neighboring. The same
letter cell may not be used more than once.

For example, given the following board:

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]


exists(board, "ABCCED") returns true,exists(board, "SEE") returns true,
exists(board, "ABCB") returns false.
*/
#include <string>
#include <vector>

inline bool is_valid( std::vector<std::vector<char>> board, int row, int col )
{
  return row >= 0 && row < board.size() && col >= 0 && col < board[0].size();
}

inline bool search( std::vector<std::vector<char>> board, int row, int col, std::string word, std::size_t index,
                    std::vector<std::vector<bool>> & visited )
{
  if( !is_valid( board, row, col ) ) return false;
  if( visited[row][col] ) return false;
  if( board[row][col] != word[index] ) return false;
  if( index == word.size() - 1 ) return true;

  visited[row][col] = true;

  for( auto d : { std::make_pair( 0, -1 ), std::make_pair( 0, 1 ), std::make_pair( -1, 0 ), std::make_pair( 1, 0 ) } )
  {
    if( search( board, row + d.first, col + d.second, word, index + 1, visited ) ) return true;
  }
  visited[row][col] = false;    // Backtrack

  return false;
}

inline bool find_word( std::vector<std::vector<char>> board, const std::string & word )
{
  int M = (int) board.size();
  int N = (int) board[0].size();

  for( int row = 0; row < M; row++ )
  {
    for( int col = 0; col < N; col++ )
    {
      std::vector<std::vector<bool>> visited = std::vector( M, std::vector( N, false ) );
      if( search( board, row, col, word, 0, visited ) ) return true;
    }
  }
  return false;
}
#endif
