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

    vector<int> seq1;
    vector<int> seq2;

    
    bool isSameTree(TreeNode* p, TreeNode* q) {

        traversePreOrder(p,seq1);
        traversePreOrder(q,seq2);

        print(seq1);
        print(seq2);

        if(seq1==seq2){
            
            vector<int> s1;
            vector<int> s2;

            traversePostOrder(p,s1);
            traversePostOrder(q,s2);

            if(s1==s2){
                return true;
            }

            return false;
        }
        return false;
        
    }

    void print(vector<int> nums){

        for(auto i: nums){
            cout<<i<<",";
        }
        cout<<endl;
        cout<<endl;
    }

    void traversePreOrder(TreeNode *root, vector<int> &nums){

        if(root==NULL){
            nums.push_back(-50000);
            return;
        }

        traversePreOrder(root->left, nums);
        nums.push_back(root->val);
        traversePreOrder(root->right, nums);
    }

     void traversePostOrder(TreeNode *root, vector<int> &nums){

        if(root==NULL){
            nums.push_back(-50000);
            return;
        }

        traversePostOrder(root->left, nums);
        traversePostOrder(root->right, nums);
        nums.push_back(root->val);

    }


};
