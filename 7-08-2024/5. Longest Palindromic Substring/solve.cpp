#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vc vector
#define ump unordered_map
#define ll long long int
#define dl double
#define sz size

class Solution
{
public:
    string longestPalindrome(string s)
    {

        int size = s.sz();
        int maxVal = INT_MIN;
        string s ="";

        for(int i=0; i<size;  i++){

            int val1 = maxLength(s, i,i);
            int val2 = maxLength(s, i, i+1);


            if(val1>val2){

            }

        }

        return maxVal;
    }

    pair<int,string> maxLength(string s, int currLeft, int currRight)
    {

        int count = 1;
        int size = s.sz();
        string st ="";

        int left = currLeft;
        int right = currRight;

        if(s[currLeft]!=s[currRight]){
            return {0,st};
        }

        if (left < 0 || right >= size)
        {
            return {0,st};
        }

        bool flag = true;

        while (flag)
        {

            char s1 = s[left];
            char s2 = s[right];

            if (s1 == s2)
            {
                left--;
                right++;
                count++;
            }

            if (left < 0 || right >= size)
            {
                flag = false;
            }
        }

        return right-left+1;
    }
};