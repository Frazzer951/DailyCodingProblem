#ifndef PROBLEMS_161_170_PROBLEM_166_HPP
#define PROBLEMS_161_170_PROBLEM_166_HPP


#pragma once

/* MEDIUM
Implement a 2D iterator class. It will be initialized with an array of arrays,
and should implement the following methods:

 * next(): returns the next element in the array of arrays. If there are no more
   elements, raise an exception.
 * has_next(): returns whether or not the iterator still has elements left.

For example, given the input [[1, 2], [3], [], [4, 5, 6]], calling next()
repeatedly should output 1, 2, 3, 4, 5, 6.

Do not use flatten or otherwise clone the arrays. Some of the arrays can be
empty.
*/
#include <stdexcept>
#include <utility>
#include <vector>

class iterator2D
{
private:
  std::vector<std::vector<int>> m_Arr;
  size_t                        outerIndex;
  size_t                        innerIndex;

  bool updateIndex()
  {
    if( outerIndex >= m_Arr.size() ) return false;
    while( innerIndex >= m_Arr[outerIndex].size() )
    {
      outerIndex++;
      innerIndex = 0;
      if( outerIndex >= m_Arr.size() ) return false;
    }
    return true;
  }

public:
  iterator2D( std::vector<std::vector<int>> arr ) : m_Arr( std::move( arr ) ), outerIndex( 0 ), innerIndex( 0 ) {}

  int next()
  {
    if( !updateIndex() ) throw std::out_of_range( "Reached end of 2D Array" );
    innerIndex++;
    return m_Arr[outerIndex][innerIndex - 1];
  }

  bool has_next() { return updateIndex(); }
};
#endif
