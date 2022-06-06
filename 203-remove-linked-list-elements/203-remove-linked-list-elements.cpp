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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return head;
        while(head!=NULL && head->val==val){
            ListNode*q=head;
            head=head->next;
            delete q;
        }
       if(head==NULL)return head;
        else{
            ListNode*p=head;
            ListNode*q=head->next;
            while(q!=NULL){
                if(q->val==val){
                    ListNode *r=q;
                    p->next=q->next;
                    q=q->next;
                    delete r;
                }
                else{
                    q=q->next;
                    p=p->next;
                }
            }
            return head;
        }
    }
};