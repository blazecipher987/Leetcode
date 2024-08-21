#include<bits/stdc++.h>
using namespace std;


//! SOLVED
//^---- 1. Keep track of the left and right depth for each node, and take the max of them
//^---- 2. Mostly like determining height, just add 1 at the printing of ans.
//^---- 3. IF this is a empthu thenut the ans as 0


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
    int maxDepth(TreeNode* root) {
        int depth =0;

        getDepth(root, depth);

        if(root==NULL){
            return 0;
        }

        return depth+1;
    }

    int getDepth(TreeNode* root, int &diameter){

        if(root==NULL){
            return 0;
        }

        int left = getDepth(root->left, diameter);
        int right = getDepth(root->right, diameter);

        diameter = max(diameter, max(left, right));

        return max(right, left)+1;
    }
};