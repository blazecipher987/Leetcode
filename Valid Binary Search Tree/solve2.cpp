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

     return leverOrderTraversal(root);
        
    }

    bool leverOrderTraversal(TreeNode *root){

        queue<TreeNode*> q1;
        vector<int> ans;
        bool flag = true;

        while(!q1.empty()){

            queue<TreeNode*> q2;

            while(!q1.empty()){

                TreeNode *tempNode = q1.front();
                ans.push_back(tempNode->val);
                q1.pop();

                if(tempNode->left!=NULL){
                    q2.push(tempNode->left);
                }
                if(tempNode->right!=NULL){
                    q2.push(tempNode->right);
                }

                flag = incVector(ans);
                if(flag==false){
                    return flag;
                }
            }
            q1=q2;
            ans.clear();

        }

        return flag;

    }

    bool incVector(vector<int> v){
        bool flag = true;
        int temp = v[0];
        for(int i=1; i<v.size(); i++){
            if(v[i-1]>v[i]){
                return false;
            }
        }

        return true;
    }

};