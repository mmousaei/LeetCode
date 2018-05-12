
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

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int val_tmp = 0;
      int dec_overflw = 0;
      ListNode* dummyRoot = new ListNode(0);
      ListNode* out_list = dummyRoot;
      while (l1 != NULL || l2 != NULL)
      {
        if(l1 == NULL)
        {
          val_tmp = l2->val;
        }
        else if(l2 == NULL)
        {
          val_tmp = l1->val;
        }
        else
        {
          val_tmp = l1->val + l2->val;
        }
        if((val_tmp + dec_overflw) < 10)
        {
          out_list->next = new ListNode(val_tmp+dec_overflw);
          dec_overflw = 0;
        }
        else
        {
          out_list->next = new ListNode(val_tmp+dec_overflw-10);
          dec_overflw = 1;
        }
        out_list = out_list->next;
        if(l1 != NULL)  l1 = l1->next;
        if(l2 != NULL)  l2 = l2->next;
      }
      if(dec_overflw == 1)
      {
          out_list->next = new ListNode(1);
          out_list = out_list->next;
      }
      out_list = dummyRoot->next;
      delete dummyRoot;
      return out_list;
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

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);

        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
