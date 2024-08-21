#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int flag = true;
        int ans;
        int temp=nums[0];
        int size = nums.size();

        for(int i=1;i <size; i++){

            if(nums[i]==temp){
                break;
            }

            temp = nums[i];
        }

        return temp;
        
    }
};