#include<bits/stdc++.h>
using namespace std;


//! SOLVED

//^---- 1. Sliding window technique
//^---- 2. First we find the downstream last min element, if this is the very last element than profit 0
//^---- 3. Then we maintain two pointer, update the lower one when a new lower value is found. Keep track of maxProfit


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        stack<int> temp;

        int num = minUntillNow(prices);
        if(num==prices.size()-1){
            return 0;
        }

        int currProfit =0;
        int maxProfit=0;

        int lowerPointer = num;
        int higherPointer=num+1;

        while(lowerPointer<prices.size() && higherPointer<prices.size()){

            //^curr value is lower that lowerpointer value
            if(prices[higherPointer]<prices[lowerPointer]){
                lowerPointer = higherPointer;
                higherPointer++;
            }
            else{
                currProfit = prices[higherPointer]- prices[lowerPointer];
                maxProfit = max(maxProfit, currProfit);
                higherPointer++;
            }
            

        }
        return maxProfit;

        
    }

    int minUntillNow(vector<int> &prices){
        int i=0;

        while(i!=prices.size()-1 && prices[i+1]<prices[i]){
            i++;
        }
        return i;
    }
};

int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    vector<int> prices2 = {5,4,3,2};
    vector<int> prices3 = {7,2,5,3,6,1,10,20,3,2,1};
    cout<<s.maxProfit(prices3)<<endl;
    return 0;
}