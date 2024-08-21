#include <bits/stdc++.h>
using namespace std;
#include<vector>


//!---- SOLVED
//^---- 1. Create a visited vector of the same size as the board
//^---- 2. Walk the graph from the borders and mark the visited nodes as true,
//^----    this will be the islands that wont be surronded due to border connection

class Solution {
public:


    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));

        for(int i=0; i<board.size() ; i++){
            walkGraph(board, visited, i, 0);
            walkGraph(board, visited, i, board[0].size()-1);
        }

        for(int i=0; i<board[0].size(); i++){
            walkGraph(board, visited, 0, i);
            walkGraph(board, visited, board.size()-1, i);
        }

        printVisitedVector(visited, board);
        
    }

    void walkGraph(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j){

        if(i<0 || i> grid.size()-1 || j<0 || j> grid[0].size()-1 || visited[i][j]==true || grid[i][j]=='X'){
            return;
        }


        visited[i][j] = true;
        if(i+1<grid.size() && grid[i+1][j] == 'O'){
            walkGraph(grid, visited, i+1, j);
        }
        if(i-1>=0 && grid[i-1][j] == 'O'){
            walkGraph(grid, visited, i-1, j);
        }
        if(j+1< grid[0].size() && grid[i][j+1] == 'O'){
            walkGraph(grid, visited, i, j+1);
        }
        if(j-1>=0 && grid[i][j-1] == 'O'){
            walkGraph(grid, visited, i, j-1);
        }
    }

    void printVisitedVector(vector<vector<bool>> visited, vector<vector<char>> &board){
        for(int i=0; i<visited.size(); i++){
            for(int j=0; j<visited[0].size(); j++){

                if(visited[i][j]==true){
                    // board[i][j] = 'O';
                }
                else{
                    // cout<<"X"<< " ";
                    board[i][j] = 'X';
                }
                // cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){

    vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};

    Solution s;
    s.solve(board);

    cout<<endl;

    // for(int i=0; i<board.size(); i++){
    //     for(int j=0; j<board[0].size(); j++){
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    return 0;

}