#include <bits/stdc++.h>
using namespace std;

#define pb push_back



class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);

        int itr=0;
        vector<int> ans;
        solve(nums, ans, k, itr);
        return result;

    }

    void solve(vector<int> &nums, vector<int> ans , int k, int itr){


        // ans.pb(nums[itr]);
        if(ans.size()==k){
            result.pb(ans);
            return;
        }



        int size = nums.size();
        vector<int> temp;
        for(int i=itr; i<size; i++){
            temp = ans;
            temp.pb(nums[i]);
            solve(nums, temp, k, i+1);
            temp.clear();
        }
    }
};