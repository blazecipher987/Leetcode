#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vc vector
#define ump unordered_map


class Solution {
public:
    void sortColors(vector<int>& nums) {
        
    }

    int findNonEmpty(vc<int>&nums, int curr, int bound){
        int itr =0;

        while(nums[itr]==curr && itr<bound){
            itr++;
        }

        if(itr==bound){
            return -1;
        }
        return itr;
    }
};