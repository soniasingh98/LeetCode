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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=1;
        ListNode* p=head;
        while(p->next!=NULL){
            p=p->next;
            size++;
        }
        if(size==n){
            ListNode*a=head;
            head=head->next;
            delete(a);
            return head;
        }
        else{
            int i=1;
            ListNode*q=head;
            while(i<size-n){
                q=q->next;
                i++;
            }
            ListNode*b=q->next;
            q->next=b->next;
            delete(b);
            return head;
        }
    }
};