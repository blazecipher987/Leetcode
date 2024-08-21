#include<bits/stdc++.h>
using namespace std;
#include<vector>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        return getCalcu(points, k);
    }

    vector<vector<int>> getCalcu(vector<vector<int>> points, int k){

        vector<pair<int,pair<int,int>>> tracks;

        

        //^---- Making the vector for heap operations
        for(auto i: points){
            int dist = ((i[0]*i[0]) + (i[1]*i[1]));
            cout<<dist<<endl;
            tracks.push_back({dist, {i[0],i[1]}});
        }


        int count =1;
        vector<vector<int>> ans;
            make_heap(tracks.begin(), tracks.end(), greater<>());

        while(count<=k){
            pop_heap(tracks.begin(), tracks.end(), greater<>());
            pair<int,pair<int,int>> largerst = tracks.back();
            ans.push_back({largerst.second.first, largerst.second.second});
            tracks.pop_back();
            count++;
        }

        return ans;
    }
};
