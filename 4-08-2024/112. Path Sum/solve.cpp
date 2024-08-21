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
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(!root){
            return false;
        }

        int sum=0;
        bool flag = false;

        getSum(root, sum, flag, targetSum);

        return flag;
        
    }

    void getSum(TreeNode *root, int sum, bool &flag, int target){

        if(root==NULL){
            return;
        }

        sum+= root->val;

        if(!root->left && !root->right){
            if(target==sum){
                flag = true;
            }
        }

        getSum(root->left, sum, flag , target);
        getSum(root->right, sum, flag , target);

    }
};