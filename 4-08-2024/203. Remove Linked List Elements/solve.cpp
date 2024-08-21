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

        //^No node
        if(head==NULL){
            return {};
        }

        ///^ First checking if the starting values are equl to val

        ListNode *curr = head;
        ListNode *prev = nullptr;

        while(curr && curr->val==val){
            ListNode *temp = curr->next;
            prev = curr;
            curr=temp;
        }

        if(curr==NULL){
            return {};
        }

        ListNode *newHead  = curr;

        prev = nullptr;

        while(curr){

            if(curr->val==val){
                ListNode *temp = curr->next;
                prev->next= curr->next;
                curr = temp;
                
            }

            else{
                   ListNode * t = curr->next;
            prev = curr;
            curr = t;
            }
         
            
        } 

        return newHead;
        
    }
};