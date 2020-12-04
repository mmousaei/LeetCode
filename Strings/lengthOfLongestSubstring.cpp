// Solution to the problem lengthOfLongestSubstring from LeetCode.com
// Written by: Mohammadreza Mousaei
// Contact: mmousaei@andrew.cmu.edu
#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include<vector>
#include<string>
#include<sstream>
#include<string.h>
#include <algorithm>
#include <array>
#include <functional>
#include<map>
#include <cassert>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      if(s.length() == 1)
          return 1;
      std::vector<char> v;
      int longestLength = 0;
      int identical_ind;
      bool substr_flag = true;
      for(int i = 0; i < s.length(); i++)
      {
        substr_flag = true;
        for(int j = 0; j < v.size(); j++)
        {
            if(s[i] == v[j])
            {
              substr_flag = false;
              identical_ind = v.size() - j;
            }
        }
        int length_temp;
        if(substr_flag)
        {
            v.push_back(s[i]);
            length_temp = v.size();
            if(length_temp > longestLength)
            {
              longestLength = length_temp;
            }
        }
        else
        {
          v.erase(v.begin(), v.end());
          for(int k = i - identical_ind; k <= i; k++)
          {
             v.push_back(s[k]);
          }
        }

      }
      return longestLength;
    }
};
string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
