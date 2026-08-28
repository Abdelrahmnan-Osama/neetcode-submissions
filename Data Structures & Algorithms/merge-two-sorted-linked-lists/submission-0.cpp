/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1, *l2 = list2, *dummy = new ListNode(), *itr = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                itr->next = l1;
                itr = itr->next;
                l1 = l1->next;
            } else {
                itr->next = l2;
                itr = itr->next;
                l2 = l2->next;
            }
        }
        if(l1)
            itr->next = l1;
        else if(l2)
            itr->next = l2;

        return dummy->next;
    }
};
