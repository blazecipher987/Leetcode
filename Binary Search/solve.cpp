#include <bits/stdc++.h>
using namespace std;
#include<vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int lowerBound =-1;
        int upperBount = nums.size();

        while(lowerBound+1 < upperBount){
            int mid = lowerBound+(upperBount-lowerBound)/2;

            if(target==nums[mid]){
                return mid;
            }

            else if(target> nums[mid]){
                lowerBound = mid;
            }

            else{
                upperBount = mid;
            }
        }
        
    }


};