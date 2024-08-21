#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {

        return totalFunc(nums);
    }

    int totalFunc(vector<int> &nums)
    {

        set<int> zeros = getZeros(nums);

        int zeroSize = zeros.size();

        if (zeroSize == 0)
        {
            return whenOnlyNeg(nums);
        }
        else
        {
            vector<vector<int>> seperations = splitVec(nums, zeros);
            
            int totalMax = INT_MIN;
            for (auto i : seperations)
            {
                int curr = whenOnlyNeg(i);
                if (curr > totalMax)
                {
                    totalMax = curr;
                }
            }

            return totalMax;
        }
    }

    int whenOnlyNeg(vector<int> nums)
    {

        set<int> pos = negNums(nums);
        int posSize = pos.size();
        if (posSize % 2 == 1)
        {
            int result = getMaxMultiplicationOfNegArr(nums, pos);
            return result;
        }
        else
        {
            return getMultiplication(nums);
        }
    }

    int getMaxMultiplicationOfNegArr(vector<int> nums, set<int> pos)
    {

        vector<vector<int>> tracks = splitNeg(nums, pos);

        int totalMax = INT_MIN;
        for (auto i : tracks)
        {

            int currMax = 1;

            currMax = getMultiplication(i);

            if (currMax > totalMax)
            {
                totalMax = currMax;
            }
        }

        return totalMax;
    }

    //^ ---- Get the multiplication of an entire vector

    int getMultiplication(vector<int> nums)
    {
        int ans = 1;

        for (auto i : nums)
        {
            ans *= i;
        }

        return ans;
    }

    vector<vector<int>> getZeroSeperation(vector<int> &nums)
    {

        set<int> temp = getZeros(nums);
        if (temp.size() > 0)
        {
            return splitVec(nums, temp);
        }

        return {nums};
    }

    //^---- Get the indexes with zeros
    set<int> getZeros(vector<int> nums)
    {
        set<int> zeros;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == 0)
            {
                zeros.insert(i);
            }
        }
        return zeros;
    }

    //^---- Get the indexs with neg values
    set<int> negNums(vector<int> nums)
    {
        int count = 0;
        set<int> negPost;
        int size = nums.size();

        for (int i = 0; i < size; i++)
        {
            if (nums[i] < 0)
            {
                negPost.insert(i);
            }
        }

        return negPost;
    }

    vector<vector<int>> splitVec(vector<int> &nums, set<int> delimiter)
    {

        vector<int> temp;
        vector<vector<int>> ans;
        int size = nums.size();

        // cout<<"Delimiter details: "<<endl;
        // for(const int &i: delimiter){
        //     cout<<i<<",";
        // }
        // cout<<endl;


        for (int i = 0; i < size; i++)
        {

            if (delimiter.find(i) != delimiter.end() && temp.size() != 0)
            {
                ans.pb(temp);
                temp.clear();
            }

            else
            {
                cout<<endl;
                // cout<<"Inserting:-"<<nums[i];
                temp.pb(nums[i]);
            }
        }

        if(temp.size()!=0){
            ans.pb(temp);
        }

        // cout<<"CUrr double vector:"<<endl;
        for(auto u: ans){
            for(auto i:u){
                cout<<i<<",";
            }
            cout<<endl;
        }

        return ans;
    }

    vector<vector<int>> splitNeg(vector<int> &nums, set<int> delim)
    {

        vector<int> temp;
        vector<vector<int>> ans;

        int size = nums.size();

        if (delim.size() != 0)
        {
            for (const int &i : delim)
            {
                vector<int> firstPart;
                vector<int> secondPart;
                for (int k = 0; k < i; k++)
                {
                    firstPart.pb(nums[k]);
                }
                for (int l = i + 1; l < size; l++)
                {
                    secondPart.pb(nums[l]);
                }

                ans.pb(firstPart);
                ans.pb(secondPart);

                
            }
            return ans;
            
        }
        return {nums};
    }
};