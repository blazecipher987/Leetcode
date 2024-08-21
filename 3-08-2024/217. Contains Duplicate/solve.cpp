#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long int

class Solution {
public:

    unordered_map<int,int> map;

    bool containsDuplicate(vector<int>& nums) {
        

        return fillMap(nums);
    }

    bool fillMap(vector<int> &nums){
        
        bool flag = false;
        for(auto i: nums){

            if(map.find(i)!= map.end()){
                flag=true;
                break;
            }
            else{
                map[i]++;
            }

        }

        return flag;
    }
};