#include<bits/stdc++.h>
using namespace std;

//! COULDNT CHECK, PREMIUM PROBLEM

class Solution{

public:
    bool meeting(vector<vector<int>> &intervals){

        vector<pair<int,int>> ans = sortVals(intervals);

        for(int i=0; i<ans.size()-1; i++){

            int endingTime = ans[i].second;
            int startingTime = ans[i+1].first;

            if(startingTime<endingTime){
                return false;
            }
        }
        return true;

    }

    vector<pair<int,int>> sortVals(vector<vector<int>> &interval){

        vector<pair<int,int>> ans;
        for(auto i:interval){
            ans.push_back({i[0],i[1]});
        }

        sort(ans.begin(), ans.end());
        return ans;
    }

};