#pragma once

/* MEDIUM
Given an unsigned 8-bit integer, swap its even and odd bits. The 1st and 2nd bit should be swapped, the 3rd and 4th bit
should be swapped, and so on.

For example, 10101010 should be 01010101. 11100010 should be 11010001.

Bonus: Can you do this in one line?
*/

#include <cstdint>

#pragma GCC diagnostic push    // Save the current warning state.
#pragma GCC diagnostic ignored "-Wconversion"
inline std::int8_t     even_odd_bit_swap( std::int8_t bits )
{
  /*
  std::int8_t even_mask = 0b10101010;
  std::int8_t odd_mask  = 0b01010101;
  std::int8_t even      = even_mask & bits;
  std::int8_t odd       = odd_mask & bits;
  even                  = even >> 1;
  odd                   = odd << 1;
  std::int8_t swaped    = ( odd_mask & even ) | ( even_mask & odd );
  return swaped;
  */
  return ( ( ( 0b10101010 & bits ) >> 1 ) & 0b01010101 ) | ( ( ( 0b01010101 & bits ) << 1 ) & 0b10101010 );
}
#pragma GCC diagnostic pop    // Restore warnings to previous state.