#include <bits/stdc++.h>
using namespace std;

#define pb push_back


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        return solve(nums, k);
        
    }

    double solve(vector<int> &nums, int k){

        double maxAns = INT_MIN;
        double currAvg =0;
        double currSum=0;

        int size = nums.size();
        bool flag = false;

        for(int i=0; i<k; i++){
            currAvg+=nums[i];

        }

        currSum = currAvg;
        currAvg = currAvg/k;

        if(currAvg>maxAns){
            maxAns = currAvg;
           }
        int lower = 0;

        for(int i=k; i<size; i++){

           currSum = currSum + nums[i] - nums[lower];
           currAvg = currSum/k;

           if(currAvg>maxAns){
            // cout<<"lwoer,i: "<<lower<< ","<<i<<endl;
            maxAns = currAvg;
           }

           lower++;

        }

        return maxAns;
    }
};