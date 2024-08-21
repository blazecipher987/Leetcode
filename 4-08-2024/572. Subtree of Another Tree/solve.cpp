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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        vector<int> preOrder1, preOrder2;
        vector<int> postOrder1, postOrder2;

        getOrder(root,preOrder1, postOrder1);
        getOrder(root, preOrder2, postOrder2);

        bool flag1=false;
        bool flag2=false;


        int size1 = preOrder1.size();
        int size3 = preOrder2.size();

        for(int i=0; i<size1-size3; i++){

            if(preOrder1[i]==preOrder2[0]){

                int j=0;
                while(j<preOrder2.size() && preOrder1[i+j]==preOrder2[j]){
                    j++;
                }

                if(j== preOrder2.size()){
                    flag1 = true;

                }
            }
        }

        int size2 = postOrder1.size();
        int size4 = postOrder2.size();

        for(int i=0; i<size2-size4; i++){

            if(postOrder1[i]==postOrder2[0]){

                int j=0;
                while(j<postOrder2.size() && postOrder1[i+j]==postOrder2[j]){
                    j++;
                }

                if(j== postOrder2.size()){
                    flag2 = true;

                }
            }
        }

        if(flag1 && flag2){
            return true;
        }
        
        return false;


        
    }

    void getOrder(TreeNode *root, vector<int> &ans, vector<int> &ans2){

        if(!root){
            return ;
        }

        ans.push_back(root->val);
        getOrder(root->left, ans, ans2);
        getOrder(root->right, ans, ans2);
        ans2.push_back(root->val);

    }

    void getPostOrder(TreeNode *root, vector<int> &ans){
        if(!root){
            return ;
        }

        getPostOrder(root->left,ans);
        getPostOrder(root->right,ans);
        ans.push_back(root->val);

        
    }
};