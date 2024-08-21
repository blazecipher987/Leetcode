#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vc vector
#define ump unordered_map


class Solution {
public:
    vc<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        
        int size = coins.size();
        dp.resize(amount+1, INT_MAX);
        dp[0]=0;

        int ans = solve(coins, amount);

        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }

    int solve(vc<int> &coins, int amount){

        if(amount<0){
            return INT_MAX;
        }

        if(dp[amount]!=INT_MAX){
            return dp[amount];
        }

        if(dp[amount]==INT_MAX){
            
            for(auto i: coins){
                int curr = solve(coins, amount- i);

                if(curr!=INT_MAX)
                    dp[amount] = min(curr+1, dp[amount]);
            }
        }

        return dp[amount];

    }
};

int main(){

    vc<int> coins = {186,419,83,408};
    sort(coins.begin(), coins.end());
    int target = 6249;

    Solution s;

    cout<<s.coinChange(coins, target)<<endl;
}