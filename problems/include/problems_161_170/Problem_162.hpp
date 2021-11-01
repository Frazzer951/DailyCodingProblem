#ifndef PROBLEMS_161_170_PROBLEM_162_HPP
#define PROBLEMS_161_170_PROBLEM_162_HPP

#pragma once

/* MEDIUM
Given a list of words, return the shortest unique prefix of each word. For
example, given the list:

 * dog
 * cat
 * apple
 * apricot
 * fish

Return the list:

 * d
 * c
 * app
 * apr
 * f
*/

#include <map>
#include <string>
#include <vector>

struct Tnode
{
  std::map<char, Tnode *> children;
  int                     count = 0;
};


class Trie
{
private:
  Tnode * root = new Tnode();

public:
  void insert( const std::string & word )
  {
    Tnode * node = root;

    for( char c : word )
    {
      if( node->children.find( c ) == node->children.end() ) node->children[c] = new Tnode();

      node->count += 1;
      node = node->children[c];
    }
  }

  std::string unique_prefix( const std::string & word )
  {
    Tnode *     node = root;
    std::string prefix;
    for( char c : word )
    {
      if( node->count == 1 ) return prefix;
      node = node->children[c];
      prefix += c;
    }
    return prefix;
  }
};

inline std::vector<std::string> shortest_unique_prefix( const std::vector<std::string> & lst )
{
  Trie trie;
  for( const std::string & word : lst ) trie.insert( word );

  std::vector<std::string> prefix;
  prefix.reserve( lst.size() );
  for( const std::string & word : lst ) prefix.push_back( trie.unique_prefix( word ) );

  return prefix;
}
#endif
