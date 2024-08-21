#include <bits/stdc++.h>
using namespace std;

#define pb push_back


class Solution {
public:

    vector<vector<int>> result;

    int subarraySum(vector<int>& nums, int k) {

        int itr =0;
        vector<int> ans;
        solve(nums, ans, itr);

        prinVector(result);

        int count=0;
        // int q=1;
        // for(auto i: result){
        //     int ki =summation(i);

        //     cout<<"Trial"<<q<<" "<<ki<<endl;

        //     if(ki==k){
        //         // cout<<"found: "<<q<<endl;
        //         count++;
        //     }
        // }

        return count;
    }

    void solve(vector<int> &nums, vector<int> ans, int itr){

        int size = nums.size();

        result.pb(ans);

        for(int i=itr; i<(itr+2); i++){
            vector<int> temp = ans;
            temp.pb(nums[i]);
            solve(nums, temp, i+1);
            temp.clear();
        }
    }

    void prinVector(vector<vector<int>> nums){
        
        for(auto i: nums){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

    int summation(vector<int> t){
        int count=0;

        for(auto i: t){
            count+=i;

        }

        return count;
    }
};

int main(){

    vector<int> trial = {1,2,3};

    Solution s;

    int x = s.subarraySum(trial, 1);
    cout<<endl;
    cout<<x<<endl;
}