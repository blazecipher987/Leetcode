#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vc vector
#define ump unordered_map


class Solution{

public:
    
    vc<int> dp;

    int fibonacchi(int n){

        dp.resize(n+1,-1);

        return f(n);
    }

    int f(int n){

        if(n==0 || n==1){
            return n;
        }

        if(dp[n]!=-1){
            return dp[n];
        }

        if(dp[n]==-1){
            dp[n] = f(n-1) + f(n-2);
            return dp[n];
        }

        return -100;
    }

};

int main(){

    Solution s;

    cout<<s.fibonacchi(6)<<endl;
}