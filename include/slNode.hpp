#pragma once

#include <iostream>
#include <vector>

template<typename T>
struct slNode
{
  T        value;
  slNode * next;

  slNode( T x, slNode * n = nullptr ) : value( x ), next( n ) {}

  slNode( std::vector<T> l ) : value( l[0] )
  {
    if( l.size() > 1 ) next = new slNode( std::vector<T>( l.begin() + 1, l.end() ) );
    else
      next = nullptr;
  }

  ~slNode() { delete next; }
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
  slNode<T> * head { nullptr };
  slNode<T> * tail { nullptr };

  slList() = default;

  slList( std::vector<T> l ) : head( nullptr ), tail( nullptr )
  {
    for( T i : l ) { add( new slNode( i ) ); }
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

  void insert( slNode<T> * node )
  {
    if( head == nullptr )
    {
      head = node;
      tail = node;
    }
    else
    {
      node->next = head;
      head       = node;
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

template<typename T>
inline bool operator==( const slList<T> & lhs, const slList<T> & rhs )
{
  if( lhs.head != nullptr && rhs.head == nullptr ) return false;
  if( lhs.head == nullptr && rhs.head != nullptr ) return false;
  if( lhs.head != nullptr && rhs.head != nullptr ) return *lhs.head == *rhs.head;
  return true;
}

template<typename T>
inline std::ostream & operator<<( std::ostream & os, const slList<T> & n )
{
  os << n.head;
  return os;
}