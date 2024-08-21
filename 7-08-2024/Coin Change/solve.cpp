#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vc vector
#define ump unordered_map



class Solution {
public:

    int result = INT_MAX;
    int coinChange(vector<int>& coins, int amount) {
        
        int count =0;
        int currTotal = 0;
        int itr=0;
        return solve(coins, amount, count, currTotal, itr);
    }

    bool solve(vc<int> &coins, int target, int count, int currTotal, int itr){

        currTotal += coins[itr];
        count++;

        if(currTotal>target){
            return false;
        }

        if(currTotal==target){
            
            if(count<result){
                result = count;
            }
            return true;
        }

        int size = coins.size();
        bool flag = false;
        for(int i=itr+1; i<size; i++){
            bool temp = solve(coins, target, count, currTotal, i);
            flag = flag || temp;
        }

        return flag;
    }
};