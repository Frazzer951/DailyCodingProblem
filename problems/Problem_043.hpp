#pragma once

/* EASY
Implement a stack that has the following methods:

        push(val), which pushes an element onto the stack

        pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then
        it should throw an error or return null.

        max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it
        should throw an error or return null.

Each method should run in constant time.
*/

#include <exception>

class stackEmptyExcept : public std::exception
{
  [[nodiscard]] const char * what() const noexcept override { return "My exception happened"; }
} stackEmpty;

struct stackNode
{
  int         val;
  stackNode * prev = nullptr;

  stackNode( int value, stackNode * _prev = nullptr ) :
    val( value ), prev( _prev ) {}
};

struct stack
{
  stackNode * top = nullptr;

  void push( int val )
  {
    auto * newNode = new stackNode( val, top );
    top                 = newNode;
  }

  int pop()
  {
    if( top == nullptr ) throw stackEmpty;

    stackNode * topNode = top;
    top                 = top->prev;
    int val             = topNode->val;
    delete topNode;

    return val;
  }

  int getMax() const
  {
    if( top == nullptr ) throw stackEmpty;

    stackNode * cur    = top;
    int         maxVal = cur->val;
    while( cur->prev != nullptr )
    {
      if( cur->val > maxVal ) { maxVal = cur->val; }
      cur = cur->prev;
    }
    return maxVal;
  }
};