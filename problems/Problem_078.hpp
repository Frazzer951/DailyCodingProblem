#pragma once

/* MEDIUM
Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.
*/

#include <forward_list>
#include <vector>

inline int getSmallest( std::vector<std::forward_list<int>> & lists )
{
  std::pair<int, int> smallest( 0, lists[0].front() );

  for( int i = 0; i < lists.size(); i++ )
  {
    if( lists[i].front() < smallest.second )
    {
      smallest.first  = i;
      smallest.second = lists[i].front();
    }
  }

  lists[smallest.first].pop_front();

  return smallest.second;
}

inline void remove_empty_lists( std::vector<std::forward_list<int>> & lists )
{
  auto i = lists.begin();
  while( i != lists.end() )
  {
    if( i->empty() )
      i = lists.erase( i );
    else
      i++;
  }
}

inline std::forward_list<int> combine_lists( std::vector<std::forward_list<int>> lists )
{
  std::forward_list<int> combined_list;

  while( !lists.empty() )
  {
    combined_list.push_front( getSmallest( lists ) );
    remove_empty_lists( lists );
  }

  combined_list.reverse();

  return combined_list;
}