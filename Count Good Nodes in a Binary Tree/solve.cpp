#include <bits/stdc++.h>
using namespace std;

//! SOLVED


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
    int goodNodes(TreeNode* root) {
        int count =0;
        int currMax = -10;
        traverseTree(root, count, currMax);
        return count;
    }

    void traverseTree(TreeNode* root, int &count , int currMax){

        if(root==NULL){
            return;
        }

        int val = root->val;
        if(val>=currMax){
            count++;
            currMax=val;
        }
        traverseTree(root->left, count, currMax);
        traverseTree(root->right, count, currMax);

    }
};