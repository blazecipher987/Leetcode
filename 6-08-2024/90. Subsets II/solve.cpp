#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
        set<vector<int>> result;
        vector<vector<int>> n;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> ans;
        int itr=0;
        dfs(nums, ans, itr);

        for(vector<int> i: result){
            n.pb(i);
        }

        return n;


    }

    void dfs(vector<int> &nums, vector<int> ans, int itr){

        
        result.insert(ans);

        int size = nums.size();
        vector<int> temp;
        for(int i=itr; i<size; i++){

            temp = ans;
            temp.pb(nums[i]);
            dfs(nums, temp, i+1);
            temp.clear();
        }
    }
};