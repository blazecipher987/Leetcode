#include<bits/stdc++.h>
using namespace std;


//! SOLVED

class Solution {
public:
    int maxSum=INT_MIN;
    int maxSubArray(vector<int>& nums) {
        return algo(nums);
    }

    int algo(vector<int>& nums) {
        int turn = 0;
        int left, right;
        int currSum=0;

        int size = nums.size();

        for (int i = 0; i < size; i++) {

            currSum += nums[i];

            if (maxSum < currSum) {
                maxSum = currSum;
                right=i;
            }

            
            if(currSum>=0 && turn==0){
                left=i;
                turn++;
            }

            if(currSum<0){
                currSum=0;
                turn=0;
                // left=i;
            }
        }

        cout<<"Positions left:"<<left<<", right:"<<right<<endl;
        return maxSum;
    }
};