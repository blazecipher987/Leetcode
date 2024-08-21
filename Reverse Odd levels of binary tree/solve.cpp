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
    TreeNode* reverseOddLevels(TreeNode* root) {
    
    int count=1;
    inversion(root, count);
    return root;
        
    }

    void inversion(TreeNode* &root, int &count){

        if(root==NULL){
            return ;
        }


        // if(root->left==NULL && root->right==NULL){
        //     return root->val;
        // }

        
        
        
        inversion(root->left,count);
        inversion(root->right,count);

        if(count%2==1)
        {
            TreeNode *temp = root->left;
            root->left = root->right;
            root->right = temp;
            // delete temp;
        }
        count++;

    }
};
