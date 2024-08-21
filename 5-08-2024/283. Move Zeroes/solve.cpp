#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int lower =0;
        int size = nums.size();

        while(lower<size && nums[lower]!=0){
            lower++;
        }

        //^ zero doesnt exist or in the last position, so nothing to do
        if(lower==size){
            return ;
        }

        int higher = lower;

        bool flag = true;
        while(flag){


            higher = returnNonZer(nums, higher);
            lower = returnZeroPos(nums, lower);

            cout<<"Curr Low: "<<lower<<",Higher: "<<higher<<endl;

            if(higher==size){
                break;
            }

            int temp = nums[higher];
            nums[higher] = nums[lower];
            nums[lower]= temp;
        }

        return;
        
    }

    int returnZeroPos(vector<int> &nums, int lower){

        while(nums[lower]!=0){
            lower++;
        }

        return lower;
    }

    int returnNonZer(vector<int> &nums, int higher){

        int size = nums.size();
        while(higher<size && nums[higher]==0){
            higher++;
        }

        return higher;
    }


};