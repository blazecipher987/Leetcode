#include <bits/stdc++.h>
using namespace std;
#include <vector>



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
        
            if(list1==NULL && list2==NULL){
                return {};
            }

            if(list1->val < list2->val){
                return solveFunc(list1, list2);
            }

            return solveFunc(list2, list1);
    }

    ListNode* solveFunc(ListNode *lesser, ListNode *greater){

        ListNode *h1 = lesser;
        ListNode *h2 = greater;

        if(h1->next==NULL){
            h1->next = h2;
            return h1;
        }

        ListNode *comp = h1->next;

        while(comp!=NULL && h2!=NULL){

            int v1 = h1->val;
            int v2 = h2->val;
            int vComp = comp->val;

            if(v2>=v1 && v2<vComp){
                ListNode *temp = comp;
                ListNode *temp2 = h2->next;
                h1->next = h2;
                h2->next = comp;
                h1 =h2;
                h2 = temp2;
            }

            if(v2>=v1 && v2>vComp){
                ListNode *temp = comp->next;
                h1 = comp;
                comp = temp;
            }

            if(v1>v2){
                ListNode *temp = h2;
                ListNode *temp1 = h2->next;
                h2 = h1;
                h1 = temp;
                comp = temp1;
            }
        }

        if(comp==NULL){
            h1->next = h2;
        }

        return lesser;

    }
};