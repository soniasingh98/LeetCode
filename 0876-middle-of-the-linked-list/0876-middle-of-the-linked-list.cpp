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
    ListNode* middleNode(ListNode* head) {
        // if(head->next==NULL)return head;
        ListNode* s=head,*f=head;
        while(f!=NULL && f->next!=NULL){
            
                s=s->next;
                f=f->next->next;
            
        }
        return s;
    }
};