#include <bits/stdc++.h>
using namespace std;
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if(list1 == NULL && list2 == NULL){
            return {};
        }

        vector<int> ans;

        while (list1 != NULL && list2 != NULL)
        {

            if (list1->val < list2->val)
            {
                ans.push_back(list1->val);
                list1 = list1->next;
            }
            else
            {
                ans.push_back(list2->val);
                list2 = list2->next;
            }
        }

        if (list1 == NULL && list2 != NULL)
        {

            while (list2 != NULL)
            {
                ans.push_back(list2->val);
                list2 = list2->next;
            }
        }

        if (list1 != NULL && list2 == NULL)
        {
            while (list1 != NULL)
            {
                ans.push_back(list1->val);
                list1 = list1->next;
            }
        }

        ListNode *head = new ListNode(ans[0]);
        ListNode *curr = head;

        int size = ans.size();
        for (int i = 1; i < size; i++)
        {

            ListNode *temp = new ListNode(ans[i], nullptr);
            curr->next = temp;
            curr = curr->next;
        }

        return head;
    }
};