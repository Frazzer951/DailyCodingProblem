#pragma once

/* MEDIUM
Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all
strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.
*/

#include <iostream>
#include <utility>
#include <vector>

inline std::vector<std::string> autocomplete( const std::string & qstr, const std::vector<std::string> & qstrs )
{
  std::vector<std::string> returnStrs;

  for( const std::string & word : qstrs )
  {
    if( qstr == word.substr( 0, qstr.size() ) ) returnStrs.push_back( word );
  }

  return returnStrs;
}

inline void testComplete( const std::string & qstr, const std::vector<std::string> & qstrs )
{
  std::vector<std::string> autocompletes = autocomplete( qstr, qstrs );

  std::cout << "'" << qstr << "' auto-completes to ";

  for( const std::string & str : autocompletes ) std::cout << str << ' ';

  std::cout << '\n';
}

inline int prob_11()
{
  std::cout << "\nProblem 11\n";

  testComplete( "de", { "dog", "deer", "deal" } );

  return 0;
}