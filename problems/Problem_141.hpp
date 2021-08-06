#pragma once

/* HARD
Implement 3 stacks using a single list:

class Stack:
    def __init__(self):
        self.list = []

    def pop(self, stack_number):
        pass

    def push(self, item, stack_number):
        pass
*/

#include <vector>

class Stack
{
  std::size_t      size;
  std::size_t      s0;
  std::size_t      s1;
  std::size_t      s2;
  std::vector<int> list;

public:
  Stack()
  {
    size = 10;
    list = std::vector( size, 0 );
    s0   = 0;                  // Grows up
    s1   = list.size() / 2;    // Grows up
    s2   = list.size() - 1;    // Grows down
  }

  int pop( int stack_number )
  {
    if( stack_number == 0 )
    {
      s0--;
      return list[s0];
    }
    else if( stack_number == 1 )
    {
      s1--;
      return list[s1];
    }
    else
    {
      s2++;
      return list[s2];
    }
  }

  bool is_resize_needed() { return s0 == list.size() / 2 || s1 > s2; }

  void resize( std::size_t new_size )
  {
    std::vector<int> prev_list = list;
    std::size_t      prev_s0   = s0;
    std::size_t      prev_s1   = s1;
    std::size_t      prev_s2   = s2;

    list = std::vector( new_size, 0 );
    s0   = 0;                  // Grows up
    s1   = list.size() / 2;    // Grows up
    s2   = list.size() - 1;    // Grows down
    size = new_size;

    for( std::size_t i = 0; i < prev_s0; i++ ) push( prev_list[i], 0 );

    for( std::size_t i = prev_list.size() / 2; i < prev_s1; i++ ) push( prev_list[i], 1 );

    for( std::size_t i = prev_list.size() - 1; i > prev_s2; i-- ) push( prev_list[i], 2 );
  }

  void push( int item, int stack_number )
  {
    if( stack_number == 0 )
    {
      list[s0] = item;
      s0++;
    }
    else if( stack_number == 1 )
    {
      list[s1] = item;
      s1++;
    }
    else
    {
      list[s2] = item;
      s2--;
    }
    if( is_resize_needed() ) resize( size * 2 );
  }
};