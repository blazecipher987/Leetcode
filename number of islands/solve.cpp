#include<bits/stdc++.h>
using namespace std;
#include<vector>

class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> components;
    int islandCount;
    int row,col;

    Solution(){
        visited.resize(10000,false);
        islandCount =0;
        
    }

    int numIslands(vector<vector<char>>& grid) {

        //Graph Formation
        adj.resize(grid.size()*grid[0].size());
        row = grid[0].size();
        col = grid.size();

        for(int i=0; i< grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){

                if(grid[i][j]== '1')
                    adj[i*row+j].push_back(i*row+j);
                
                if(grid[i][j]== '1' && grid[i][j+1]=='1' && j<grid[0].size()-1){
                    adj[i*row+j].push_back(i*row+j+1);
                    adj[i*row+j+1].push_back(i*row+j);
                }

                if(grid[i][j]=='1' && grid[i+1][j]=='1' && i<grid.size()-1){
                    adj[i*row+j].push_back((i+1)*row+j);
                    adj[(i+1)*row+j].push_back(i*row+j);
                }
            }
        }

        //Main problem solve
        return findComponents(adj);

        
    }

    void dfs(int node){
        visited[node] = true;
        components.push_back(node);
        for(int u: adj[node]){
            if(visited[u]==false)
                dfs(u);
        }
    }

    int findComponents(vector<vector<int>> &adj){
        for(int i=0; i<row*col; i++){
            if(visited[i]==false && adj[i].size()!=0){
                components.clear();
                dfs(i);
                islandCount++;
                // for(auto u: components){
                //     cout<<u<<" ";
                // }
                // cout<<endl;
            }
        }

        return islandCount;
    }


};


int main(){
    Solution s;
    vector<vector<char>> grid = {{'1','1','0','0','0'},
                                  {'1','1','0','1','0'},
                                  {'1','1','0','0','0'},
                                  {'0','0','0','0','0'}};

    cout<<s.numIslands(grid)<<endl;

    // for(auto i: s.adj){
    //     for(auto j: i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}