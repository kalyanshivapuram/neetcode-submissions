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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* p= slow->next;
        ListNode* q = nullptr;
        ListNode* r = nullptr;
        //cut the list at the 1st half
        slow->next = nullptr;
        //reverse the 2nd half
        while(p!=nullptr){
            r=q;
            q=p;
            p=p->next;
            q->next =r;
        }
        ListNode* first = head;
        ListNode* second = q;//head of the reversed list
        //merge the two halves altenatively
        while(second!=nullptr){
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;
            first->next = second;
            second->next = t1;
            first = t1;
            second = t2;
        }


        
    }
};
