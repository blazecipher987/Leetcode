#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vc vector
#define ump unordered_map

class Solution {
public:
    vc<int> dp;
    int rob(vector<int>& nums) {
        
        int size = nums.size();
        dp.resize(size+1,-1);


        for (int i = 0; i < size; i++)
        {

            dp[i] = solve(nums, i, size, i);
        }

        int maxVal = INT_MIN;

        for (auto i : dp)
        {
            maxVal = maxVal<i?i:maxVal;
        }

        return maxVal;
    }

    int solve(vc<int> &nums, int itr, int size, int initItr){

        if(itr<=initItr+1){
            return 0;
        }

        if(dp[itr]!=-1){
            return dp[itr];
        }

        if(dp[itr]==-1){
            int curr1 = solve(nums, (itr+size-2)%size, size, initItr);
            int curr2 = solve(nums, (itr-3+size)%size, size, initItr);

            dp[itr] = nums[itr] + max(curr1, curr2);

        }

        return dp[itr];
    }
};