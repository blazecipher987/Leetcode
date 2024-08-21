#include<bits/stdc++.h>
using namespace std;

class solve{
    public:
        vector<int> vect;
        bool flag = false;

        bool solveFunc(vector<int> &arr){
            unordered_set<int> s;
            
            s.insert(arr[0]);
            for(int i=1;i <arr.size(); i++){
                if(s.find(arr[i])!=s.end()){
                    flag=true;
                    break;
                }
                s.insert(arr[i]);
            }

            return flag;
        }

};
