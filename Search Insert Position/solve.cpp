#include <bits/stdc++.h>
using namespace std;
#include<vector>

//! SOLVED
//^ Minimization Binary Search
//^ IF ELEMENT IS PRESENT, that position is directly given
//^ ELse the position where the element should be inserted is given
//^ Both are done at the same time

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        return findElem(nums, target);
        
    }

    int findElem(vector<int> &nums, int targert){

        int ans = nums.size();
        int lowerBound = 0;
         int upperBound = ans -1;

         while(lowerBound<= upperBound){

            int mid = lowerBound + (upperBound-lowerBound)/2;

            if(nums[mid]>= targert){
                ans = mid;
                upperBound = mid-1;
            }
            else{
                lowerBound = mid+1;
            }
         }

         return ans;
    }
};