/* HARD
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?
*/

#include <iostream>
#include <vector>

int findSum( std::vector<int> v, int index = 0 )
{
  if( v.size() == 0 || index >= int( v.size() ) ) return 0;
  if( index + 1 == v.size() ) return v[index];

  int sum_1 = 0;
  for( unsigned int i = index; i < v.size(); i += 2 )
  {
    sum_1 += v[i];
  }

  int sum_2 = v[index] + findSum( v, index + 3 );

  int sum_3 = findSum( v, index + 1 );

  int sum = ( sum_1 > sum_2 ) ? sum_1 : sum_2;
  sum     = ( sum > sum_3 ) ? sum : sum_3;

  return sum;
}

void testVector( std::vector<int> v )
{
  std::cout << "For the array: ";
  for( unsigned int i = 0; i < v.size(); ++i )
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

  testVector( { 2, 4, 6, 2, 5 } );           // Sum is 13
  testVector( { 5, 1, 1, 5 } );              // Sum is 10
  testVector( { 5, 1, 1, 5, 1, 3 } );        // Sum is 13
  testVector( { 1, 7, 3, 4, 1, 1, 10 } );    // Sum is 21

  return 0;
}