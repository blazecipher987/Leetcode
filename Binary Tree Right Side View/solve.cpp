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
    vector<int> rightSideView(TreeNode* root) {
        
        return getRightElems(root);
    }

    vector<int> getRightElems(TreeNode *root){

        queue<TreeNode*> q1;
        vector<int> ans;
        
        q1.push(root);

        while(!q1.empty()){
            
            queue<TreeNode*> q2;

            while(!q1.empty()){
                
                if(q1.size()==1){
                    ans.push_back(q1.front()->val);
                }

                TreeNode *tempNode = q1.front();
                q1.pop();
                
                if(tempNode->left!=NULL)
                    q2.push(tempNode->left);
                if(tempNode->right!=NULL)
                    q2.push(tempNode->right);
            }

            q1=q2;
        }

        return ans;
    }
};