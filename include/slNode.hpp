#pragma once

#include <iostream>

template<typename T>
struct slNode
{
  T        value;
  slNode * next;

  slNode( T x, slNode * n = nullptr )
  {
    value = x;
    next  = n;
  }
};

template<typename T>
inline bool operator==( const slNode<T> & lhs, const slNode<T> & rhs )
{
  if( lhs.value != rhs.value ) return false;
  if( lhs.next != nullptr && rhs.next == nullptr ) return false;
  if( lhs.next == nullptr && rhs.next != nullptr ) return false;
  if( lhs.next != nullptr && rhs.next != nullptr ) return *lhs.next == *rhs.next;
  return true;
}

template<typename T>
inline std::ostream & operator<<( std::ostream & os, const slNode<T> & n )
{
  os << n.value;
  if( n.next != nullptr ) { os << " -> " << *n.next; }
  return os;
}

template<typename T>
inline std::ostream & operator<<( std::ostream & os, const slNode<T> * n )
{
  os << n->value;
  if( n->next != nullptr ) { os << " -> " << n->next; }
  return os;
}

template<typename T>
class slList
{
public:
  slNode<T> * head;
  slNode<T> * tail;

  slList()
  {
    head = nullptr;
    tail = nullptr;
  }

  void add( slNode<T> * node )
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

  [[nodiscard]] slNode<T> * get( int index ) const
  {
    slNode<T> * node = head;
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