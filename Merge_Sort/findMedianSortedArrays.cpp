// Solution to the problem 4. Median of Two Sorted Arrays from LeetCode.com
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, rem;
      std::vector<int> merged;
      // for(int i = 0; i < nums1.size(); i++)
      // {
      //   std::cout << nums1[i] << '\n';
      // }
      // for(int i = 0; i < nums2.size(); i++)
      // {
      //   std::cout << nums2[i] << '\n';
      // }
      // std::cout << "size1: " <<  nums1.size() << '\n';
      // std::cout << "size2: " <<  nums2.size() << '\n';
      while (i < nums1.size() && j < nums2.size())
      {
        if(nums1[i] < nums2[j])
        {
          merged.push_back(nums1[i]);
          i++;
        }
        else
        {
          merged.push_back(nums2[j]);
          j++;
        }
      }
      if( i == nums1.size())
      {
        for(; j < nums2.size(); j++)
        {
          merged.push_back(nums2[j]);
        }
      }
      else
      {
        for(; i < nums1.size(); i++)
        {
          merged.push_back(nums1[i]);
        }
      }
      // for(int i = 0; i < merged.size(); i++)
      // {
      //   std::cout << merged[i] << '\n';
      // }
      int n = merged.size()/2;

      nth_element(merged.begin(), merged.begin()+n, merged.end());
      if(merged.size()%2 == 1)
      {
        return merged[n];
      }
      else
      {
        std::nth_element(merged.begin(), merged.begin()+n, merged.end());
        return 0.5*(merged[n]+merged[n-1]);
      }
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums1 = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> nums2 = stringToIntegerVector(line);

        double ret = Solution().findMedianSortedArrays(nums1, nums2);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
