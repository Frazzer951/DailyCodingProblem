#pragma once

/* EASY
Determine whether a doubly linked list is
a palindrome. What if it’s singly linked?

For example, 1 -> 4 -> 3 -> 4 -> 1 returns True
while 1 -> 4 returns False.
*/

#include <list>

inline bool palindromeList( std::list<int> l )
{
  std::vector<int> elements;

  for( int i : l )
    elements.push_back( i );

  int i = 0;
  for( auto it = l.rbegin(); it != l.rend(); ++it )
  {
    if( elements[i] != *it )
      return false;
    i++;
  }
  return true;
}
