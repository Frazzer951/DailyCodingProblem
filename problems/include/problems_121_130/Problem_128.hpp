#ifndef PROBLEMS_121_130_PROBLEM_128_HPP
#define PROBLEMS_121_130_PROBLEM_128_HPP

#pragma once

/* MEDIUM
The Tower of Hanoi is a puzzle game with three rods and n disks, each a
different size.

All the disks start off on the first rod in a stack. They are ordered by size,
with the largest disk on the bottom and the smallest one at the top.

The goal of this puzzle is to move all the disks from the first rod to the last
rod while following these rules:

 * You can only move one disk at a time.
 * A move consists of taking the uppermost disk from one of the stacks and
   placing it on top of another stack.
 * You cannot place a larger disk on top of a smaller disk.

Write a function that prints out all the steps necessary to complete the Tower
of Hanoi. You should assume that the rods are numbered, with the first rod being
1, the second (auxiliary) rod being 2, and the last (goal) rod being 3.

For example, with n = 3, we can do this in 7 moves:

Move 1 to 3
Move 1 to 2
Move 3 to 2
Move 1 to 3
Move 2 to 1
Move 2 to 3
Move 1 to 3
*/
#include <stack>
#include <vector>

inline std::vector<std::pair<int, int>> solveHanoi( int n ) {
  std::vector<std::pair<int, int>> moves;

  std::stack<int> A;
  std::stack<int> B;
  std::stack<int> C;

  auto moveAB = [&moves, &A, &B]() {
    if ( A.empty() && B.empty() ) return;
    if ( A.empty() ) {
      A.push( B.top() );
      B.pop();
      moves.emplace_back( 2, 1 );
    } else if ( B.empty() ) {
      B.push( A.top() );
      A.pop();
      moves.emplace_back( 1, 2 );
    } else {
      if ( A.top() < B.top() ) {
        B.push( A.top() );
        A.pop();
        moves.emplace_back( 1, 2 );
      } else {
        A.push( B.top() );
        B.pop();
        moves.emplace_back( 2, 1 );
      }
    }
  };
  auto moveAC = [&moves, &A, &C]() {
    if ( A.empty() && C.empty() ) return;
    if ( A.empty() ) {
      A.push( C.top() );
      C.pop();
      moves.emplace_back( 3, 1 );
    } else if ( C.empty() ) {
      C.push( A.top() );
      A.pop();
      moves.emplace_back( 1, 3 );
    } else {
      if ( A.top() < C.top() ) {
        C.push( A.top() );
        A.pop();
        moves.emplace_back( 1, 3 );
      } else {
        A.push( C.top() );
        C.pop();
        moves.emplace_back( 3, 1 );
      }
    }
  };
  auto moveBC = [&moves, &B, &C]() {
    if ( B.empty() && C.empty() ) return;
    if ( B.empty() ) {
      B.push( C.top() );
      C.pop();
      moves.emplace_back( 3, 2 );
    } else if ( C.empty() ) {
      C.push( B.top() );
      B.pop();
      moves.emplace_back( 2, 3 );
    } else {
      if ( B.top() < C.top() ) {
        C.push( B.top() );
        B.pop();
        moves.emplace_back( 2, 3 );
      } else {
        B.push( C.top() );
        C.pop();
        moves.emplace_back( 3, 2 );
      }
    }
  };

  for ( int i = n; i > 0; i-- ) { A.push( i ); }

  if ( n % 2 == 0 ) {
    while ( !A.empty() || !B.empty() ) {
      moveAB();
      if ( A.empty() && B.empty() ) break;
      moveAC();
      if ( A.empty() && B.empty() ) break;
      moveBC();
    }
  } else {
    while ( !A.empty() || !B.empty() ) {
      moveAC();
      if ( A.empty() && B.empty() ) break;
      moveAB();
      if ( A.empty() && B.empty() ) break;
      moveBC();
    }
  }

  return moves;
}

/*
For an even number of disks:
  make the legal move between pegs A and B (in either direction),
  make the legal move between pegs A and C (in either direction),
  make the legal move between pegs B and C (in either direction),
  repeat until complete.


For an odd number of disks:
  make the legal move between pegs A and C (in either direction),
  make the legal move between pegs A and B (in either direction),
  make the legal move between pegs B and C (in either direction),
  repeat until complete.
*/
#endif
