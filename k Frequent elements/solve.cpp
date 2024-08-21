#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<pair<int,int>> vect;
        vector<int> ans;

        for(int i=0; i <nums.size(); i++){
            mp[nums[i]]++;
        }

        for(auto it: mp){
            vect.push_back({it.second,it.first});
        }

        sort(vect.begin(),vect.end(),greater<pair<int,int>>());

        for(int i=0; i<k; i++){
            ans.push_back(vect[i].second);
        }

        return ans;
    }
};
