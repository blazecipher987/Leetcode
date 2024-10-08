#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int tortoise = nums[0];
        int hare = nums[0];

        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(hare!=tortoise);

        tortoise =nums[0];

        while(hare!=tortoise){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return tortoise;
        
    }
};