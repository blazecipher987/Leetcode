#include<bits/stdc++.h>
using namespace std;
#include<vector>


class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {

        int size = dist.size();

        // sort(dist.begin(), dist.end());

        if(ceil(hour)<size){
            return -1;
        }

        int resutl = minimization(dist, hour);
        return resutl;
        
    }

    
    int minimization(vector<int> vect, double hour){

        int ans = vect.size();
        int lower = 1;
        // int higher = vect[ans-1];
        int higher = 10000000;

        while(lower<=higher){

            int mid = lower + (higher-lower)/2;

            double result = divFunc(vect, mid);

            if(result<=hour){
                ans=mid;
                higher = mid-1;
            }
            else{
                lower=mid+1;
            }

        }
            return ans;
        
    }

    double divFunc(vector<int> dist, int divisor){

        int count=0;
        double temp=0;

        // for(auto i: dist){
        //     count += (i+divisor-1)/divisor;
        // }

        int size = dist.size();

        for(int i=0; i<size-1; i++){
            temp +=(dist[i]+divisor-1)/divisor;
            cout<<"Curr temp val: "<<temp<<endl;
        }
        temp+= (dist[size-1]*1.0/divisor*1.0);

        cout<<"returning: "<<temp<<", Divisor: "<<divisor<<endl;
        return temp;
        
        // return count;
    }

};