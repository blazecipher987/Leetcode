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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    }

    TreeNode *buildTree(vector<int> arr, vector<int> preorder,  int preIter){

        if(arr.size()==1){
            TreeNode *temp = new TreeNode(arr[0]);
            return temp;
        }

        

        auto itl= find(arr.begin(), arr.end(), preorder[preIter]);

        vector<int> left(arr.begin(), arr.begin()+itl);
        vector<int> right(arr.begin()+itl, arr.end());

        int val = preorder[preIter];
        preIter++;

        TreeNode *leftNode = buildTree(left, preorder, preIter);
        TreeNode *rightNode = buildTree(right, preorder, preIter);

        TreeNode *node = new TreeNode(val, leftNode, rightNode);

        return node;




        
    }
};