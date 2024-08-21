#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    unordered_map<char,int> tracks;
    

    int leastInterval(vector<char>& tasks, int n) {

        return findInterval(tasks, n);
        
    }

    int findInterval(vector<char>&tasks, int gap){

        
        //^---- Forming the hashtable
        for(auto i: tasks){

            if(tracks.find(i)!= tracks.end()){
                tracks[i]++;
            }

            else{
                tracks[i]=1;
            }

        }

        int ans=0;
        
        int count =0;
        int moreReq ;

        while(tracks.size()!=0){

            int temp = gap;

            int size = tracks.size();

            cout<<"Size: "<<size<<","<<temp<<endl;

            if(size>=gap+1){
                ans+=size;

                count=-100;
                
            }

            else{
                moreReq = gap+1 -size;
                ans+= moreReq;
                ans+=size;
                count=-200;
            }

            for(auto it = tracks.begin(); it!=tracks.end();){


                     if (it->second > 0) {
                    it->second--;
                }

                if (it->second == 0) {
                    it = tracks.erase(it); // erase returns the next iterator
                } else {
                    ++it; // only increment if not erasing
                }
                    


                }
                    printHash(tracks);
            

                cout<<"Curr Ans:"<<ans<<endl;

        }

        if(count== -200)
            return ans-moreReq;

        return ans;

    }

    void printHash(unordered_map<char,int> map){

        for(auto it= map.begin(); it!=map.end();){
            cout<<it->first<<":"<<it->second<<endl;
            ++it;
        }
    }

    




};
