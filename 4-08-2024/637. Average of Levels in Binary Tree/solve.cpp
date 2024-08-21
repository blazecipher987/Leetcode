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
    vector<double> averageOfLevels(TreeNode *root)
    {

        return calcuAvg(root);
    }

    vector<double> calcuAvg(TreeNode *root)
    {

        queue<TreeNode *> q1;

        q1.push(root);
        vector<double> ans;
        double val = (double) root->val;
        ans.push_back(val);

        while (!q1.empty())
        {
            vector<double> values;
            queue<TreeNode *> q2;
            double avg;

            while (!q1.empty())
            {
                TreeNode *temp = q1.front();
                q1.pop();

                if (temp->left)
                {
                    values.push_back(temp->left->val);
                    q2.push(temp->left);
                }
                if (temp->right)
                {
                    values.push_back(temp->right->val);
                    q2.push(temp->right);
                }

                avg = result(values);
            }
                ans.push_back(avg);
            q1=q2;
        }

        ans.erase(ans.end());

        return ans;
    }

    double result(vector<double> tracks)
    {

        double result = 0;

        for (auto i : tracks)
        {
            result += i;
        }

        int size = tracks.size();

        return (result / (size * 1.0));
    }
};