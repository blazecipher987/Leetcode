#include<bits/stdc++.h>
using namespace std;

class Solution {

    unordered_map<char,int> map;
    int maxCount =0;

public:
    int lengthOfLongestSubstring(string s) {

        int i,j;
        int size = s.size();
        if(size<2){
            return size;
        }
        else if(size==2){
            if(s[0]==s[1]){
                return 1;
            }
            else{
                return 2;
            }
        }

        else{
            i=0;
            j=1;
            int temp=0;

            map[s[i]]=i;

            while(i<size && j<size){
                
                cout<<"ITeration: "<<temp++<<endl;
                cout<<"Curr i: "<<s[i]<<",at Pos: "<<i<<endl;
                cout<<"Curr j: "<<s[j]<<",at Pos: "<<j<<endl;

                if(map.find(s[j])!=map.end()){
                    cout<<"Sikeee"<<endl;
                     
                    if(maxCount<j-i+1){
                        maxCount = j-i;
                    }

                    // map.clear();
                    i= map[s[j]]+1;333333333333333
                    j++;
                    map[s[i]]=i;


                }
                else{
                    map[s[j]]=j;
                    j++;
                    // maxCount++;
                }
            }

            int val = j-i;
            if(val>maxCount){
                return val;
            }

            return maxCount;

        }
        
    }


};

int main(){
    Solution s;
    cout<<s.lengthOfLongestSubstring("abcabcbb");
    return 0;
}