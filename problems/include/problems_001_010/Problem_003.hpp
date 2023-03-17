#ifndef PROBLEMS_001_010_PROBLEM_003_HPP
#define PROBLEMS_001_010_PROBLEM_003_HPP

#pragma once

/* MEDIUM
Given the root to a binary tree, implement serialize(root), which serializes the
tree into a string, and deserialize(s), which deserializes the string back into
the tree.

For example, given the following Node class

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


The following test should pass:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
*/
#include <iostream>
#include <string>
#include <utility>

class SerNode {
public:
  std::string _val;
  SerNode    *_left;
  SerNode    *_right;

  SerNode( std::string val ) : _val( std::move( val ) ), _left( nullptr ), _right( nullptr ) {}
  SerNode( std::string val, SerNode *left ) : _val( std::move( val ) ), _left( left ), _right( nullptr ) {}
  SerNode( std::string val, SerNode *left, SerNode *right ) : _val( std::move( val ) ), _left( left ), _right( right ) {}

  [[nodiscard]] std::string value() const { return _val; }

  [[nodiscard]] SerNode left() const { return *_left; }

  [[nodiscard]] SerNode right() const { return *_right; }

  [[nodiscard]] std::string serialize_node() const {
    std::string node_str = _val + ":{";
    if ( _left != nullptr ) { node_str += _left->serialize_node(); }
    if ( _right != nullptr ) { node_str += ',' + _right->serialize_node(); }
    node_str += "}";
    return node_str;
  }
};

inline std::string serialize( const SerNode &root ) { return root.serialize_node(); }

inline SerNode *deserialize( const std::string &str ) {
  // Example Serialized Tree
  // root:{left:{left.left:{}},right:{}}

  /*
    Steps:
      Find SerNode Name
        Find Left SerNode
          If node has sub nodes recurse, else return node with just name
        Find Right SerNode
          If node has sub nodes recurse, else return node with just name
  */

  auto colon_index = str.find( ':' );

  std::string const node_name = str.substr( 0, colon_index );

  std::string const nodes = str.substr( colon_index + 1 );

  if ( nodes.size() == 2 ) { return new SerNode( node_name ); }    // If there are no sub nodes return empty node

  auto comma_index = nodes.find( ',' );

  if ( comma_index == -1 ) {
    SerNode *left        = deserialize( nodes.substr( 1, nodes.size() - 2 ) );
    auto    *return_node = new SerNode( node_name, left );
    return return_node;
  }

  SerNode *left        = deserialize( nodes.substr( 1, comma_index - 1 ) );
  SerNode *right       = deserialize( nodes.substr( comma_index + 1, nodes.size() - comma_index - 2 ) );
  auto    *return_node = new SerNode( node_name, left, right );
  return return_node;
}

inline int prob_3() {
  std::cout << "\nProblem 3:\n";

  SerNode leftleft( "left.left" );
  SerNode left( "left", &leftleft );
  SerNode right( "right" );
  SerNode const root( "root", &left, &right );

  std::string const serialized_root = serialize( root );

  std::cout << "Root serialized: " << serialized_root << '\n';

  SerNode const deser_root = *deserialize( serialized_root );

  std::cout << "Original root left.left:    " << root.left().left().value() << '\n';
  std::cout << "Deserialize root left.left: " << deser_root.left().left().value() << '\n';

  return 0;
}
#endif
