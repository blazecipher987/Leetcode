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
    ListNode* reverseList(ListNode* head) {

        if(head==NULL){
            return {};
        }
        
        vector<int> ans = getElemens(head);

        reverse(ans.begin(), ans.end());

        int size = ans.size();
        ListNode *curr;
        ListNode *newHead;
        newHead = new ListNode(ans[0]);
        curr=newHead;
        for(int i=1; i<size; i++){
            ListNode *temp = new ListNode(ans[i], nullptr);
            newHead->next = temp;
            newHead = newHead->next;
        }

        return curr;
    }

    vector<int> getElemens(ListNode *head){

        

        ListNode *curr =head;
        vector<int> ans;

        while(curr !=NULL){
            ans.push_back(curr->val);
            curr = curr->next;
        }

        return ans;
    }
};