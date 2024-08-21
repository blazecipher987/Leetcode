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
    void reorderList(ListNode* head) {

        if(head==NULL){
            return ;
        }

        ListNode *curr = head;
        vector<int> ans;

        while(curr!=NULL){
            ans.push_back(curr->val);
            curr=curr->next;
        }

        
        int size = ans.size();
        vector<int> temp;

        if(size==1){
            return;
        }

        if(size%2==1){
            int lower =0;
            int higher = size-1;

            while(lower+1<higher){
                temp.push_back(ans[lower]);
                temp.push_back(ans[higher]);

                lower++;
                higher++;
            }
            temp.push_back(ans[lower+1]);
        }
        else{

            int lower =0;
            int higher = size-1;

            while(lower<higher){
                temp.push_back(ans[lower]);
                temp.push_back(ans[higher]);

                lower++;
                higher++;
            }

        }

        ListNode *head1 = new ListNode(temp[0]);
        ListNode *curr1 = head1;

        size = temp.size();
        for(int i=1;i<size; i++){
            ListNode *l = new ListNode(temp[i],nullptr);
            curr1->next = l;
            curr1 = curr1->next;
        }

        head = head1;

        
        
    }
};