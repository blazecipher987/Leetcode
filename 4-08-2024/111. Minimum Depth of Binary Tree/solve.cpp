#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int minDepth(TreeNode* root) {

        if(!root){
            return 0;
        }


        vector<int> ans;
        int depth =0;
        depthDetermine(root, ans, depth);
        sort(ans.begin(), ans.end());
        return ans[0];
    }


    void depthDetermine(TreeNode *root, vector<int> &ans, int depth){

        if(root==NULL){
            return;
        }

        depth++;


        if(!root->left && !root->right){
            ans.push_back(depth);

        }


        depthDetermine(root->left, ans, depth);
        depthDetermine(root->right, ans, depth);
    }
};