#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<pair<int,int>> tracks;
    vector<int> time;
    stack<int> fleets;
    int fleetNum=0;
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        //---- First sort the cars according to their positions
        //sort in descending order
        sortTracks(position, speed);

        //---- Find out the time to reach the target
        for(auto it: tracks){
            time.push_back((target-it.first)/it.second);
        }

        //Print the time vector
        // cout<<"Time:    "<<endl;
        // for(auto it: time){
        //     cout<<it<<" ";
        // }   
        // cout<<endl;

        //---- Add to stack only if the times are lower than the current stack top element
        for(int i=0; i<time.size(); i++){
            while(!fleets.empty() && fleets.top()>=time[i] && i<time.size()-1){
                // cout<<fleets.top()<<" ";
                i++;
            }
            
            if(i==time.size()-1 && fleets.top()>=time[i])
                continue;
                
            fleets.push(time[i]);
        }

        // for(int i=0; i<fleets.size(); i++){
        //     cout<<fleets.top()<<"-";
        //     fleets.pop();
        // }


        return fleets.size();

    }  

    void sortTracks(vector<int> &pos, vector<int> &speed){
        for(int i=0; i<pos.size(); i++){
            tracks.push_back({pos[i], speed[i]});
        }

        //sort in descending order
        sort(tracks.begin(), tracks.end(), [](pair<int,int> a, pair<int,int> b){
            return a.first>b.first;
        });
        // sort(tracks.begin(), tracks.end());
    }
};

int main(){
    Solution s;
    vector<int> pos = {3};
    vector<int> speed = {3};
    cout<<"Ans: " << s.carFleet(10, pos, speed);
    cout<<s.carFleet(12, pos, speed)<<endl;
}