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
    
    //    printVec(formArr(root));

        vector<int> ans = formArr(root);
        return constructTree(ans);

    //    return root;
        
    }

    TreeNode* constructTree(vector<int> seq){

        queue<TreeNode*> q1;

        int i=0;

        TreeNode *root = new TreeNode(seq[i]);

        q1.push(root);
        int size = seq.size();
        while(q1.empty() == false){

            TreeNode *temp = q1.front();
            q1.pop();

            i++;

            if(i<size){
                temp->left = new TreeNode(seq[i]);
                q1.push(temp->left);
            }
            i++;
            if(i<size){
                temp->right = new TreeNode(seq[i]);
                q1.push(temp->right);
            }
        }

        return root;
    }

    vector<int> formArr(TreeNode* root){

        queue<TreeNode*> q1;
        stack<TreeNode*> s1;
        vector<int> seq;

        int count=1;

        q1.push(root);
        seq.push_back(root->val);

        while(!q1.empty()){

            // queue<TreeNode*> q2;
            vector<TreeNode*> q2;


            while(!q1.empty()){

                TreeNode* temp = q1.front();
                q1.pop();

                if(temp->left!=NULL){
                    q2.push_back(temp->left);
                }
                if(temp->right!=NULL){
                    q2.push_back(temp->right);
                }

            }

            for(TreeNode* i: q2){
                q1.push(i);
            }
            
            if(count%2==1)
                reverse(q2.begin(), q2.end());

            for(auto i: q2){
                seq.push_back(i->val);
            }

            count++;
        }

        return seq;

    }


    // TreeNode * formTree(vector<int> nums){

    //     TreeNode *head;
    // }

    void printVec(vector<int> ans){
        for(auto i: ans){
            cout<<i<<",";
        }
    }

};

int main(){
    
    // Constructing the tree manually
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    root->left->left->left = new TreeNode(11);
    root->left->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(13);
    root->left->right->right = new TreeNode(14);
    root->right->left->left = new TreeNode(25);
    root->right->left->right = new TreeNode(26);
    root->right->right->left = new TreeNode(27);
    root->right->right->right = new TreeNode(28);

    
        Solution s;
        s.reverseOddLevels(root);
    
        return 0;
}