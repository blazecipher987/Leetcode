#include<bits/stdc++.h>
using namespace std;
#include<vector>


//! SOLVED
//^---- 1. The 1 and 0's are characaters, not strings
//^---- 2. k

class Solution {
public:
    int total=0;
    int maxCount =0;
    int numIslands(vector<vector<char>>& grid) {

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    int temp=0;
                    total++;
                    walkGrid(grid, i, j, temp, maxCount);

                }
            }
        }

        return total;
        
    }

    void walkGrid(vector<vector<char>> &grid, int i, int j, int &currCount, int &maxCount){

        if(i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1 || grid[i][j]=='0'){
            return ;
        }

        grid[i][j]='0';
        walkGrid(grid, i+1, j, currCount, maxCount);
        walkGrid(grid, i-1, j, currCount, maxCount);

        walkGrid(grid, i, j+1, currCount, maxCount);
        walkGrid(grid, i, j-1, currCount, maxCount);

    }


};


int main(){
    
        vector<vector<char>> grid = {{'0'
                                    }};
    
        Solution s;
        cout<<s.numIslands(grid)<<endl;
    
        return 0;
}