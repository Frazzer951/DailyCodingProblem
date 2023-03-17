#ifndef PROBLEMS_021_030_PROBLEM_023_HPP
#define PROBLEMS_021_030_PROBLEM_023_HPP

#pragma once

/* EASY
You are given an M by N matrix consisting of booleans that represents a board.
Each True boolean represents a wall. Each False boolean represents a tile you
can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum
number of steps required to reach the end coordinate from the start. If there is
no possible path, then return null. You can move up, left, down, and right. You
cannot move through walls. You cannot wrap around the edges of the board.

For example, given the following board:

[[f, f, f, f],
[t, t, f, t],
[f, f, f, f],
[f, f, f, f]]


and start = (3, 0) (bottom left) and end = (0, 0) (top left), the minimum number
of steps required to reach the end is 7, since we would need to go through (1,
2) because there is a wall everywhere else on the second row.
*/
#include <vector>

inline bool canMoveUp( std::vector<std::vector<bool>> maze, std::pair<int, int> curPos ) {
  return !maze[curPos.first - 1][curPos.second];
}
inline bool canMoveDown( std::vector<std::vector<bool>> maze, std::pair<int, int> curPos ) {
  return !maze[curPos.first + 1][curPos.second];
}
inline bool canMoveLeft( std::vector<std::vector<bool>> maze, std::pair<int, int> curPos ) {
  return !maze[curPos.first][curPos.second - 1];
}
inline bool canMoveRight( std::vector<std::vector<bool>> maze, std::pair<int, int> curPos ) {
  return !maze[curPos.first][curPos.second + 1];
}

inline int findOpening( std::vector<bool> row ) {
  for ( int i = 0; i < row.size(); ++i ) {
    if ( !row[i] ) return i;
  }
  return -1;
}

inline int stepsToSolveMaze( std::vector<std::vector<bool>> maze, std::pair<int, int> startPos, std::pair<int, int> endPos ) {
  std::pair<int, int> curPos = startPos;
  int                 moves  = 0;

  while ( curPos != endPos ) {
    // Find the direction we need to move
    bool up    = curPos.first > endPos.first;
    bool down  = curPos.first < endPos.first;
    bool left  = curPos.second > endPos.second;
    bool right = curPos.second < endPos.second;

    // First Get to the same level as the end point
    if ( curPos.first != endPos.first ) {
      if ( up ) {
        if ( canMoveUp( maze, curPos ) ) {
          curPos.first -= 1;
          moves++;
        } else {
          int moveIndex = findOpening( maze[curPos.first - 1] );
          if ( curPos.second < moveIndex ) {
            if ( canMoveRight( maze, curPos ) ) {
              curPos.second += 1;
              moves++;
            }
          } else {
            if ( canMoveLeft( maze, curPos ) ) {
              curPos.second -= 1;
              moves++;
            }
          }
        }
      } else if ( down ) {
        if ( canMoveDown( maze, curPos ) ) {
          curPos.first += 1;
          moves++;
        } else {
          int moveIndex = findOpening( maze[curPos.first + 1] );
          if ( curPos.second < moveIndex ) {
            if ( canMoveRight( maze, curPos ) ) {
              curPos.second += 1;
              moves++;
            }
          } else {
            if ( canMoveLeft( maze, curPos ) ) {
              curPos.second -= 1;
              moves++;
            }
          }
        }
      }
    } else    // Get to the correct point
    {
      if ( left ) {
        if ( canMoveLeft( maze, curPos ) ) {
          curPos.second -= 1;
          moves++;
        }
      } else if ( right ) {
        if ( canMoveRight( maze, curPos ) ) {
          curPos.second += 1;
          moves++;
        }
      }
    }
  }
  return moves;
}
#endif
