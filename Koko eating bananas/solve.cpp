#include<bits/stdc++.h>
using namespace std;
#include<vector>


//! SOLVED


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        sort(piles.begin(), piles.end());
        
        return minimization(piles, h);
    }

    int minimization(vector<int> &nums, int hourHad){
        int ans = nums.size();
        int lowerBound=1;
        int upperBound = nums[ans-1];

        while(lowerBound<=upperBound){
            int mid = (lowerBound+(upperBound-lowerBound)/2);
            // mid = nums[mid];

            long long int temp = getDiv(nums, mid);
            if(temp<=hourHad){
                ans = mid;
                upperBound= mid-1;
                // lowerBound=mid+1;

            }
            else{
                lowerBound = mid+1;
                // upperBound= mid-1;

            }
        }
        return ans;

    }

    long long int getDiv(vector<int> nums, int divisor){

        long long int count=0;
        for(int i: nums){
            int temp = (i+divisor-1)/divisor;
            count+= temp;
        }

        return count;
    }


};