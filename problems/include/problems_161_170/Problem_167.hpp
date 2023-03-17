#ifndef PROBLEMS_161_170_PROBLEM_167_HPP
#define PROBLEMS_161_170_PROBLEM_167_HPP

#pragma once

/* HARD
Given a list of words, find all pairs of unique indices such that the
concatenation of the two words is a palindrome.

For example, given the list ["code", "edoc", "da", "d"], return [(0, 1), (1, 0),
(2, 3)].
*/
#include <string>
#include <vector>

#include "problems_031_040/Problem_034.hpp"

inline std::vector<std::pair<int, int>> palindromes( std::vector<std::string> words ) {
  std::vector<std::pair<int, int>> indices;

  for ( int i = 0; i < words.size(); i++ ) {
    for ( int j = 0; j < words.size(); j++ ) {
      if ( j == i ) continue;
      std::string word = words[i];
      word             += words[j];
      if ( isPalindrome( word ) ) indices.emplace_back( i, j );
    }
  }
  return indices;
}
#endif
