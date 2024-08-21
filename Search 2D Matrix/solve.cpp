#include<bits/stdc++.h>
using namespace std;


//! SOLVED

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        return modifiedBinarySearch(matrix, target);
    }

    bool modifiedBinarySearch(vector<vector<int>> matrix, int target){

        int rowLeft = 0;
        int rowRight = matrix[0].size()-1;

        int colLeft = 0;
        int colRight = matrix.size()-1;

        int rowVal = minimization(matrix, target);
        if(rowVal>= matrix.size()){
            return false;
        }
        int colVal = minimization2(matrix, target, rowVal);

        cout<<rowVal<<","<<colVal<<endl;

        if(matrix[rowVal][colVal]==target){
            return true;
        }
        return false;
    }

    int minimization(vector<vector<int>> nums, int target){
        int ans = nums.size();
        int t = nums[0].size()-1;
        int lowerBound=0;
        int upperBound = ans-1;

        while(lowerBound<=upperBound){
            int mid = (lowerBound+upperBound)/2;

            if(nums[mid][t]>=target){
                ans = mid;
                upperBound=mid-1;

            }
            else{
                lowerBound = mid+1;
            }
        }
        return ans;

    }

    int minimization2(vector<vector<int>> nums, int target, int rowVal){

        if(rowVal>=nums.size()){
            return -1;
        }
        int ans = nums[0].size();
        int lowerBound=0;
        int upperBound = ans-1;

        while(lowerBound<=upperBound){
            int mid = (lowerBound+upperBound)/2;

            if(nums[rowVal][mid]>=target){
                ans = mid;
                upperBound=mid-1;

            }
            else{
                lowerBound = mid+1;
            }
        }
        return ans;

    }


};