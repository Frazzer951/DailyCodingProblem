#pragma once

/* MEDIUM
Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, and deserialize(s),
which deserializes the string back into the tree.

For example, given the following SerNode class

class SerNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
The following test should pass:

node = SerNode('root', SerNode('left', SerNode('left.left')), SerNode('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'
*/

#include <iostream>
#include <string>
#include <utility>

class SerNode
{
public:
  std::string _val;
  SerNode *   _left;
  SerNode *   _right;

  SerNode( std::string val )
  {
    _val   = std::move( val );
    _left  = nullptr;
    _right = nullptr;
  }
  SerNode( std::string val, SerNode * left )
  {
    _val   = std::move( val );
    _left  = left;
    _right = nullptr;
  }
  SerNode( std::string val, SerNode * left, SerNode * right )
  {
    _val   = std::move( val );
    _left  = left;
    _right = right;
  }

  std::string value() const { return _val; }

  SerNode left() const { return *_left; }

  SerNode right() const { return *_right; }

  std::string serialize_node() const
  {
    std::string node_str = _val + ":{";
    if( _left != nullptr ) { node_str += _left->serialize_node(); }
    if( _right != nullptr ) { node_str += ',' + _right->serialize_node(); }
    node_str += "}";
    return node_str;
  }
};

inline std::string serialize( SerNode root ) { return root.serialize_node(); }

inline SerNode * deserialize( const std::string & str )
{
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

  std::string node_name = str.substr( 0, colon_index );

  std::string nodes = str.substr( colon_index + 1 );

  if( nodes.size() == 2 ) { return new SerNode( node_name ); }    // If there are no sub nodes return empty node

  auto comma_index = nodes.find( ',' );

  if( comma_index == -1 )
  {
    SerNode * left        = deserialize( nodes.substr( 1, nodes.size() - 2 ) );
    auto *    return_node = new SerNode( node_name, left );
    return return_node;
  }
  else
  {
    SerNode * left        = deserialize( nodes.substr( 1, comma_index - 1 ) );
    SerNode * right       = deserialize( nodes.substr( comma_index + 1, nodes.size() - comma_index - 2 ) );
    auto *    return_node = new SerNode( node_name, left, right );
    return return_node;
  }

  return new SerNode( "Error" );
}

inline int prob_3()
{
  std::cout << "\nProblem 3:\n";

  SerNode leftleft( "left.left" );
  SerNode left( "left", &leftleft );
  SerNode right( "right" );
  SerNode root( "root", &left, &right );

  std::string serialized_root = serialize( root );

  std::cout << "Root serialized: " << serialized_root << '\n';

  SerNode deser_root = *deserialize( serialized_root );

  std::cout << "Original root left.left:    " << root.left().left().value() << '\n';
  std::cout << "Deserialize root left.left: " << deser_root.left().left().value() << '\n';

  return 0;
}