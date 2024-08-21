#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string ans = "";
    string multiply(string num1, string num2)
    {

        int size1 = num1.size();
        int size2 = num2.size();

        vector<int> result(size1 + size2, 0);

        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                result[i + j] += ((int)num1[i] - '0') * ((int)num2[j] - '0');
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] = result[i + j] % 10;
            }
        }

        for (int i = result.size()-1; i >=0; i--)
        {
            if (result[i] == 0 && i == result.size()-1)
                continue;
            ans += to_string(result[i]);
        }

        return ans;
    }
};
