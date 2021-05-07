#pragma once

/* My Custom Functions */

#include <string>
#include <vector>

inline std::vector<std::string> split( std::string str, char delim = ' ' )
{
  std::vector<std::string> split_str;
  std::string              word;
  unsigned int             i = 0;
  while( i < str.length() )
  {
    if( str[i] == delim )
    {
      split_str.push_back( word );
      word = "";
    }
    else
    {
      word += str[i];
    }
    i++;
  }
  split_str.push_back( word );
  return split_str;
}

inline int getIntVecMax( std::vector<int> v )
{
  int max = v[0];
  for( unsigned int i = 0; i < v.size(); ++i )
  {
    if( v[i] > max ) { max = v[i]; }
  }
  return max;
}

inline int getIntVecMin( std::vector<int> v, unsigned int exclude_index = -1 )
{
  int min = ( exclude_index == 0 ) ? v[1] : v[0];
  for( unsigned int i = 0; i < v.size(); ++i )
  {
    if( i == exclude_index ) continue;
    if( v[i] < min ) { min = v[i]; }
  }
  return min;
}

inline std::string intVecToStr( std::vector<int> v )
{
  std::string str;
  for( unsigned int i = 0; i < v.size(); ++i ) { str += std::to_string( v[i] ) + ' '; }
  return str;
}

struct slNode
{
  int      value;
  slNode * next;

  slNode( int x )
  {
    value = x;
    next  = NULL;
  }
};

class slList
{
public:
  slNode * head;
  slNode * tail;

  slList()
  {
    head = NULL;
    tail = NULL;
  }

  void add( slNode * node )
  {
    if( head == NULL )
    {
      head = node;
      tail = node;
    }
    else
    {
      tail->next = node;
      node->next = NULL;
      tail       = node;
    }
  }

  slNode * get( int index )
  {
    slNode * node = head;
    for( int i = 0; i < index; ++i )
    {
      if( node->next ) { node = node->next; }
      else
      {
        throw "Linked List index out of range";
      }
    }
    return node;
  };
};
