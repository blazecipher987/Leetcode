#include <bits/stdc++.h>
using namespace std;

#define pb push_back


class Solution {
public:
        vector<vector<int>> result;

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> ans;
        // result.pb(ans);
        int itr=0;
        dfs(nums, ans, itr);
        return result;

    }

    void dfs(vector<int> &vc, vector<int> ans, int itr){

        result.pb(ans);

        int size = vc.size();
        for(int i=itr;i<size; i++){

            vector<int> temp = ans;
            temp.pb(vc[i]);

            dfs(vc, temp, i+1);
        }
    }
};