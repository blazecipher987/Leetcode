#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int size = nums.size();

        if(size==1){
            return {nums[0]*nums[0]};
        }

        return solve(nums);
        
    }

    vector<int> solve(vector<int> nums){

        vector<int> ans;
        int size= nums.size();

        int i=0;
        while(i <size && nums[i]<0){
            i++;
        }

        if(i==size){  //^all elements are neg;

        vector<int> result;
        for(int i= size-1; i>=0; i--){
            int x = nums[i]*(-1);
            ans.pb(x*x);
        }
        return ans;

        }

        // int midpoint = i;
        int left = i-1;
        int right =i;

        // ans.pb(nums[midpoint]*nums[midpoint]);

        while(left>=0 && right<size){
 
            int x = nums[left]*(-1);
            int y = nums[right];

            if(x<y){
                ans.pb(x*x);
                left--;
            }
            else{
                ans.pb(y*y);
                right++;
            }
        }

        cout<<"left: "<<left<<", right: "<<right<<endl;

        if(left<0){

            for(int i=right; i<size; i++){
                
                ans.pb(nums[i]*nums[i]);
            }
        }

        if(right>=size){
            for(int i=left; i>=0; i--){
                ans.pb(nums[i]*nums[i]);
            }
        }

        return ans;
    }
};