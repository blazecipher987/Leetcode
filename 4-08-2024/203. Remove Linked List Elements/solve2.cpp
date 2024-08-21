#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


 class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        if(!head){
            return {};
        }

        ListNode *prev = new ListNode();
        ListNode *curr = head;
        prev->next = curr;
        ListNode *newHead = prev;

        while(curr){
            if(curr->val==val){
                ListNode *temp = curr->next;
                prev->next = curr->next;
                curr = temp;
            }
            else{
                ListNode *temp = curr->next;
                prev = curr;
                curr = temp;
            }
        }

        return newHead->next;
        
    }
};