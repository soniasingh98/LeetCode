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
    ListNode* rev(ListNode*head){
        ListNode*prev=NULL,*cur=head,*temp=head;
        while(cur){
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next)return true;
        ListNode*s=head,*f=head->next;
        while(f && f->next){
           s=s->next;
           f=f->next->next;
        }
        s->next=rev(s->next);
        s=s->next;
        ListNode*d=head;
        while(s){
            if(d->val!=s->val)return false;
            d=d->next;
            s=s->next;
        }
        return true;
    }
};