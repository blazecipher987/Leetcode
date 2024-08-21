#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int rowSize = matrix.size();
        int colSize = matrix[0].size();


        for(int i=0; i<rowSize; i++){
            for(int j=i+1; j<colSize; j++){

                int temp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }

        int half = (colSize-1)/2;
        for(int i=0; i<rowSize; i++){
            for(int j=0; j<=half; j++){
                
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][colSize-1-j];
                matrix[i][colSize-1-j] = temp;
            }
        }

        
    }
};