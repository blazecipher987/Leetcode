#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {

        int len = s.length();
        bool flag = true;

        int begin =0;
        int end = len-1;

        while(begin<end){
            while(isalnum(s[begin])==false && begin <end){
                begin++;
            }
            while(isalnum(s[end])==false && end>begin){
                end--;
            }

            if(tolower(s[begin])!=tolower(s[end]) || begin>end){
                return false;
            }
            begin++;
            end--;
        }

        return flag;
        
    }
};
