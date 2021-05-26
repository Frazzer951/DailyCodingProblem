#pragma once

/* HARD
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or
negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5
and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

#include <iostream>
#include <vector>

// New Solution from given solution
inline int largest_non_adjacent( std::vector<int> v )
{
  if( v.size() <= 2 ) { return std::max( 0, v[0] ); }

  int max_excluding_last = std::max( 0, v[0] );
  int max_including_last = std::max( max_excluding_last, v[1] );

  for( unsigned int i = 2; i < v.size(); ++i )
  {
    int prev_max_including_last = max_including_last;

    max_including_last = std::max( max_including_last, max_excluding_last + v[i] );
    max_excluding_last = prev_max_including_last;
  }

  return std::max( max_including_last, max_excluding_last );
}

// Old Solution
inline int findSum( std::vector<int> v, int index = 0 )
{
  if( v.empty() || index >= int( v.size() ) ) return 0;
  if( index + 1 == v.size() ) return v[index];

  int sum_1 = 0;
  for( unsigned int i = index; i < v.size(); i += 2 ) { sum_1 += v[i]; }

  int sum_2 = v[index] + findSum( v, index + 3 );

  int sum_3 = findSum( v, index + 1 );

  int sum = ( sum_1 > sum_2 ) ? sum_1 : sum_2;
  sum     = ( sum > sum_3 ) ? sum : sum_3;

  return sum;
}

inline void testVector( std::vector<int> v )
{
  std::cout << "For the array: ";
  for( int i : v ) { std::cout << i << ' '; }
  int sum = largest_non_adjacent( v );
  std::cout << " the largest sum is " << sum << '\n';
}

inline int prob_9()
{
  std::cout << "\nProblem 9\n";
  std::cout << "This will only work on the given test cases and specific sceneries\n";

  testVector( { 2, 4, 6, 2, 5 } );           // Sum is 13
  testVector( { 5, 1, 1, 5 } );              // Sum is 10
  testVector( { 5, 1, 1, 5, 1, 3 } );        // Sum is 13
  testVector( { 1, 7, 3, 4, 1, 1, 10 } );    // Sum is 21

  return 0;
}