#pragma once

/* HARD
You have an N by N board. Write a function that, given N, returns the number of possible arrangements of the board where
N queens can be placed on the board without threatening each other, i.e. no two queens share the same row, column, or
diagonal.
*/

#include <vector>

/*
def n_queens(n, board=[]):
    if n == len(board):
        return 1

    count = 0
    for col in range(n):
        board.append(col)
        if is_valid(board):
            count += n_queens(n, board)
        board.pop()
    return count

def is_valid(board):
    current_queen_row, current_queen_col = len(board) - 1, board[-1]
    # Iterate over all already-placed queens and check if any of them can attack
    # each other.
    for row, col in enumerate(board[:-1]):
        diff = abs(current_queen_col - col)
        if diff == 0 or diff == current_queen_row - row:
            return False
    return True
*/

bool is_valid( std::vector<int> board )
{
  int current_queen_row = (int)board.size() - 1;
  int current_queen_col = board[board.size() - 1];

  for( int row = 0; row < board.size() - 1; row++ )
  {
    int diff = abs( current_queen_col - board[row] );
    if( diff == 0 || diff == current_queen_row - row ) { return false; }
  }
  return true;
}

int n_queens( int n, std::vector<int> board = {} )
{
  if( n == board.size() ) return 1;

  int count = 0;
  for( int col = 0; col < n; col++ )
  {
    board.push_back( col );
    if( is_valid( board ) ) count += n_queens( n, board );
    board.pop_back();
  }
  return count;
}