#pragma once

/* MEDIUM
On our special chessboard, two bishops attack each other if
they share the same diagonal. This includes bishops that have
another bishop located between them, i.e. bishops can attack
through pieces.

You are given N bishops, represented as (row, column) tuples
on a M by M chessboard. Write a function to count the number
of pairs of bishops that attack each other. The ordering of
the pair doesn't matter: (1, 2) is considered the same as (2, 1).

For example, given M = 5 and the list of bishops:

(0, 0)
(1, 2)
(2, 2)
(4, 0)
The board would look like this:

[b 0 0 0 0]
[0 0 b 0 0]
[0 0 b 0 0]
[0 0 0 0 0]
[b 0 0 0 0]
You should return 2, since bishops 1 and 3 attack each other, as well as bishops 3 and 4.
*/

#include <vector>

inline bool is_attacking( std::pair<int, int> bishop0, std::pair<int, int> bishop1 )
{
  auto & [r0, c0] = bishop0;
  auto & [r1, c1] = bishop1;
  return abs( r1 - r0 ) == abs( c1 - c0 );
}

inline int pairs( std::vector<std::pair<int, int>> bishops, int /*m*/ )
{
  int count = 0;
  for( int i = 0; i < bishops.size(); i++ )
  {
    for( int j = i + 1; j < bishops.size(); j++ )
    {
      count += static_cast<int>( is_attacking( bishops[i], bishops[j] ) );
    }
  }
  return count;
}
