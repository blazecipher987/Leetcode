#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        bool flag = false;
        unordered_map<string,int> mp;

        for(int i=0;i <s.size(); i++){
            mp[s.substr(i,1)]++;
        }

        for(int i=0;i<t.size();i++){
            if(mp.find(t.substr(i,1))!=mp.end()){
                mp[t.substr(i,1)]--;
            }
            else{
                return false;
            }
        }

        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second!=0){
                return false;
            }
        }
    }
};
