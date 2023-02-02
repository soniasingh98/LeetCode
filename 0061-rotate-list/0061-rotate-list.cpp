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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;
        int size=0;
        ListNode*p=head;
        
        while(p->next){
            p=p->next;
            size++;
        }
        size++;
        k=k%size;
        if(k==0)return head;
        p->next=head;
        
        p=head;
        for(int i=1;i<size-k;i++){
            p=p->next;
        }
        ListNode*q=p->next;
        p->next=NULL;
            return q;
    }
};