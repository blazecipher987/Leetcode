#include<bits/stdc++.h>
using namespace std;

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
    int minDepth(TreeNode* root) {

        int depth = INT_MAX;
        getMinDepth(root, depth);

        return depth+1;
        
    }

    int getMinDepth(TreeNode *root, int &depth){

        if(root==NULL){
            return 0;
        }

        int left = getMinDepth(root->left, depth);
        int right = getMinDepth(root->right, depth);

        if(!left && !right){
            return min(left, right)+1;
        }

        return max(left, right)+1;
    }
};