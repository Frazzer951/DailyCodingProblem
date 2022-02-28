#ifndef PROBLEMS_151_160_PROBLEM_152_HPP
#define PROBLEMS_151_160_PROBLEM_152_HPP


#pragma once

/* MEDIUM
You are given n numbers as well as n probabilities that sum up to 1. Write a
function to generate one of the numbers with its corresponding probability.

For example, given the numbers [1, 2, 3, 4] and probabilities [0.1, 0.5, 0.2,
0.2], your function should return 1 10% of the time, 2 50% of the time, and 3
and 4 20% of the time.

You can generate random numbers between 0 and 1 uniformly.
*/
#include <cstdlib>
#include <ctime>
#include <vector>

inline int randomProb( std::vector<int> nums, std::vector<double> probs )
{
  srand( (unsigned) time( nullptr ) );

  double random = (double) rand() / RAND_MAX;

  int    i    = 0;
  double prob = 0;
  while( i < probs.size() )
  {
    prob += probs[i];
    if( random < prob ) return nums[i];
    i++;
  }

  return 0;
}
#endif
