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
#include<queue>
#include<stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {

public:
    int maxDepth_Old_Buggy(TreeNode* root) {
        TreeNode* current = root;
        bool cond = true;
        int maxDepth = 1;
        int currDepth = 1;
        stack<TreeNode*> s;
        while(current != NULL || s.empty() == false)
        {
            while(current != NULL)
            {
                s.push(current);
                current = current -> left;
                if(current != NULL)
                {
                    currDepth++;
                    cout<<"1: "<<current->val << " depth: "<<currDepth<<endl;
                }
                if(currDepth > maxDepth)    
                    maxDepth = currDepth;              
            }

            current = s.top();
            if(current != NULL)
            {
                currDepth--;
                cout<<"2: "<<current->val << " depth: "<<currDepth<<endl;

            }
            s.pop();
            


            current = current->right;
            if(current != NULL)  
            {          
                currDepth++;
                cout<<"3: "<<current->val << " depth: "<<currDepth<<endl;
                if(currDepth > maxDepth)    
                    maxDepth = currDepth;
            }  
        }

        return maxDepth;
    }
    int maxDepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;

        return max(maxDepth(root->left), maxDepth(root->right))+1;
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

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().maxDepth(root);

        string out = to_string(ret);
        cout <<out << endl;
    }
    return 0;
}