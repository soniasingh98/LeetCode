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
        if(list1==NULL)return list2;
        else if(list2==NULL)return list1;
        else{
          
          ListNode*head=NULL,*move;
            while(list1!=NULL && list2!=NULL){
            if(list1->val >= list2->val){
                ListNode*q=new ListNode();
                q->val=list2->val;
                q->next=NULL;
                if(head==NULL){
                    head=q;
                    move=q;
                }
                else{
                    move->next=q;
                    move=q;
                }
                list2=list2->next;
            }
             else if(list1->val < list2->val){
                ListNode*q=new ListNode();
                q->val=list1->val;
                q->next=NULL;
                if(head==NULL){
                    head=q;
                    move=q;
                }
                else{
                    move->next=q;
                    move=q;
                }
                 list1=list1->next;
            }
            }
            if(list1==NULL){
                while(list2!=NULL){
                    ListNode*q=new ListNode();
                    q->val=list2->val;
                    move->next=q;
                    move=q;
                    list2=list2->next;
                }
            }
            else{
                while(list1!=NULL){
                    ListNode*q=new ListNode();
                    q->val=list1->val;
                    move->next=q;
                    move=q;
                    list1=list1->next;
                }
            }
            return head;
        }
    }
};