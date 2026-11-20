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
        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* p = list1;
        ListNode* q = list2;
        while(p!=nullptr && q!=nullptr){
            if(p->val<=q->val){
                tail->next = p;
                p = p->next;
            }
            else{
                tail->next = q;
                q = q->next;
            }
            tail= tail->next;
        }
        tail->next = (p!=nullptr)? p : q;
        return dummy.next;
    }
};
