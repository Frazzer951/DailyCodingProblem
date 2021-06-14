#pragma once

/* MEDIUM
Implement division of two positive integers without using the division,
multiplication, or modulus operators. Return the quotient as an integer,
ignoring the remainder.
*/


inline int divide( const int & x, const int & y )
{
  int i       = 0;
  int counter = y;

  while( counter <= x )
  {
    i++;
    counter += y;
  }

  return i;
}

/*
inline int divide( int x, int y )
{
  if( y == 0 )
    return -1;

  int quotient  = 0;
  int power     = 32;            // Assume 32-bit integer
  int yPower    = y << power;    // Initial y^d value is y^32
  int remainder = x;             // Initial remainder is x
  while( remainder >= y )
  {
    while( yPower > remainder )
    {
      yPower >>= 1;
      power -= 1;
    }
    quotient += 1 << power;
    remainder -= yPower;
  }
  return quotient;
}
*/