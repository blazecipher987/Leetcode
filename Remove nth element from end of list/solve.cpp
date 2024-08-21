#include<bits/stdc++.h>
using namespace std;
#include<vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        
        
        int size=0;

        ListNode *curr2 = head;

        while(curr2!=NULL){
            size++;
            curr2 = curr2->next;
        }

        if(size==1)
            return {};

        if(size==n){
            return head->next;
        }

        int gap = size - (n-1);

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *currNext = curr->next;

        int count=1;

        while(count!=gap){

            ListNode *temp = curr;
            ListNode *temp1= currNext;
            prev = curr;
            curr = temp1;
            currNext = curr->next;

            count++;
        }

        prev->next = currNext;
        return head;
        
    }
};