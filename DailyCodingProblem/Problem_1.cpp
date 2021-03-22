/* EASY
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
*/

#include <iostream>
#include <vector>

bool arrayAddToNum( std::vector<int> arr, int k )
{
  for( unsigned int i = 0; i < arr.size() - 1; ++i )
  {
    for( unsigned int j = i; j < arr.size(); ++j )
    {
      if( arr[i] + arr[j] == k ) return true;
    }
  }
  return false;
}

int prob_1()
{
  std::cout << "\nProblem 1:\n";

  std::string str = ( arrayAddToNum( { 10, 15, 3, 7 }, 17 ) ) ? "True" : "False";

  std::cout << str << std::endl;

  str = ( arrayAddToNum( { 1, 5, 7, 9 }, 11 ) ) ? "True" : "False";
  std::cout << str << std::endl;

  return 0;
}