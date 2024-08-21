
#include<bits/stdc++.h>
using namespace std;

//! SOLVED
//^---- 1. Inorder of a valid BST gives an increasing sequence

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
    bool isValidBST(TreeNode* root) {

        vector<int> ans;
        inorderTraversal(root, ans);
        return validateInc(ans);
    }

    void inorderTraversal(TreeNode *root, vector<int> &ans){

        if(root==NULL){
            return;
        }

        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }

    bool validateInc(vector<int> v){

        bool flag = true;

        for(int i=1; i<v.size(); i++){
            if(v[i-1]>=v[i]){
                return false;
            }
        }
        return true;
    }

    
};