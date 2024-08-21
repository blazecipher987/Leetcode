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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        

        if(!list1 && !list2){
            return {};
        }
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }

        ListNode *newHead = new ListNode();
        ListNode *t = newHead;

        ListNode *curr1 = list1;
        ListNode *curr2 = list2;
        
        while(curr1 && curr2 ){
            
            if(curr1->val< curr2->val){
                ListNode *temp = new ListNode(curr1->val);
                newHead->next = temp;
                newHead = newHead->next;

                curr1 = curr1->next;
            }
            else{
                ListNode *temp = new ListNode(curr2->val);
                newHead->next = temp;
                newHead = newHead->next;

                curr2 = curr2->next;
            }
        }

        if(curr1){
            newHead->next = curr1;
        }
        if(curr2){
            newHead->next = curr2;
        }

        return t->next;
    }
};