#pragma once

#include <iostream>

template<typename T>
struct btNode
{
  T        value;
  btNode * left;
  btNode * right;

  btNode( T x, btNode<T> * _left = nullptr, btNode<T> * _right = nullptr ) : value( x ), left( _left ), right( _right )
  {}
};

template<typename T>
inline std::string inorder( const btNode<T> * root )
{
  std::string s;
  if( root == nullptr ) { return s; }

  s += inorder( root->left ) + " ";
  s += std::to_string( root->value ) + " ";
  s += inorder( root->right );

  return s;
}

template<typename T>
inline std::ostream & operator<<( std::ostream & os, const btNode<T> & n )
{
  os << inorder( &n );
  return os;
}

template<typename T>
inline bool operator==( const btNode<T> & lhs, const btNode<T> & rhs )
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