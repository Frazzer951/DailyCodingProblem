#ifndef PROBLEMS_221_230_PROBLEM_229_HPP
#define PROBLEMS_221_230_PROBLEM_229_HPP


#pragma once

/* MEDIUM
Snakes and Ladders [https://en.wikipedia.org/wiki/Snakes_and_Ladders] is a game
played on a 10 x 10 board, the goal of which is get from square 1 to square 100.
On each turn players will roll a six-sided die and move forward a number of
spaces equal to the result. If they land on a square that represents a snake or
ladder, they will be transported ahead or behind, respectively, to a new square.

Find the smallest number of turns it takes to play snakes and ladders.

For convenience, here are the squares representing snakes and ladders, and their
outcomes:

snakes = {16: 6, 48: 26, 49: 11, 56: 53, 62: 19, 64: 60, 87: 24, 93: 73, 95: 75, 98: 78}
ladders = {1: 38, 4: 14, 9: 31, 21: 42, 28: 84, 36: 44, 51: 67, 71: 91, 80: 100}
*/
inline int minimum_turns()
{
  std::map<int, int> snakes_and_ladders = { { 16, 6 },  { 48, 26 }, { 49, 11 }, { 56, 53 }, { 62, 19 },
                                            { 64, 60 }, { 87, 24 }, { 93, 73 }, { 95, 75 }, { 98, 78 },
                                            { 1, 38 },  { 4, 14 },  { 9, 31 },  { 21, 42 }, { 28, 84 },
                                            { 36, 44 }, { 51, 67 }, { 71, 91 }, { 80, 100 } };

  std::vector<int> board;
  for( int i = 0; i <= 100; ++i )
  {
    if( snakes_and_ladders.find( i ) != snakes_and_ladders.end() ) { board.push_back( snakes_and_ladders[i] ); }
    else
    {
      board.push_back( i );
    }
  }

  int                             start = 0;
  int                             end   = 100;
  int                             turns = 0;
  std::deque<std::pair<int, int>> path  = { std::make_pair( start, turns ) };
  std::set<int>                   visited;

  while( !path.empty() )
  {
    int square = path.front().first;
    turns      = path.front().second;
    path.pop_front();

    for( int move = square + 1; move < square + 7; ++move )
    {
      if( move >= end ) return turns + 1;

      if( visited.find( move ) == visited.end() )
      {
        visited.insert( move );
        path.emplace_back( board[move], turns + 1 );
      }
    }
  }
  return -1;
}
#endif
