#pragma once

/* HARD
Alice wants to join her school's Probability Student Club. Membership dues are computed via one of two simple
probabilistic games.

The first game: roll a die repeatedly. Stop rolling once you get a five followed by a six. Your number of rolls is the
amount you pay, in dollars.

The second game: same, except that the stopping condition is a five followed by a five.

Which of the two games should Alice elect to play? Does it even matter? Write a program to simulate the two games and
calculate their expected value.
*/

#include <ctime>
#include <random>
#include <vector>

inline int diceSim( std::vector<int> winningCondition )
{
  srand( (unsigned int) time( nullptr ) );

  bool won       = false;
  int  index     = 0;
  int  rollCount = 0;
  while( !won )
  {
    int roll = ( rand() % 6 ) + 1;
    rollCount++;
    if( roll == winningCondition[index] )
    {
      index++;
      if( index >= winningCondition.size() ) won = true;
    }
    else
    {
      index = 0;
    }
  }
  return rollCount;
}