#pragma once

/* EASY
Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.

restore(short), which expands the shortened string into the original url. If no such shortened string exists, return
null.

Hint: What if we enter the same URL twice?
*/

#include <string>

/*
class URLShortener:
    def __init__(self):
        self.short_to_url = {}
        self.url_to_short = {}

    def _generate_short(self):
        return ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(6))

    def _generate_unused_short(self):
        t = self._generate_short()
        while t in self.short_to_url:
            t = self._generate_short()
        return t

    def shorten(self, url):
        short = self._generate_unused_short()
        if url in self.url_to_short:
            return self.url_to_short[url]
        self.short_to_url[short] = url
        self.url_to_short[url] = short
        return short

    def restore(self, short):
        return self.short_to_url.get(short, None)
*/

#include <map>

class URLShortener
{
  std::string _generate_short()
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

  std::string shorten( std::string url )
  {
    std::string shortened = _generate_unused_short();
    if( url_to_short.find( url ) != url_to_short.end() ) return url_to_short[url];
    short_to_url[shortened] = url;
    url_to_short[url]       = shortened;
    return shortened;
  }

  std::string restore( std::string shortened ) { return short_to_url[shortened]; }
};