#pragma once

/* My Custom Functions */

#include <iostream>
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
  for( int i : v )
  {
    if( i > max ) { max = i; }
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

inline std::string intVecToStr( const std::vector<int> & v )
{
  std::string str;
  for( int i : v ) { str += std::to_string( i ) + ' '; }
  return str;
}

struct slNode
{
  int      value;
  slNode * next;

  slNode( int x, slNode * n = nullptr )
  {
    value = x;
    next  = n;
  }
};

inline bool operator==( const slNode & lhs, const slNode & rhs )
{
  if( lhs.value != rhs.value ) return false;
  if( lhs.next != nullptr && rhs.next == nullptr ) return false;
  if( lhs.next == nullptr && rhs.next != nullptr ) return false;
  if( lhs.next != nullptr && rhs.next != nullptr ) return *lhs.next == *rhs.next;
  return true;
}

inline std::ostream & operator<<( std::ostream & os, const slNode & n )
{
  os << n.value;
  if( n.next != nullptr ) { os << " -> " << *n.next; }
  return os;
}

inline std::ostream & operator<<( std::ostream & os, const slNode * n )
{
  os << n->value;
  if( n->next != nullptr ) { os << " -> " << n->next; }
  return os;
}

class slList
{
public:
  slNode * head;
  slNode * tail;

  slList()
  {
    head = nullptr;
    tail = nullptr;
  }

  void add( slNode * node )
  {
    if( head == nullptr )
    {
      head = node;
      tail = node;
    }
    else
    {
      tail->next = node;
      node->next = nullptr;
      tail       = node;
    }
  }

  [[nodiscard]] slNode * get( int index ) const
  {
    slNode * node = head;
    for( int i = 0; i < index; ++i )
    {
      if( node->next != nullptr ) { node = node->next; }
      else
      {
        throw "Linked List index out of range";
      }
    }
    return node;
  };
};

struct btNode
{
  char     value;
  btNode * left;
  btNode * right;

  btNode( char x )
  {
    value = x;
    left  = nullptr;
    right = nullptr;
  }
};

struct ibtNode
{
  int       value;
  ibtNode * left;
  ibtNode * right;

  ibtNode( int x, ibtNode * _left = nullptr, ibtNode * _right = nullptr )
  {
    value = x;
    left  = _left;
    right = _right;
  }
};

inline std::string inorder( const ibtNode * root )
{
  std::string s;
  if( root == nullptr ) { return s; }

  s += inorder( root->left ) + " ";
  s += std::to_string( root->value ) + " ";
  s += inorder( root->right );

  return s;
}

inline std::ostream & operator<<( std::ostream & os, const ibtNode & n )
{
  os << inorder( &n );
  return os;
}

inline bool operator==( const ibtNode & lhs, const ibtNode & rhs )
{
  if( lhs.value != rhs.value ) return false;
  if( lhs.left == nullptr && rhs.left != nullptr ) return false;
  if( lhs.left != nullptr && rhs.left == nullptr ) return false;
  if( lhs.right == nullptr && rhs.right != nullptr ) return false;
  if( lhs.right != nullptr && rhs.right == nullptr ) return false;
  if( lhs.left == nullptr && lhs.right == nullptr ) return true;
  if( lhs.left != nullptr && lhs.right == nullptr ) return *lhs.left == *rhs.left;
  if( lhs.left == nullptr && lhs.right != nullptr ) return *lhs.right == *rhs.right;
  return *lhs.left == *rhs.left && *lhs.right == *rhs.right;
}


inline bool operator==( const btNode & lhs, const btNode & rhs )
{
  return lhs.value == rhs.value && lhs.left == rhs.left && lhs.right == rhs.right;
}

inline int sum( const std::vector<int> & v )
{
  int sum = 0;

  for( int x : v ) { sum += x; }

  return sum;
}