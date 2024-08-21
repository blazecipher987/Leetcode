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
        
       ListNode *greater =l1;
       ListNode *lesser =l2;
       ListNode *prev =nullptr;

       ListNode *ans = new ListNode();
       ListNode *h = ans;

       int main,carry=0;

       while(greater){

        if(lesser){
            int sum = greater->val + lesser->val +carry;
            main= sum%10;
            carry =sum/10;

            ListNode *temp = new ListNode(main,nullptr);
            ans->next = temp;
            ans = ans->next;

            greater = greater->next;
            lesser = lesser->next;
        }
        else{
            int sum  = greater->val + carry;
            main= sum%10;
            carry =sum/10;

            ListNode *temp = new ListNode(main,nullptr);
            ans->next = temp;
            ans = ans->next;

            greater = greater->next;

        }

        



        if(!greater && lesser){
            greater=lesser;
            lesser=nullptr;
        }

        

       }

       if(carry>0){
            ListNode *temp = new ListNode(carry,nullptr);
            ans->next = temp;
            ans = ans->next;
        }

       return h->next;
    }


};