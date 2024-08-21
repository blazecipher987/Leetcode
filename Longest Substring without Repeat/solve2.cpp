#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<char, int> hashMap;
    int lengthOfLongestSubstring(string s)
    {

        if (s.size() == 0 || s.size() == 1)
        {
            return s.size();
        }

        int low = 0;
        int high = 1;
        int maxCount = 0;
        int currCount = 0;

        hashMap[s[low]] = low;

        while (low < s.size() && high < s.size())
        {

            if (hashMap.find(s[high]) != hashMap.end())
            {
                currCount = high - low;
                maxCount = max(maxCount, currCount);

                int t = low;
                low = giveCharLastPos(s[high], hashMap) + 1;
                deleteSpecifiedEntries(s, hashMap, t, high);

            
                hashMap[s[high]] = high;

                // hashMap[s[high]] = high;
                high++;
            }
            else
            {
                hashMap[s[high]] = high;
                high++;
            }
        }

        if(maxCount==0){
            return high-low;
        }

        return maxCount;
    }

    //^ Give the number of unique characters in the hashmap
    int hashMapSearcher(unordered_map<char, int> hashMap)
    {

        int count = 0;
        vector<char> keys = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        for (auto key : keys)
        {
            if (hashMap.find(key) != hashMap.end())
            {
                count++;
            }
        }
        return count;
    }

    int giveCharLastPos(char c, unordered_map<char, int> hashMap)
    {

        if (hashMap.find(c) != hashMap.end())
        {
            return hashMap[c];
        }
        return -1;
    }

    void deleteSpecifiedEntries(string s, unordered_map<char, int> &hashMap, int low, int high)
    {

        int uptilVal = hashMap[s[high]];

        for (int i = low; i < uptilVal; i++)
        {

            auto it = hashMap.find(s[i]);
            hashMap.erase(it);
        }

    }

    void printHashMap(unordered_map<char, int> hashMap)
    {
        for (auto it : hashMap)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
};

int main()
{

    Solution s;
    string str = "abcdxyszdcxya";
    string str2 = "abcabcbb";
    string str3 = "au";
    string str4 = "pwwkew";
    string str5 = "bba";
    // s.hashMap['a'] = 0;
    // s.hashMap['b'] = 1;
    // s.hashMap['c'] = 2;
    // s.hashMap['d'] = 3;
    // s.hashMap['x'] = 4;
    // s.hashMap['y'] = 5;
    // s.hashMap['s'] = 6;
    // s.hashMap['z'] = 7;

    // s.deleteSpecifiedEntries(str, s.hashMap, 0, 8);
    // s.printHashMap(s.hashMap);
    cout<<s.lengthOfLongestSubstring(str5)<<endl;

    return 0;
}