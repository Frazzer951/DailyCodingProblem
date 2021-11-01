#pragma once

/* HARD
Sudoku is a puzzle where you're given a partially-filled 9 by 9 grid with
digits. The objective is to fill the grid with the constraint that every row,
column, and box (3 by 3 subgrid) must contain all of the digits from 1 to 9.

Implement an efficient sudoku solver.
*/

#include <vector>

inline bool valid_sudoku( std::vector<std::vector<int>> arr )
{
  for( int i = 0; i < 9; i++ )
  {
    for( int j = 0; j < 9; j++ )
    {
      int cur_num = arr[i][j];

      if( cur_num == 0 ) continue;

      // Check Row & Column
      for( int x = 0; x < 9; x++ )
      {
        if( x != i && arr[x][j] == cur_num ) return false;
        if( x != j && arr[i][x] == cur_num ) return false;
      }

      // Check Box
      int box_x = i / 3 * 3;
      int box_y = j / 3 * 3;

      for( int x = box_x; x < box_x + 3; x++ )
      {
        for( int y = box_y; y < box_y + 3; y++ )
        {
          if( x != i && y != j && arr[x][y] == cur_num ) return false;
        }
      }
    }
  }
  return true;
}

inline bool is_filled( std::vector<std::vector<int>> arr )
{
  for( int i = 0; i < 9; i++ )
  {
    for( int j = 0; j < 9; j++ )
    {
      if( arr[i][j] == 0 ) return false;
    }
  }
  return true;
}

inline std::pair<int, int> find_first_empty( std::vector<std::vector<int>> arr )
{
  for( int i = 0; i < 9; i++ )
  {
    for( int j = 0; j < 9; j++ )
    {
      if( arr[i][j] == 0 ) return std::make_pair( i, j );
    }
  }
  return std::make_pair( -1, -1 );
}

/*
def sudoku(board):
    if is_complete(board):
        return board

    r, c = find_first_empty(board)
    # set r, c to a val from 1 to 9
    for i in range(1, 10):
        board[r][c] = i
        if valid_so_far(board):
            result = sudoku(board)
            if is_complete(result):
                return result
        board[r][c] = X
    return board
*/

inline std::vector<std::vector<int>> solveSudoku( std::vector<std::vector<int>> board )
{
  if( valid_sudoku( board ) && is_filled( board ) ) return board;

  auto pos = find_first_empty( board );
  int  r   = pos.first;
  int  c   = pos.second;

  // Set r, c to a val from 1 to 9
  for( int i = 1; i < 10; i++ )
  {
    board[r][c] = i;
    if( valid_sudoku( board ) )
    {
      auto result = solveSudoku( board );
      if( valid_sudoku( result ) && is_filled( result ) ) return result;
    }
    board[r][c] = 0;
  }

  return board;
}