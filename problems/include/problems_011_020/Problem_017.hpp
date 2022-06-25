#ifndef PROBLEMS_011_020_PROBLEM_017_HPP
#define PROBLEMS_011_020_PROBLEM_017_HPP


#pragma once

/* HARD
Suppose we represent our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext


The directory dir contains an empty sub-directory subdir1 and a sub-directory
subdir2 containing a file file.ext.

The string
"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext


The directory dir contains two sub-directories subdir1 and subdir2. subdir1
contains a file file1.extand an empty second-level sub-directory subsubdir1.
subdir2 contains a second-level sub-directorysubsubdir2 containing a file
file2.ext.

We are interested in finding the longest (number of characters) absolute path to
a file within our file system. For example, in the second example above, the
longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is
32 (not including the double quotes).

Given a string representing the file system in the above format, return the
length of the longest absolute path to a file in the abstracted file system. If
there is no file in the system, return 0.

Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.
*/

#include <algorithm>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "Futils.hpp"

inline bool is_file( const std::string & f ) { return f.find( '.' ) != std::string::npos; }

inline std::string find_longest_filepath( std::string filesystem )
{
  std::vector<std::string>   file_paths = split( std::move( filesystem ), '\n' );
  std::map<int, std::string> depths;
  std::vector<std::string>   filepaths;

  for( auto path : file_paths )
  {
    int depth = std::count( path.begin(), path.end(), '\t' );
    path.erase( std::remove( path.begin(), path.end(), '\t' ), path.end() );
    if( is_file( path ) )
    {
      std::string filepath;
      for( int i = 0; i < depth; i++ )
      {
        filepath += depths[i];
        filepath += '/';
      }

      filepath += path;
      filepaths.push_back( filepath );
    }
    else
    {
      depths[depth] = path;
    }
  }
  std::string longest = filepaths[0];
  for( const auto & filepath : filepaths )
  {
    if( filepath.size() > longest.size() )
    {
      longest = filepath;
    }
  }
  return longest;
}

#endif
