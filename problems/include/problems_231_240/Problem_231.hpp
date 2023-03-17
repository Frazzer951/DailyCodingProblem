#ifndef PROBLEMS_231_240_PROBLEM_231_HPP
#define PROBLEMS_231_240_PROBLEM_231_HPP

#pragma once

/* EASY
Given a string with repeated characters, rearrange the string so that no two
adjacent characters are the same. If this is not possible, return None.

For example, given "aaabbc", you could return "ababac". Given "aaab", return
None.
*/
#include <map>
#include <queue>
#include <string>
#include <vector>

struct Letter {
  int  priority {};
  char data { ' ' };

  friend bool operator<( Letter const &lhs, Letter const &rhs ) { return lhs.priority > rhs.priority; }

  friend std::ostream &operator<<( std::ostream &os, Letter const &e ) {
    return os << "{ " << e.priority << ", '" << e.data << "' } ";
  }
};

inline std::string noRepeatingAdjacentCharacters( const std::string &input ) {
  std::map<char, int> charCount;
  for ( auto c : input ) { charCount[c]++; }

  std::priority_queue<Letter> heap;
  for ( auto &c : charCount ) { heap.push( Letter { -c.second, c.first } ); }

  Letter l     = heap.top();
  int    count = l.priority;
  char   c     = l.data;
  heap.pop();
  std::vector<char> result = { c };

  while ( !heap.empty() ) {
    Letter const last = { count + 1, c };
    l           = heap.top();
    heap.pop();
    count = l.priority;
    c     = l.data;
    result.push_back( c );

    if ( last.priority < 0 ) { heap.push( last ); }
  }

  if ( result.size() != input.size() ) { return ""; }
  return std::string( result.begin(), result.end() );
}
#endif
