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
    int diameterOfBinaryTree(TreeNode* root) {
        
        int diameter = 0;
        return getHeight(root, diameter);
    }

    int getHeight(TreeNode* node, int &diameter){

        if(node==NULL){
            return 0;
        }

        int left = getHeight(node->left, diameter);
        int right = getHeight(node->right, diameter);

        diameter = max(diameter, left+right);

        return max(left, right)+1;

    }
};

int main(){

}