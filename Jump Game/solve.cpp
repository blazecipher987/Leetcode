#include<bits/stdc++.h>
using namespace std;
#include<vector>

//!SOLVED

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        return jumpGame(nums);
    }

    bool jumpGame(vector<int> &nums){

        reverse(nums.begin(), nums.end());

        int count =0;
        int flag = false;
        int i=0;

        int size = nums.size();

        while(!flag && i<size){
            if(nums[i]>=count){
                count=0;
            }
            if(i== size-1 && count==0){
                flag = true;
            }

            i++;
            count++;
        }

        return flag;
    }
};