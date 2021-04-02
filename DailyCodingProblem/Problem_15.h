#pragma once

//int prob_15();

/* MEDIUM
Given a stream of elements too large to store in memory,
pick a random element from the stream with uniform probability.
*/

#include <iostream>
#include <vector>

int randElement( std::vector<int> v )
{
  int index = rand() % v.size();

  return v[index];
}

int prob_15()
{
  std::cout << "\nProblem 15\n";

  std::cout << "A random element from the list [10, 15, 12, 67, 21, 43] is " << randElement( { 10, 15, 12, 67, 21, 43 } ) << ".\n";
  std::cout << "A random element from the list [10, 15, 12, 67, 21, 43] is " << randElement( { 10, 15, 12, 67, 21, 43 } ) << ".\n";
  std::cout << "A random element from the list [10, 15, 12, 67, 21, 43] is " << randElement( { 10, 15, 12, 67, 21, 43 } ) << ".\n";
  std::cout << "A random element from the list [10, 15, 12, 67, 21, 43] is " << randElement( { 10, 15, 12, 67, 21, 43 } ) << ".\n";

  return 0;
}