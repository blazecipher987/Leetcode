#include <bits/stdc++.h>
using namespace std;

#define pb push_back


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        

        return getCount(nums);
    }


    int getCandidate(vector<int> &nums){

        int size = nums.size();

        int count=1;
        int candidate=nums[0];
        for(int i=1; i<size; i++){

            if(nums[i]==candidate){
                count++;
            }
            else{
                
                if(count==0){
                    candidate=nums[i];
                }
                else{
                    count--;
                }
            }
        }

        return candidate;
    }

    int getCount(vector<int> &nums){

        int candidate = getCandidate(nums);

        int size = nums.size();
        int count =0;
        for(int i=0; i<size; i++){
            if(nums[i]==candidate){

                count++;
            }   
        }

        int halfList = (size)/2;

        if(count>halfList){
            return candidate;
        }
        return -1;
    }
};