#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int result = cornerCase(prices);
        if(result==0 || prices.size()==1){
            cout<<"Corner Case"<<endl;
            return 0;
        }

        return combine(prices);


    }

private:
    int cornerCase(vector<int>&pric ){
        auto minIt = min_element(pric.begin(), pric.end());
        int maxDistance = distance(pric.begin(), minIt);

        if(maxDistance==pric.size()-1){
            return 0;
        }
        return 1;
    }

    int findMin(vector<int> &pric, int start){
        
        int i=start;
        int minD = i;

        while(pric[i+1]<=pric[i]){
            minD=i+1;

            i++;
        }

        return minD;
    }

    int findMax(vector<int> &pric, int start){
        
        int i=start;
        int maxD = i;

        while(pric[i+1]>pric[i]){
            maxD=i+1;

            i++;
        }

        return maxD;
    }

    int combine(vector<int> &prices){
        int i=0;
        int j=1;

        int maxVal =0;

        while(j<= prices.size() && i<= prices.size()){
            i= findMin(prices, i);
            j = findMax(prices,j);

            if(prices[j]-prices[i]>>maxVal){
                maxVal = prices[j] - prices[i];
            }

            i = j+1;
            j= i+1;

        }

        return maxVal;


    }

};



int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<s.maxProfit(prices);
    return 0;
}