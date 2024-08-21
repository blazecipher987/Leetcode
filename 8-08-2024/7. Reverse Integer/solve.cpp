#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vc vector
#define ump unordered_map
#define ll long long int
#define dl double
#define sz size
#define pq priority_queue


class Solution {
public:
    int reverse(int x) {

        bool isNeg = false;
        if(x<0){
            isNeg = true;
            x = abs(x);
        }
        string num = getStringVersion(x);

        // reverse(num.begin(), num.end());

        num = reversal(num);

        ll curr = stoll(num);
        if(curr> INT_MAX ){
            return 0;
        }
        
        if(!isNeg){
            return (int)curr;
        }
        return (int)curr*(-1);
        
    }

    string getStringVersion(int x){
        return to_string(x);
    }

    string reversal(string s){

        int size = s.size();

        int left = 0;
        int right = size-1;

        while(left<right){
            char temp = s[right];
            s[right] = s[left];
            s[left] =temp;
            left++;
            right--;
        }

        return s;
    }


};