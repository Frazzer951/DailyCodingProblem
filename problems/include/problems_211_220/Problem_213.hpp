#ifndef PROBLEMS_211_220_PROBLEM_213_HPP
#define PROBLEMS_211_220_PROBLEM_213_HPP

#pragma once

/* MEDIUM
Given a string of digits, generate all possible valid IP address combinations.

IP addresses must follow the format A.B.C.D, where A, B, C, and D are numbers
between 0 and 255. Zero-prefixed numbers, such as 01 and 065, are not allowed,
except for 0 itself.

For example, given "2542540123", you should return ['254.25.40.123',
'254.254.0.123'].
*/

#include <string>
#include <vector>

inline std::vector<std::string> generateIpAddresses( const std::string & s, std::vector<std::string> parts = {} )
{
  std::vector<std::string> addresses;

  if( parts.size() > 4 ) return {};

  if( s.empty() )
  {
    if( parts.size() == 4 )
    {
      std::string tmp;
      for( int i = 0; i < 4; i++ )
      {
        tmp += parts[i];
        if( i != 3 ) tmp += '.';
      }
      return { tmp };
    }
    return {};
  }

  std::vector<std::string> tmpParts = parts;
  tmpParts.push_back( s.substr( 0, 1 ) );
  std::vector<std::string> address = generateIpAddresses( s.substr( 1 ), tmpParts );
  addresses.insert( addresses.end(), address.begin(), address.end() );

  if( s.size() > 1 )
  {
    int num = atoi( s.substr( 0, 2 ).c_str() );
    if( 10 <= num && num <= 99 )
    {
      tmpParts = parts;
      tmpParts.push_back( s.substr( 0, 2 ) );
      address = generateIpAddresses( s.substr( 2 ), tmpParts );
      addresses.insert( addresses.end(), address.begin(), address.end() );
    }
  }

  if( s.size() > 2 )
  {
    int num = atoi( s.substr( 0, 3 ).c_str() );
    if( 100 <= num && num <= 255 )
    {
      tmpParts = parts;
      tmpParts.push_back( s.substr( 0, 3 ) );
      address = generateIpAddresses( s.substr( 3 ), tmpParts );
      addresses.insert( addresses.end(), address.begin(), address.end() );
    }
  }

  return addresses;
}
#endif
