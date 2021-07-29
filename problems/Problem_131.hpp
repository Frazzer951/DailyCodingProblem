#pragma once

/* MEDIUM
Given the head to a singly linked list, where each node also has a “random” pointer that points to anywhere in the
linked list, deep clone the list.
*/

#include <map>

#include "Futils.hpp"

struct rslNode
{
  int       value;
  rslNode * next;
  rslNode * random;

  rslNode( int x, rslNode * n = nullptr, rslNode * r = nullptr )
  {
    value  = x;
    next   = n;
    random = r;
  }
};
inline std::ostream & operator<<( std::ostream & os, const rslNode & n )
{
  os << n.value;
  if( n.random != nullptr ) { os << "\n\trandom: -> " << n.random->value; }
  if( n.next != nullptr ) { os << "\n\tnext -> " << *n.next; }
  return os;
}
inline bool operator==( const rslNode & lhs, const rslNode & rhs )
{
  if( lhs.value != rhs.value ) return false;
  if( lhs.next != nullptr && rhs.next == nullptr ) return false;
  if( lhs.next == nullptr && rhs.next != nullptr ) return false;
  if( lhs.next != nullptr && rhs.next != nullptr )
    if( !( *lhs.next == *rhs.next ) ) return false;
  if( lhs.random != nullptr && rhs.random == nullptr ) return false;
  if( lhs.random == nullptr && rhs.random != nullptr ) return false;
  if( lhs.random != nullptr && rhs.random != nullptr )
    if( !( *lhs.random == *rhs.random ) ) return false;

  return true;
}
