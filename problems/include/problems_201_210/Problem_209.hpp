#ifndef PROBLEMS_201_210_PROBLEM_209_HPP
#define PROBLEMS_201_210_PROBLEM_209_HPP

#pragma once

/* HARD
Write a program that computes the length of the longest common subsequence of
three given strings. For example, given "epidemiologist", "refrigeration", and
"supercalifragilisticexpialodocious", it should return 5, since the longest
common subsequence is "eieio".
*/
#include <string>
#include <vector>

inline int lcs( std::string a, std::string b, std::string c ) {
  std::vector<std::vector<std::vector<int>>> lengths =
      std::vector( a.size(), std::vector( b.size(), std::vector( c.size(), 0 ) ) );
  for ( int i = 0; i < a.size() - 1; i++ ) {
    char const x = a[i];
    for ( int j = 0; j < b.size() - 1; j++ ) {
      char const y = b[j];
      for ( int k = 0; k < c.size() - 1; k++ ) {
        char const z = c[k];
        if ( x == y && y == z ) {
          lengths[i + 1][j + 1][k + 1] = lengths[i][j][k] + 1;
        } else {
          lengths[i + 1][j + 1][k + 1] =
              std::max( lengths[i][j + 1][k + 1], std::max( lengths[i + 1][j][k + 1], lengths[i + 1][j + 1][k] ) );
        }
      }
    }
  }
  return lengths[lengths.size() - 1][lengths[0].size() - 1][lengths[0][0].size() - 1];
}
#endif
