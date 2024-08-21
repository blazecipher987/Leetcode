#include<bits/stdc++.h>
using namespace std;

//! SOLVED


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {

        bool flag = true;
        getHeightDiff(root, flag);

        return flag;

        
        
    }

    

    int getHeightDiff(TreeNode *root, bool &flag){
        
        if(root==NULL){
            return 0;
        }

        int left = getHeightDiff(root->left, flag);
        int right = getHeightDiff(root->right, flag);

        int d = (left>right)?(left-right):(right-left);

        //^ abs has big overhead, causes much more execution time
        // int d = abs(left-right);

        flag = flag && d<=1;

        return max(left, right)+1;

    }
};