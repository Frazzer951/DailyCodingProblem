#ifndef PROBLEMS_241_250_PROBLEM_242_HPP
#define PROBLEMS_241_250_PROBLEM_242_HPP

#pragma once

/* HARD
You are given an array of length 24, where each element represents the number of
new subscribers during the corresponding hour. Implement a data structure that
efficiently supports the following:

 * update(hour: int, value: int): Increment the element at index hour by value.
 * query(start: int, end: int): Retrieve the number of subscribers that have
   signed up between start and end (inclusive).

You can assume that all values get cleared at the end of the day, and that you
will not be asked for start and end values that wrap around midnight.
*/
class sub_hour_counter {
  int subs[24] = { 0 };

public:
  void update( int hour, int value ) { subs[hour] += value; }
  int  query( int start, int end ) {
    int sum = 0;
    for ( int i = start; i <= end; i++ ) sum += subs[i];
    return sum;
  }
};
#endif
