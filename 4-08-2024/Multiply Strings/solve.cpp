#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {

        return multiplyStr(num1,num2);
    }

    string multiplyStr(string s1, string s2)
    {
        int size1 = s1.size();
        int size2 = s2.size();

        int prevSum = 0;
        int lower;
        int carry = 0;
        string ans;

        string bigger =s1;
        string smaller =s2;

        if(size2>size1){
            bigger=s2;
            smaller=s1;
        }

        size1=bigger.size();
        for(int i=size1-1; i>=0; i++){
            int result = resultt(bigger, smaller[i]) + carry;
            
            int excess = result%10;
            ans.append(to_string(excess));
            carry = result/10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    int getIntFromString(string s, int i)
    {

        return s[i] - '0';
    }

    int resultt(string s1, char s2)
    {

        int size = s1.size();
        int x = s2 - '0';
        int sum = 0;
        int carry = 0;
        int k = 0;
        for (int i = size - 1; i >= 0; i--)
        {

            int curr = s1[i] - '0';
            sum = (curr * x) * pow(10, k) + sum;

            k++;
        }

        return sum;
    }
};