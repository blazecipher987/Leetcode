#include<bits/stdc++.h>
using namespace std;


//!SOLVED
//^ Try solving using runner walker concept

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {

        int count=0;
        bool flag = true;

        ListNode *curr = head;

        while(count<100005){

            if(curr==NULL){
                flag = false;
                break;
            }
            
            count++;
            curr = curr->next;
        }
        cout<<"Count val was: "<<count<<endl;
        return flag;
    }
};