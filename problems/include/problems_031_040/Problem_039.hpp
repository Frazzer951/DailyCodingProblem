#ifndef PROBLEMS_031_040_PROBLEM_039_HPP
#define PROBLEMS_031_040_PROBLEM_039_HPP


#pragma once

/* MEDIUM
Conway's Game of Life takes place on an infinite two-dimensional board of square
cells. Each cell is either dead or alive, and at each tick, the following rules
apply:

 * Any live cell with less than two live neighbours dies.
 * Any live cell with two or three live neighbours remains living.
 * Any live cell with more than three live neighbours dies.
 * Any dead cell with exactly three live neighbours becomes a live cell.

A cell neighbours another cell if it is horizontally, vertically, or diagonally
adjacent.

Implement Conway's Game of Life. It should be able to be initialized with a
starting list of live cell coordinates and the number of steps it should run
for. Once initialized, it should print out the board state at each step. Since
it's an infinite board, print out only the relevant coordinates, i.e. from the
top-leftmost live cell to bottom-rightmost live cell.

You can represent a live cell with an asterisk (*) and a dead cell with a dot (.
).
*/
#include <vector>

inline int count_neighbors( std::vector<std::vector<bool>> & board, int x, int y )
{
  int count = 0;
  for( int i = x - 1; i <= x + 1; i++ )
  {
    for( int j = y - 1; j <= y + 1; j++ )
    {
      if( i == x && j == y ) { continue; }
      if( i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ) { continue; }
      if( board[i][j] ) { count++; }
    }
  }
  return count;
}


inline void game_of_life( std::vector<std::vector<bool>> & board, int steps = 1 )
{
  for( int i = 0; i < steps; i++ )
  {
    std::vector<std::vector<bool>> new_board( board.size(), std::vector<bool>( board[0].size(), false ) );
    for( int x = 0; x < board.size(); x++ )
    {
      for( int y = 0; y < board[0].size(); y++ )
      {
        int count = count_neighbors( board, x, y );
        if( board[x][y] )
        {
          if( count < 2 || count > 3 ) { new_board[x][y] = false; }
          else
          {
            new_board[x][y] = true;
          }
        }
        else
        {
          if( count == 3 ) { new_board[x][y] = true; }
        }
      }
    }
    board = new_board;
  }
}
#endif
