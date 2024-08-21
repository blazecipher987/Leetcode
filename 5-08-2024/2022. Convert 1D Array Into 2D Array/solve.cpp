#include <bits/stdc++.h>
using namespace std;

#define pb push_back


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        int size = original.size();
        int total = m*n;
        if(total!=size){
            return {};
        }
        int count=1;
        vector<vector<int>> ans;
        vector<int>temp;

        for(int i=0; i<size; i++){
            
            temp.pb(original[i]);
            if(count==n){
                ans.push_back(temp);
                temp.clear();
                count=1;
            }
            else{
                count++;
            }
        }

        return ans;
    }
};