#include <bits/stdc++.h>
using namespace std;

#define pb push_back


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> zeroPos = getZeroPos(nums);
        int size = nums.size();

        int zeroSize = zeroPos.size();
        if(zeroSize==0){
            
            int ans = multiplicationResult(nums);

            vector<int> result(size, ans);
            // fill(result.begin(), result.end(), ans);

            for(int i=0; i<size; i++){
                result[i] = result[i]/nums[i];
            }

            return result;

        }

        if(zeroSize==1){

            int zeroIndex = zeroPos[0];
            vector<int> ans(size, 0);

            // fill(ans.begin(), ans.end(),0);

            int product = mutliExceptSelf(nums, zeroIndex);
            ans[zeroIndex]=product;
            return ans;
        }

        if(zeroSize>=2){
            vector<int> ans(size, 0);
            // fill(ans.begin(), ans.end(), 0);

            return ans;
        }

        return {};
        
    }

    vector<int> getZeroPos(vector<int> &nums){

        vector<int> ans;
        int size = nums.size();
        for(int i=0; i<size;  i++){
            if(nums[i]==0){
                ans.pb(i);
            }
        }

        return ans;
    }

    int multiplicationResult(vector<int> &nums){

        int ans =1;

        for(auto i: nums){
            ans*=i;
        }

        return ans;
    }

    int mutliExceptSelf(vector<int> &nums , int except){

        int size = nums.size();
        int ans =1;
        for(int i=0; i<size; i++){

            if(i==except){
                continue;
            }

            ans*= nums[i];
        }

        return ans;
    }

};