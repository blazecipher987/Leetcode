#include<bits/stdc++.h>
using namespace std;
#include<vector>

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {

        long long int result = nums[0];

        int itr=1;
        int size = nums.size();
        int limit=0;

        long long int prevSum=0;

        while(limit<size){
            prevSum = calculateAvg(nums,prevSum, limit);

            long long int avg = (prevSum+limit)/(limit+1);

            // cout<<"Curr SUm: "<<prevSum<<endl;

            if(avg>result){
                result=avg;
            }

            limit++;
        }

        return (int)result;
        
    }



    long long int calculateAvg(vector<int> &nums, long long int prevSum,int limit){


        long long int totalSum = prevSum + nums[limit];

        // return (totalSum+limit)/(limit+1);
        return totalSum;
    }
};

