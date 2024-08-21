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
    TreeNode* invertTree(TreeNode* root) {
    
    inversion(root);
    return root;
        
    }

    void inversion(TreeNode* &root){

        if(root==NULL){
            return ;
        }
        // if(root->left==NULL && root->right==NULL){
        //     return root->val;
        // }

        
        // if(root->left!=NULL && root->right!=NULL)
        {
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
            // delete temp;
        }
        
        inversion(root->left);
        inversion(root->right);

    }
};
