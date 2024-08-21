#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        TreeNode *ans = nullptr;

        int valP = p->val;
        int valQ = q->val;

        if (valP > valQ) {
            std::swap(valP, valQ);
        }

        recurr(root, valP, valQ, ans);

        return ans;
    }

    void recurr(TreeNode* root, int p, int q, TreeNode *& ans){

        if(root==NULL){
            return;
        }

        if(root->val >= p && root->val <=q){
            ans= root;
            return;
        }

        if(p< root->val && q< root->val)
            recurr(root->left, p, q, ans);
        else
            recurr(root->right, p, q, ans);

    }
};