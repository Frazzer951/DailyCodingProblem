#ifndef PROBLEMS_221_230_PROBLEM_227_HPP
#define PROBLEMS_221_230_PROBLEM_227_HPP

#pragma once

/* EASY
Boggle is a game played on a 4 x 4 grid of letters. The goal is to find as many
words as possible that can be formed by a sequence of adjacent letters in the
grid, using each cell at most once. Given a game board and a dictionary of valid
words, implement a Boggle solver.
*/

#include <map>
#include <set>
#include <string>
#include <vector>

inline std::vector<std::pair<int, int>> get_neighbors( std::pair<int, int> location, int grid_size = 4 )
{
  int i = location.first;
  int j = location.second;

  std::vector<std::pair<int, int>> possible_neighbors = { { i - 1, j - 1 }, { i - 1, j },    { i - 1, j + 1 },
                                                          { i, j - 1 },     { i, j + 1 },    { i + 1, j - 1 },
                                                          { i + 1, j },     { i + 1, j + 1 } };

  std::vector<std::pair<int, int>> neighbors;

  for( auto & neighbor : possible_neighbors )
  {
    if( neighbor.first >= 0 && neighbor.first < grid_size && neighbor.second >= 0 && neighbor.second < grid_size )
    {
      neighbors.push_back( neighbor );
    }
  }

  return neighbors;
}

inline void search( std::pair<int, int> location, std::vector<std::vector<std::string>> grid,
                    std::set<std::pair<int, int>> & visited, std::string word, std::set<std::string> & result,
                    std::vector<std::string> dictionary )
{
  visited.insert( location );
  if( std::find( dictionary.begin(), dictionary.end(), word ) != dictionary.end() ) { result.insert( word ); }

  for( auto neighbor : get_neighbors( location ) )
  {
    if( visited.find( neighbor ) == visited.end() )
    {
      word += grid[neighbor.first][neighbor.second];
      search( neighbor, grid, visited, word, result, dictionary );
      word.pop_back();
      visited.erase( neighbor );
    }
  }
}


inline std::vector<std::string> boggle( std::vector<std::vector<std::string>> grid,
                                        const std::vector<std::string> &      dictionary )
{
  std::set<std::pair<int, int>> visited;
  std::set<std::string>         result;

  for( int row = 0; row < grid.size(); row++ )
  {
    for( int col = 0; col < grid.size(); col++ )
    {
      std::string word = grid[row][col];
      search( std::make_pair( row, col ), grid, visited, word, result, dictionary );
    }
  }

  return std::vector( result.begin(), result.end() );
}

#endif
