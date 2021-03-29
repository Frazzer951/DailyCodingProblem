/* HARD
Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
*/

#include <iostream>
#include <map>

char findMin(std::map<char,int> m){
  char key;
  int min = m.begin()->second;
  for(std::pair<char, int> c : m){
    if(c.second < min){
      key = c.first;
      min = c.second;
    }
  }
  return key;
}

/*
def longest_substring_with_k_distinct_characters(s, k):
    if k == 0:
        return 0

    # Keep a running window
    bounds = (0, 0)
    h = {}
    max_length = 0
    for i, char in enumerate(s):
        h[char] = i
        if len(h) <= k:
            new_lower_bound = bounds[0] # lower bound remains the same
        else:
            # otherwise, pop last occurring char
            key_to_pop = min(h, key=h.get)
            new_lower_bound = h.pop(key_to_pop) + 1

        bounds = (new_lower_bound, bounds[1] + 1)
        max_length = max(max_length, bounds[1] - bounds[0])

    return max_length
*/

int longest_substring_with_k_distinct_characters( std::string s, int k ){
  if(k==0)return 0;

  int bounds[] = {0,0};
  std::map<char,int> h;
  int max_length = 0;
  int new_lower_bounds;
  for(int i = 0; i < s.size(); ++i){
    h[s[i]] = i;
    if(h.size() <= k){
      new_lower_bounds = bounds[0]; // Lower bound remains the same
    } else {
      // otherwise, pop last occurring char
      char key_to_pop = findMin(h);
      new_lower_bounds = h[key_to_pop]+1;
      h.erase(key_to_pop);
    }
    bounds[0] = new_lower_bounds;
    bounds[1] = bounds[1]+1;
    max_length = std::max(max_length, bounds[1]-bounds[0]);
  }
  return max_length;
}

int prob_13()
{
  std::cout << "\nProblem 13\n";

  std::cout << "Skipping for now";

  return 0;
}