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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
       ListNode*first=NULL,*second=head,*third=head->next;
        head=head->next;
       while(third!=NULL ){
           if(first==NULL){
           second->next=third->next;
           third->next=second;
           ListNode*p=third;
           third=second;
           second=p;
               if(third->next!=NULL){
            first=third;
          second=second->next->next;
           third=third->next->next;
               }
               else{
                   third=third->next;
               }
           }
           else{
           
           second->next=third->next;
           third->next=second;
            first->next=third;
           ListNode*p=third;
           third=second;
           second=p;
           if(third->next!=NULL){
            first=first->next->next;
          second=second->next->next;
           third=third->next->next;
               }
               else{
                   third=third->next;
               }
           }
       }
        return head;
    }
};