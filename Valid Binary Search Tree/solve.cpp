#include<bits/stdc++.h>
using namespace std;



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

        bool flag = true;
        validate(root, flag);
        return flag;
        
    }

    void validate(TreeNode *root, bool &ans){

        if(root==NULL){
            return;
        }

        if(root->left== NULL && root->right==NULL){
            return;
        }

        if(root->left!=NULL && root->right!=NULL && root->val>root->left->val && root->val<root->right->val){
            validate(root->left,ans);
            validate(root->right,ans);
        }

        if(root->right==NULL && root->left!=NULL && root->val > root->left->val){
            validate(root->left, ans);
        }
        if(root->left==NULL && root->right!=NULL && root->val< root->right->val){
            validate(root->right, ans);
        }

        else{
            ans=false;
            return;
        }
    }
};
