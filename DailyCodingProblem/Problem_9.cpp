/* HARD
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

#include <iostream>
#include <vector>

int findSum( std::vector<int> v )
{
  if( v.size() == 0 ) return 0;
  if( v.size() == 1 ) return v[0];

  int sum_1 = 0;
  for( int i = 0; i < v.size(); i += 2 )
  {
    sum_1 += v[i];
  }

  int sum_2 = v[0];
  for( int i = 3; i < v.size(); i += 2 )
  {
    sum_2 += v[i];
  }
  return ( sum_1 > sum_2 ) ? sum_1 : sum_2;
}

void testVector( std::vector<int> v )
{
  std::cout << "For the array: ";
  for( int i = 0; i < v.size(); ++i )
  {
    std::cout << v[i] << ' ';
  }
  int sum = findSum( v );
  std::cout << " the largest sum is " << sum << '\n';
}

int prob_9()
{
  std::cout << "\nProblem 9\n";
  std::cout << "This will only work on the given test cases and specific sceneries\n";
  testVector( { 2, 4, 6, 2, 5 } );
  testVector( { 5, 1, 1, 5 } );

  return 0;
}