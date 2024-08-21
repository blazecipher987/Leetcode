#include <bits/stdc++.h>
using namespace std;

#define pb push_back


class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {

        int left = 0;
        int right =0;
        string ans ="";

        dfs(ans, left, right, n);

        return result;
        
    }

    void dfs(string ans, int left, int right, int limit){

        if(right==limit){
            result.pb(ans);
            return;
        }

        if(left<limit){

            // cout<<"Value of Left: "<<left<<endl;
            // ans+='(';
            
            dfs(ans+"(", left+1, right, limit);
        }

        if(left>right){
            // ans+=')';
            dfs(ans+")", left, right+1, limit);
        }
    }
};