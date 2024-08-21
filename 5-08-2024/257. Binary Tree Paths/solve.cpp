#include <bits/stdc++.h>
using namespace std;

#define pb push_back



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string s="";
        getPaths(root,s);

        return ans;
    }

    void getPaths(TreeNode *root, string s){

        if(!root){

            return;
        }

        if(!root->left && !root->right){
            s.append(to_string(root->val));
            ans.push_back(s);

        }

        else{
            s.append(to_string(root->val));
            s.append("->");
        }
        
        

        getPaths(root->left,s);
        getPaths(root->right,s);
        
    }
};