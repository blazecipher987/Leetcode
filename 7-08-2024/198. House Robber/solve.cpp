#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vc vector
#define ump unordered_map

class Solution
{
public:
    vc<int> dp;
    int rob(vector<int> &nums)
    {

        dp.resize(nums.size() + 1, -1);

        int size = nums.size();

        for (int i = 0; i < size; i++)
        {

            dp[i] = solve(nums, i);
        }

        int maxVal = INT_MIN;

        for (auto i : dp)
        {
            if (maxVal < i)
            {
                maxVal = i;
            }
        }

        return maxVal;
    }

    int solve(vc<int> &nums, int itr)
    {

        if (itr < 0)
        {
            return 0;
        }

        if (dp[itr] != -1)
        {
            return dp[itr];
        }

        if (dp[itr] == -1)
        {

            int curr = solve(nums, itr - 2);
            int curr2 = solve(nums, itr - 3);

            dp[itr] = nums[itr] + max(curr, curr2);
        }

        return dp[itr];
    }
};
