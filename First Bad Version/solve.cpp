#include <bits/stdc++.h>
using namespace std;
#include<vector>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

//! SOLVED


class Solution {
public:
    int firstBadVersion(int n) {
        return (minimization(n));
    }

    int minimization(int target){
        int ans = target;
        int lowerBound=0;
        int upperBound = target;

        while(lowerBound<=upperBound){
            // int mid = (lowerBound+upperBound)/2;
            int mid = lowerBound + (upperBound-lowerBound)/2;   //! Faced an overflow issue here

            if(isBadVersion(mid)){
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