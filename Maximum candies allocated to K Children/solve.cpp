#include<bits/stdc++.h>
using namespace std;
#include<vector>

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        sort(candies.begin(), candies.end());

        int candieSize = candies.size();

        int elemSum = sumOfElems(candies);

        //^---- If total candies are less than number of childrens
        if(sumOfElems(candies)<k){
            return 0;
        }

        //^---- If children number is less than the total piles of candies
        // if(k<= candies.size()){
        //     return candies[0];
        // }

        else{
            return minimization(candies, k);
            
        }

        return 0;
        
    }

    long long int sumOfElems(vector<int> candies){
        long long int count=0;

        for(auto i: candies){
            count+= i;
        }

        return count;
    }

    

    int minimization(vector<int> &nums, long long int target){
        int ans = nums.size();
        int lowerBound=1;
        int upperBound = nums[ans-1];

        while(lowerBound<=upperBound){
            int mid = (lowerBound+(upperBound-lowerBound)/2);

            long long int temp = divResult(nums, mid);
            if(temp<target){
                // ans = mid;
                upperBound=mid-1;

            }
            else{
                ans=mid;
                lowerBound = mid+1;
            }
        }
        return ans;

    }

    long long int divResult(vector<int> candies, int divisor){
        long long int count=0;

        for(auto i: candies){
            count+= (i/divisor);
        }

        return count;
    }
};