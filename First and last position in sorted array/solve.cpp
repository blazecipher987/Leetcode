#include <bits/stdc++.h>
using namespace std;
#include<vector>



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int low = minimization(nums, target);
        if(low == nums.size() || nums[low]!=target){
            return {-1, -1};
        }
        int high = maximization(nums, target);
        return {low, high-1};

        
    }

    int minimization(vector<int> &nums, int target){
        int ans = nums.size();
        int lowerBound=0;
        int upperBound = ans-1;

        while(lowerBound<=upperBound){
            int mid = (lowerBound+upperBound)/2;

            if(nums[mid]>=target){
                ans = mid;
                upperBound=mid-1;

            }
            else{
                lowerBound = mid+1;
            }
        }
        return ans;

    }

    int maximization(vector<int> &nums, int target){
        int ans = nums.size();
        int lowerBound=0;
        int upperBound = ans-1;

        while(lowerBound<=upperBound){
            int mid = (lowerBound+upperBound)/2;

            if(nums[mid]>target){
                ans = mid;
                upperBound=mid-1;

            }
            else{
                lowerBound = mid+1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = s.searchRange(nums, target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}