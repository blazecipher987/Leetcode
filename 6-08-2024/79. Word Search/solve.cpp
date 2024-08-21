#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {

    vector<bool> dp;
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        dp.resize(wordDict.size(),true);

        int startingPos = 0;
        
        bool flag = true;
        bool matchFound=true;

        while(matchFound){
            matchFound =false;
            
            for(int i=0; i<wordDict.size(); i++){

                

                string word = wordDict[i];
                int strLen = word.size();

                string subStr = s.substr(startingPos, strLen);

                if(subStr==word){
                    // cout<<"matched"<<word<<endl;
                    matchFound=true;
                    startingPos = startingPos+strLen;
                    // cout<<"Starting pos now: "<<startingPos;
                    break;
                }

                if(startingPos>=s.size()){
                    return true;
                }

            }
        }

        return false;


        
    }



    bool stringFound(string s, vector<string> &t){

        for(auto i : t){
            if(i==s){
                return true;
            }
        }
        return false;
    }
};