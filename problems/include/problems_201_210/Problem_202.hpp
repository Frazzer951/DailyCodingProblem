#ifndef PROBLEMS_201_210_PROBLEM_202_HPP
#define PROBLEMS_201_210_PROBLEM_202_HPP

#pragma once

/* EASY
Write a program that checks whether an integer is a palindrome. For example, 121
is a palindrome, as well as 888. 678 is not a palindrome. Do not convert the
integer into a string.
*/
#include <iostream>
#include <vector>

inline bool isPalindrome( int num ) {
  if ( num == 0 ) return true;

  std::vector<int> nums;

  while ( num > 0 ) {
    nums.push_back( num % 10 );
    num = num / 10;
  }

  for ( int i = 0; i < nums.size(); i++ ) {
    if ( nums[i] != nums[nums.size() - i - 1] ) return false;
  }

  return true;
}
#endif
