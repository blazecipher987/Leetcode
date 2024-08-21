#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<pair<int,int>> tracks;
        vector<vector<int>> ans;

        int tempMax =INT_MIN;
        for(auto u: intervals){
            if(tempMax<u[1]){
                tempMax=u[1];
            }
        }

        auto comparator = [](const vector<int> &a, const vector<int> &b){
            return a[0]<b[0];
        };

        sort(intervals.begin(), intervals.end(), comparator);   //^-- Sorted according to the first elements asending order

        tracks.resize(tempMax+1, {0,0}); //^---- Initialization


        //^---- Track formation for overlap processing
        for(int i=0; i <intervals.size(); i++){
            pair<int,int> p = {intervals[i][0], intervals[i][1]};

            // for(int j=p.first; j<=p.second; j++){
            //     tracks[j].first+=1;
            // }
            tracks[p.first].second-=1;
            tracks[p.second].second+=1;

            if(p.first==p.second){
                ans.push_back({0,0});
            }
        }


        for(int i=0; i<tracks.size(); i++){
            
            vector<int> temp;
            if(tracks[i].second<0){
                int count = tracks[i].second;

                temp.push_back(i);

                while(count!=0){
                    
                    i++;
                    count+= tracks[i].second;
                }

                temp.push_back(i);
            }

            ans.push_back(temp);
            temp.clear();
        }

        vector<vector<int>> ans2;

        for(auto u: ans){
            if(u.empty()==false){
                ans2.push_back(u);
            }
        }

        return ans2;

    }


};