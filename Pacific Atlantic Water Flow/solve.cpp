#include <bits/stdc++.h>
using namespace std;


class Solution {


public:
    bool flagPacific;
    bool flagAtlantic;
    vector<vector<int>> ans;
    vector<int> temp;

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        for(int i=0; i< heights.size(); i++){
            for(int j=0; j< heights[0].size(); j++){
                flagPacific = false;
                flagAtlantic = false;

                dfsP(heights, i, j, flagPacific);
                dfsA(heights, i, j, flagAtlantic);

                if(flagPacific && flagAtlantic){
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }

        return ans;
        
    }

    void dfsP(vector<vector<int>> &grid, int i, int j, bool &flag){

        if(i<0 || j<0){     //^ WEnt over the border of pacific
            flag= true;
            return;
        }

        grid[i][j]== -1;       //^ This route has been visited, water flows only downwards

        if(grid[i][j] >= grid[i-1][j] && grid[i-1][j]!=-1){ //^ checking the left side
            dfsP(grid, i-1, j, flag);
        }

        if(grid[i][j] >= grid[i][j-1] && grid[i][j-1]!=-1){     //^ Checking the upper side
            dfsP(grid, i, j-1, flag);
        }
    }

    void dfsA(vector<vector<int>> &grid, int i, int j, bool &flag){

        if(i>grid.size()-1 || j> grid[0].size()-1){     //^ WEnt over the border of pacific
            flag= true;
            return;
        }

        grid[i][j]== -1;       //^ This route has been visited, water flows only downwards

        if(grid[i][j] >= grid[i+1][j] && grid[i+1][j]!=-1){ //^ checking the left side
            dfsA(grid, i+1, j, flag);
        }

        if(grid[i][j] >= grid[i][j+1] && grid[i][j+1]!=-1){     //^ Checking the upper side
            dfsA(grid, i, j+1, flag);
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{1,2,2,3,5},
                                {3,2,3,4,4},
                                {2,4,5,3,1},
                                {6,7,1,4,5},
                                {5,1,1,2,4}};

    vector<vector<int>> ans = s.pacificAtlantic(grid);

    for(auto u: ans){
        for(auto v: u){
            cout<<v<<" ";
        }
        cout<<endl;
    }

    return 0;
}