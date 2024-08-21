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

        ListNode *curr1 = l1;
        ListNode *curr2 = l2;

        ListNode *prev1 = nullptr;
        ListNode *prev2 = nullptr;


        while(curr1!=NULL){

            int x = curr1->val + curr2->val;

            int main,carry=0;


            main = x%10;
            if(x>9){
                
                carry = x/10;
            }

            if(prev1!=NULL){
                prev1->val +=carry;
            }

            curr1->val = main;

            ListNode *temp1 = curr1->next;
            ListNode *temp2 = curr2->next;

            prev1 = curr1;
            prev2 = curr2;
            curr1 = temp1;
            curr2 = temp2;
        }

        return l1;
    }
};