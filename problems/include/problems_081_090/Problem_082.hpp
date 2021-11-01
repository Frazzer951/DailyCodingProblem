#pragma once

/* EASY
This problem was asked Microsoft.

Using a read7() method that returns 7 characters from a file, implement readN(n)
which reads n characters.

For example, given a file with the content �Hello world�, three read7() returns
�Hello w�, �orld� and then ��.
*/

#include <fstream>
#include <string>
#include <vector>

struct filereader
{
  std::vector<std::string> seven_letter_split;
  int                      pos = 0;

  filereader( const std::string & filename )
  {
    std::ifstream file;
    file.open( filename );

    char        c = ' ';
    int         i = 0;
    std::string tmp;
    while( file.get( c ) )
    {
      if( i == 7 )
      {
        seven_letter_split.push_back( tmp );
        tmp.clear();
        i = 0;
      }
      tmp += c;
      i++;
    }
    seven_letter_split.push_back( std::move( tmp ) );

    file.close();
  }

  std::string read7()
  {
    pos++;
    if( pos > seven_letter_split.size() ) return "";
    return seven_letter_split[pos - 1];
  }
};

inline std::string readN( int n )
{
  filereader filereader( "Problem_082.txt" );

  int         num_needed = n / 7 + 1;
  std::string all;

  for( int i = 0; i < num_needed; i++ ) { all += filereader.read7(); }

  return all.substr( 0, n );
}