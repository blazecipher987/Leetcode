#include <bits/stdc++.h>
using namespace std;

#define pb push_back


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        int size = nums.size();
        vector<int> ans;
        for(int i=0; i<size;  i++){

            int elem = abs(nums[i])-1;

            if(nums[elem]>0){
                nums[elem] *= -1;
            }

            else{
                ans.pb(elem+1);

            }
        }

        return ans;
        
    }
};