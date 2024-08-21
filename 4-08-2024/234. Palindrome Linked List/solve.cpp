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
    bool isPalindrome(ListNode* head) {

        ListNode *slower = head;
        ListNode *faster = head;

        int odd=0;

        while(faster && faster->next){
            slower = slower->next;
            faster = faster->next->next;
        }

        if(faster!=NULL){
            odd=1;
        }
        
        ListNode *l1 = head;
        ListNode *l2;
        if(odd==1){
            l2 = reversal(slower->next);
        }
        else{
            l2 = reversal(slower);
        }

        bool flag = true;
        while(l1 && l2){

            if(l1->val != l2->val){
                flag = false;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }

        return flag;
        
    }

    
    ListNode* reversal(ListNode *head){
        ListNode *curr = head;
        ListNode *prev = nullptr;

        while(curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    
};