#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> result;
        for(int i=0;i<=n; i++){
            int totalResult = convertToBin(i);
            result.push_back(totalResult);
        }

        return result;
        
    }

    int convertToBin(int n){

        bitset<17> temp(n);

        int count=0;
        for(int i=0; i<=17; i++){
            if(temp[i]==1){
                count++;
            }
        }

        return count;
    }
};