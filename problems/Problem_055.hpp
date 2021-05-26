#pragma once

/* EASY
Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.

restore(short), which expands the shortened string into the original url. If no such shortened string exists, return
null.

Hint: What if we enter the same URL twice?
*/

#include <cstdlib>
#include <map>
#include <string>

class URLShortener
{
  static std::string _generate_short()
  {
    char        values[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string random;
    for( int i = 0; i < 6; i++ )
    {
      int index = rand() % 37;
      random += values[index];
    }
    return random;
  }

  std::string _generate_unused_short()
  {
    std::string t = _generate_short();
    while( short_to_url.find( t ) != short_to_url.end() ) t = _generate_short();
    return t;
  }

public:
  std::map<std::string, std::string> short_to_url;
  std::map<std::string, std::string> url_to_short;

  std::string shorten( const std::string & url )
  {
    std::string shortened = _generate_unused_short();
    if( url_to_short.find( url ) != url_to_short.end() ) return url_to_short[url];
    short_to_url[shortened] = url;
    url_to_short[url]       = shortened;
    return shortened;
  }

  std::string restore( const std::string & shortened ) { return short_to_url[shortened]; }
};