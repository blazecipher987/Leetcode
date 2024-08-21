#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vc vector
#define ump unordered_map

class Solution
{

    vc<int> dp;
    vc<vc<int>> pascalV;
    vc<vc<int>> result;

public:
    vc<vc<int>> generate(int n)
    {
        dp.resize(n + 1, -1);
        pascalV.resize(n, vc<int>(n));
        fill(pascalV.begin(), pascalV.end(), vc<int>(n, -1));

        vector<int> ans;

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i <= j; i++)
            {

                int x = pascal( j, i);
                ans.pb(x);
            }

            result.pb(ans);
            ans.clear();
        }

        // printVector(ans);

        return result;
    }

    int pascal(int r, int c)
    {

        if (c == 0 || c == r)
        {
            pascalV[r][c] = 1;
        }

        if (pascalV[r][c] == -1)
        {
            pascalV[r][c] = pascal(r - 1, c - 1) + pascal(r - 1, c);
            return pascalV[r][c];
        }

        return pascalV[r][c];
    }

    int factorial(int n)
    {

        if (n == 0 || n == 1)
        {
            dp[n] = 1;
            return 1;
        }

        if (dp[n] == -1)
        {
            dp[n] = n * factorial(n - 1);
            return dp[n];
        }
        return dp[n];
    }

    void printVector(vc<int> tracks)
    {

        for (auto i : tracks)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main()
{

    Solution s;

    // cout<<s.factorial(5)<<endl;

    s.solve(5);
}