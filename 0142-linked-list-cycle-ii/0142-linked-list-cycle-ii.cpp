/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode*s=head,*f=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
            if(s==f)break;
        }
        if(!f || !f->next)return NULL;
        ListNode*d=head;
        while(d!=s){
            s=s->next;
            d=d->next;
        }
        return d;
    }
};