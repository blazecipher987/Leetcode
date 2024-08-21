#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int size1 = s.size();
        int size2 = t.size();

        if(size1==0 && size2==0){
            return true;

        }
        
        bool flag =false;

        int curr=0;

        for(int i=0; i<size2;i++){

            if(s[curr]==t[i]){

            cout<<"Curr: "<<curr<<", i: "<<i<<endl;

                curr++;
                // i++;
            }


            if(curr==size1){
                flag = true;
                break;
            }
        }

        return flag;
        
    }
};