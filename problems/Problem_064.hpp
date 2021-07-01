#pragma once

/* HARD
A knight's tour is a sequence of moves by a knight
on a chessboard such that all squares are visited once.

Given N, write a function to return the number of
knight's tours on an N by N chessboard.
*/

#include <vector>

inline bool is_valid_move( std::vector<std::vector<int>> board, std::pair<int, int> move, int n )
{
  auto & [r, c] = move;
  return 0 <= r && r < n && 0 <= c && c < n && board[r][c] == -1;
}

inline std::vector<std::pair<int, int>> vaild_moves( const std::vector<std::vector<int>> & board, int r, int c, int n )
{
  std::vector<std::pair<int, int>> deltas = { std::make_pair( 2, 1 ),   std::make_pair( 1, 2 ),
                                              std::make_pair( 1, -2 ),  std::make_pair( -2, 1 ),
                                              std::make_pair( -1, 2 ),  std::make_pair( 2, -1 ),
                                              std::make_pair( -1, -2 ), std::make_pair( -2, -1 ) };

  std::vector<std::pair<int, int>> all_moves;

  all_moves.reserve( deltas.size() );
  for( auto & [r_delta, c_delta] : deltas ) { all_moves.emplace_back( r + r_delta, c + c_delta ); }

  std::vector<std::pair<int, int>> moves;

  for( auto & move : all_moves )
  {
    if( is_valid_move( board, move, n ) ) { moves.push_back( move ); }
  }

  return moves;
}

inline int knights_tours_helper( std::vector<std::vector<int>> board, std::vector<std::pair<int, int>> tour, int n )
{
  if( tour.size() == n * n ) return 1;

  int count               = 0;
  auto & [last_r, last_c] = tour[tour.size() - 1];

  auto moves = vaild_moves( board, last_r, last_c, n );
  for( auto & [r, c] : moves )
  {
    tour.emplace_back( r, c );
    board[r][c] = (int) tour.size();
    count += knights_tours_helper( board, tour, n );
    tour.pop_back();
    board[r][c] = -1;
  }
  return count;
}

inline int knights_tours( int n )
{
  int count = 0;
  for( int i = 0; i < n; i++ )
  {
    for( int j = 0; j < n; j++ )
    {
      std::vector<std::vector<int>> board( n, std::vector<int>( n, -1 ) );
      board[i][j] = 0;
      count += knights_tours_helper( board, { std::make_pair( i, j ) }, n );
    }
  }
  return count;
}
