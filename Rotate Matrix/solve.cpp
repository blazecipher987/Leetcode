#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        vector<int> tracks[n];

        for(int col=0; col<matrix[0].size(); col++){
            for(int row=matrix.size()-1; row>=0; row--){

                tracks[col].push_back(matrix[row][col]);
            }
        }

        for(auto &r: matrix){
            r.clear();
        }        
        matrix.clear();

        for(int i=0; i<n; i++){
            matrix.push_back(tracks[i]);
        }

        
    }
};
