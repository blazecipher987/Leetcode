#include<bits/stdc++.h>
using namespace std;

//!SOLVED
//^---- 1. Just maintain hashmaps for the rwos, cols and quadrants, check for inconsistencies

class Solution {
public:

    
    bool flag = true;

    bool isValidSudoku(vector<vector<char>>& board) {

        if(allQuadCalculation(board) && totalRowsChecker(board) && totalColsChecker(board)){
            return true;
        }
        return false;
        
    }

    bool allQuadCalculation(vector<vector<char>> &board ){

        for(int i=0; i<board.size(); i=i+3){
            for(int j=0; j<board[0].size(); j=j+3){
                if(!quadrantCheker(board,i,j,3)){
                    return false;
                }
            }
        }
        return true;
    }

    bool quadrantCheker(vector<vector<char>> &board, int row, int col, int chunk){

        unordered_map<char,int> tracks;
        for(int i=row; i<row+chunk; i++){
            for(int j=col; j<col+chunk; j++){
                
                char c = board[i][j];
                if(tracks.find(c)!= tracks.end()){
                    return false;
                }
                else{
                    if(c!='.'){
                        tracks[c]=i;
                    }
                }
            }
        }
    }

    bool totalRowsChecker(vector<vector<char>> &board){

        for(int i=0; i<board.size(); i++){
            if(!rowChecker(i,board)){
                return false;
            }
        }
        return true;
    }

    bool totalColsChecker(vector<vector<char>> &board){

        for(int i=0; i<board[0].size(); i++){
            if(!colChecker(i,board)){
                return false;
            }
        }
        return true;
    }

    bool rowChecker(int rowNum, vector<vector<char>> &board){

        unordered_map<char,int> tracks;

        for(int i=0; i<board[0].size(); i++){
            char c = board[rowNum][i];

            if(tracks.find(c)!= tracks.end()){
                tracks.clear();
                return false;
            }
            else{
                if(c!='.'){
                    tracks[c]=i;
                }
            }
        }
        tracks.clear();
        return true;
    }

    bool colChecker(int colNum, vector<vector<char>> &board){

         unordered_map<char,int> tracks;

        for(int i=0; i<board.size(); i++){
            char c = board[i][colNum];

            if(tracks.find(c)!= tracks.end()){
                tracks.clear();
                return false;
            }
            else{
                if(c!='.'){
                    tracks[c]=i;
                }
            }
        }
        tracks.clear();
        return true;

    }
};