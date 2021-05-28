#pragma once

/* HARD
An XOR linked list is a more memory efficient doubly linked list.
Instead of each node holding next and prev fields, it holds a field named both,
which is an XOR of the next node and the previous node. Implement an XOR linked list;
it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.

If using a language that has no pointers (such as Python), you can assume you have access to get_pointer and
dereference_pointer functions that converts between nodes and memory addresses.
*/
#include <iostream>

struct xNode
{
  int     val;
  xNode * both;

  xNode( int value )
  {
    val  = value;
    both = nullptr;
  }
};

inline xNode * xorNode( xNode * a, xNode * b ) { return (xNode *) ( (uintptr_t) a ^ (uintptr_t) b ); }

class xor_list
{
public:
  xNode * head;
  xNode * tail;

  xor_list()
  {
    head = nullptr;
    tail = nullptr;
  }

  void add( xNode * node )
  {
    if( head == nullptr )
    {
      head = node;
      tail = node;
    }
    else
    {
      tail->both = xorNode( node, tail->both );
      node->both = tail;
      tail       = node;
    }
  }

  [[nodiscard]] xNode * get( int index ) const
  {
    xNode * prev_id = nullptr;
    xNode * node    = head;
    for( int i = 0; i < index; ++i )
    {
      xNode * next_id = xorNode( prev_id, node->both );

      if( next_id != nullptr )
      {
        prev_id = node;
        node    = next_id;
      }
      else
      {
        throw "Linked List index out of range";
      }
    }
    return node;
  };
};

inline void printAtIndex( xor_list list, int index )
{
  std::cout << "The index " << index << " contains the value " << list.get( index )->val << '\n';
}

inline int prob_6()
{
  std::cout << "\nProblem 6:\n";

  xor_list list;

  list.add( new xNode( 5 ) );
  list.add( new xNode( 3 ) );
  list.add( new xNode( 18 ) );

  printAtIndex( list, 0 );
  printAtIndex( list, 1 );
  printAtIndex( list, 2 );

  return 0;
}