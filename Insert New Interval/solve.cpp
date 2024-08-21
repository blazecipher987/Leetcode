#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<pair<int, char>> tracks;
        tracks.resize(intervals[intervals.size()-1][1], {0,'a'});

        vector<vector<int>> result;
        vector<int> ans;

        //^---- Getting the pair vector ready with the already given intervals
        for(auto z: intervals){
            pair<int,int> p = {z[0], z[1]};

            int x = p.first;
            int y = p.second;

            if(tracks[x].second=='e'){
                tracks[x].second='a';
            }
            else{
                tracks[x].second='s';
            }
            tracks[y].second='e';

            for(int i=x; i<=y; i++){
                tracks[i].first+=1;
            }
            
        }

        //^Fitting in the new interval to see if there is an overlap

        bool overlap = false;
        
        for(int i=newInterval[0]; i<=newInterval[1]; i++){
            tracks[i].first +=1;

            if(tracks[i].first==2){
                overlap=true;
            }
        }

        if (tracks[newInterval[0]].second == 'e') {
            tracks[newInterval[0]].second = 'a';
        } else {
            tracks[newInterval[0]].second = 's';
        }
        tracks[newInterval[1]].second = 'e';

        //^----If there is overlap

        for(int i=0; i<tracks.size(); i++){



            if(tracks[i].second=='s'){
                int count=-1;
                ans.push_back(i);

                while(count!=0){

                    if(tracks[i].second=='e'){
                        count++;
                    }
                    if(tracks[i].second=='s'){
                        count--;
                    }

                    i++;
                }

                ans.push_back(i);
                result.push_back(ans);
                ans.clear();
            }
        }

        return result;
        
    }
};
