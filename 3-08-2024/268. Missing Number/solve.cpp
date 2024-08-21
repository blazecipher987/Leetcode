#include<bits/stdc++.h>
using namespace std;

#define ll long long int


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int size = nums.size();
        ll total = (size*(size+1))/2;

        ll sum = summation(nums);

        return total-sum;
    }

    ll summation(vector<int> nums){

        ll sum =0;

        for(auto i: nums){
            sum+=i;
        }

        return sum;
    }
};