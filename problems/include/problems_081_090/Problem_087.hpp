#pragma once

/* HARD
A rule looks like this:

A NE B

This means this means point A is located northeast of point B.

A SW C

means that point A is southwest of C.

Given a list of rules, check if the sum of the rules validate. For example:

A N B
B NE C
C N A


does not validate, since A cannot be both north and south of C.

A NW B
A N B


is considered valid.
*/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "Futils.hpp"

static int                 N         = 0;
static int                 E         = 1;
static int                 S         = 2;
static int                 W         = 3;
static int                 DIRS[]    = { N, E, S, W };
static std::map<char, int> charToDir = { { 'N', N }, { 'E', E }, { 'S', S }, { 'W', W } };

struct mapNode
{
  std::vector<std::set<mapNode *>> edges;
  char                             val;

  mapNode( char value = ' ' ) : val( value )
  {
    for( int i = 0; i < 4; i++ ) { edges.emplace_back(); }
  }
};

inline bool operator==( const mapNode & lhs, const mapNode & rhs )
{
  return ( lhs.val == rhs.val ) && ( lhs.edges == rhs.edges );
}

inline bool operator<( const mapNode & lhs, const mapNode & rhs ) { return lhs.val < rhs.val; }

inline int opposite( int dir ) { return ( dir + 2 ) % 4; }


inline bool isValid( mapNode * from, mapNode * to, int newDir )
{
  int oppositeDir = opposite( newDir );
  return from->edges[oppositeDir].find( to ) == from->edges[oppositeDir].end();
}


inline void addEdges( mapNode * from, mapNode * to, int newDir )
{
  /* Get the direct opposite direction, e.g. S from N */
  int oppositeDir = opposite( newDir );

  /* Add the immediate edge between the nodes, using bi-directional edges. */
  from->edges[newDir].insert( to );
  to->edges[oppositeDir].insert( from );

  for( int dir : DIRS )
  {
    /* Relationships in the same direction are ambiguous.
         For example, if A is north of B, and we are adding
         C north of B, we cannot say C is north of A. */
    if( dir == newDir ) continue;

    for( mapNode * neighbor : from->edges[dir] )
    {
      /* No need to add self-edges */
      if( neighbor == to ) continue;
      /* Add bi-directional edges */
      neighbor->edges[newDir].insert( to );
      to->edges[oppositeDir].insert( neighbor );
    }
  }
}

inline bool validate( const std::vector<std::string> & rules )
{
  std::map<char, mapNode *> map;

  for( const std::string & line : rules )
  {
    auto rule = split( line );
    std::cout << "Rule " + rule[0] + " " + rule[1] + " " + rule[2] << '\n';
    char fromVal = rule[2][0];
    char toVal   = rule[0][0];

    if( map.find( fromVal ) == map.end() )
    {
      auto * n     = new mapNode( fromVal );
      map[fromVal] = n;
    }

    if( map.find( toVal ) == map.end() )
    {
      auto * n   = new mapNode( toVal );
      map[toVal] = n;
    }

    mapNode * from = map[fromVal];
    mapNode * to   = map[toVal];

    /* Decompose diagonal (two-char) directions to single directions */
    for( char dirChar : rule[1] )
    {
      int dir = charToDir[dirChar];
      if( !isValid( from, to, dir ) ) return false;
      addEdges( from, to, dir );
    }
  }

  return true;
}
