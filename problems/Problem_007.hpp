#pragma once

/* MEDIUM
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/

#include <iostream>
#include <string>

inline int num_encodings( std::string s )
{
  if( s[0] == '0' ) return 0;
  if( s.size() <= 1 )
    return 1;

  int total = 0;

  if( std::stoi( s.substr( 0, 2 ) ) <= 26 ) total += num_encodings( s.substr( 2 ) );

  total += num_encodings( s.substr( 1 ) );
  return total;
}

inline int prob_7()
{
  std::cout << "\nProblem 7\n";

  std::cout << "1 can be encoded " << num_encodings( "1" ) << " ways. \n";
  std::cout << "11 can be encoded " << num_encodings( "11" ) << " ways. \n";
  std::cout << "111 can be encoded " << num_encodings( "111" ) << " ways. \n";
  std::cout << "1111 can be encoded " << num_encodings( "1111" ) << " ways. \n";
  std::cout << "001 can be encoded " << num_encodings( "001" ) << " ways. \n";

  return 0;
}