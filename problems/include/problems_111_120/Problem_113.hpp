#ifndef PROBLEMS_111_120_PROBLEM_113_HPP
#define PROBLEMS_111_120_PROBLEM_113_HPP


#pragma once

/* MEDIUM
Given a string of words delimited by spaces, reverse the words in string. For
example, given "hello world here", return "here world hello"

Follow-up: given a mutable string representation, can you perform this operation
in-place?
*/
#include <string>
#include <utility>

#include "Futils.hpp"

inline std::string reverseSentance( std::string sentance )
{
  auto        words = split( std::move( sentance ) );
  std::string reverse;
  for( auto i = words.rbegin(); i != words.rend(); ++i )
  {
    reverse += *i + " ";
  }
  reverse.erase( reverse.end() - 1 );
  return reverse;
}
#endif
