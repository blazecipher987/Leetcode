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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        pair<ListNode*,int> temp;
        l1 = l1;
        temp = reversal(l1);
       
        int n1 = temp.second;

        l2 = l2;
        temp = reversal(l2);
        int n2 = temp.second;

        if(n1>n2){
            ListNode *result= summation(l1,l2);
            return reversal(result).first;
        }
        else{
            ListNode *result= summation(l2,l1);
            return reversal(result).first;
        }

    }

    pair<ListNode*,int> reversal(ListNode *head){


        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *currNext = head->next;

        //^only single element
        if(currNext==NULL){
            return {head,1};
        }

        int count=0;
        while(curr!=NULL){

            ListNode *temp2 = curr->next;

            curr->next = prev;
            prev = curr;
            curr = temp2;
            count++;
        }

        return {prev,count};
    }

    ListNode* summation(ListNode *h1, ListNode *h2){


        ListNode *curr1 =h1;
        ListNode *prev =nullptr;
        ListNode *result =h1;
        ListNode *curr2 =h2;
        int main,carry=0;

        while(curr1!=NULL){
            int sum;

            if(curr2!=NULL){
                sum = curr1->val + curr2->val +carry;
                curr2 = curr2->next;

            }
            else{
                sum = curr1->val + 0 + carry;
            }

            

            
            main = sum%10;
            carry = sum/10;
           
            curr1->val = main;

            prev=curr1;
            curr1 = curr1->next;
        }
        if(carry>0){
            ListNode *ne = new ListNode(carry,nullptr);
            prev->next=ne;
        }

        return result;
    }
};