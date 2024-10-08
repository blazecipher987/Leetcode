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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head){
            return {};
        }

        if(head->next==nullptr){
            return head;
        }

        ListNode *prev = head;
        
        ListNode *curr = head->next;

        while(curr){
            if(prev->val==curr->val){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                ListNode *temp = curr->next;
                prev = curr;
                curr = temp;
            }
        }

        return head;
    }
};