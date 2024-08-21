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

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {

        queue<TreeNode *> q1;
        vector<vector<int>> ans;
        vector<int> tempResult;

        if(root==NULL){
            return {};
        }

        q1.push(root);

        while (!q1.empty())
        {

            queue<TreeNode*> q2;

            while (!q1.empty())
            {

                TreeNode *temp = q1.front();
                q1.pop();

                tempResult.push_back(temp->val);

                if (temp->left != NULL)
                {
                    q2.push(temp->left);
                }

                if (temp->right != NULL)
                {
                    q2.push(temp->right);
                }
            }

            q1=q2;
            ans.push_back(tempResult);
            tempResult.clear();
        }

        return ans;
    }
};