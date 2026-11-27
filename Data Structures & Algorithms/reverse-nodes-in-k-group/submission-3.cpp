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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // check k nodes exists
        //reverse exactly k nodes
        //connect the reversed group to the remaining list
        if(head==nullptr||k==1){
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while(true){
            ListNode* kth = groupPrev;
            for(int i =0;i<k && kth!=nullptr;i++){
                kth = kth->next;
            }
            if(kth==nullptr){
                break;
            }
            ListNode* groupNext = kth->next;

            //reverse
            ListNode* p = groupPrev->next;
            ListNode* q = groupNext;
            ListNode* r = nullptr;
            ListNode* oldhead = p;
            for(int i=0;i<k;i++){
                r=q;
                q=p;
                p=p->next;
                q->next =r;
            }
            groupPrev->next = q;
            groupPrev = oldhead;
        }
        return dummy.next;



        }
};
