#include<bits/stdc++.h>
using namespace std;

//! SOLVED

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        set<int> rows;
        set<int> cols;

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        allCols(matrix, cols);
        allRows(matrix, rows);
        
    }


    void allCols(vector<vector<int>> &matrix, set<int> s){
        for(auto x: s)
            {colZero(matrix, x);}
    }

    void allRows(vector<vector<int>> &matrix, set<int> s){
        for(int x: s)
            {rowZero(matrix, x);}
        // colZero(matrix, colNum);
    }

    void rowZero(vector<vector<int>> &matrix, int rowNum){

        for(int i=0; i<matrix[0].size(); i++){
            matrix[rowNum][i]=0;

        }
    }

    void colZero(vector<vector<int>> &matrix, int colNum){
        for(int i=0; i<matrix.size(); i++){
            matrix[i][colNum]=0;
        }
    }

};