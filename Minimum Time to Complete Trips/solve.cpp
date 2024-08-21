#include<bits/stdc++.h>
using namespace std;
#include<vector>


class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        return getTime(time, totalTrips);
    }

    long long int getTime(vector<int> vect, int totalTrips){

        long long int lower = 1;
        long long int higher = findMin(vect)*vect.size();
        // long long int higher = findMin(vect)*totalTrips;


        long long int ans = 1000000000;

        while(lower<=higher){

            int time = lower + (higher-lower)/2;

            long long int madeTrips = getTripTIme(vect, time);
            if(madeTrips>=totalTrips){

                ans = time;
                higher = time-1;
            }

            else{
                lower = time+1;
            }
        }

        return ans;
    }

    long long int getTripTIme(vector<int> time, int divisor){

        long long int count=0;

        for(auto i: time){
            count+= divisor/i;
        }

        return count;
    }

    long long int findMin(vector<int> time){
        int temp = INT_MAX;

        for(auto i: time){
            if(temp>i){
                // i=temp;
                temp=i;
            }
        }

        return temp;
    }
};