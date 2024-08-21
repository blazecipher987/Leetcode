#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAreaa = 0;

        int i=0;
        int j=heights.size()-1;

        while(i<j){
            int area = min(heights[i],heights[j])*(j-i);
            maxAreaa = max(area, maxAreaa);

            if(maxAreaa==area){
                cout<<i<<" "<<j<<" "<<area<<endl;
            }

            if(heights[i+1]>heights[j-1]){
                cout<<"Incrementing i"<<endl;
                cout<<heights[i+1]<<" "<<heights[j-1]<<endl;
                i++;
            }
            else{
                cout<<"Decrementing j"<<endl;
                cout<<heights[i+1]<<" "<<heights[j-1]<<endl;
                
                j--;
            }
        }

        return maxAreaa;
    }

    
};

int main(){
    Solution s;
    vector<int> v = {1,7,2,5,12,3,500,500,7,8,4,7,3,6};
    cout<<s.maxArea(v)<<endl;
    return 0;
}