
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

using namespace std;

class My_First_Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      std::vector<int> out;
      for(int i = 0; i < nums.size(); i++)
      {
        for(int j = i+1; j < nums.size(); j++)
        {
          if(nums[i]+nums[j] == target)
          {
            // cerr<< "num[" << i << "] = " << nums[i]<< " and num[" << j << "] = " << nums[j] << endl;
            out.push_back(i);
            out.push_back(j);
            return out;
          }
        }
      }
    }
};


class Hash_Solution
{
  public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
      vector<int> out;
      map<int, int> hash_table;
      map<int,int>::iterator it;
      for(int i = 0; i < nums.size(); i++)
      {
        hash_table.insert(pair<int, int> (nums[i], i+1));
      }
      it = hash_table.find(3);
      cerr<<"First = "<<it->first<<" Second = "<<it->second<<endl;
      for(int i = 0; i < nums.size(); i++)
      {
        int complement = target - nums[i];
        it = hash_table.find(complement);
        if(it->second != 0 && (it->second-1) != i)
        {
          out.push_back(i);
          out.push_back(it->second - 1);
          return out;
        }
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

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        // vector<int> ret = My_First_Solution().twoSum(nums, target);
        vector<int> ret = Hash_Solution().twoSum(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
