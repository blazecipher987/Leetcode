#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string str1;
        for(auto it: strs){
            str1+=it;
            str1+=".";
        }

        return str1;
    }

    vector<string> decode(string s) {

        stringstream ss(s);
        char del= '.';
        string token;
        vector<string> ans;

        while(getline(ss, token, del)){
            ans.push_back(token);
        }
        
        return ans;
    }
};

int main(){
    char c = 'z';
    //make a char to lowercase
    
    cout<<(int)c<<endl;
}