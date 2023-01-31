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
        ListNode*ans=new ListNode(0),*p=ans;
        ListNode* a=list1,*b=list2;
        while(a && b){
            if(a->val<=b->val){
                p->next=a;
                p=p->next;
                a=a->next;
            }
            else{
                p->next=b;
                p=p->next;
                b=b->next;
            }
        }
        while(a){
            p->next=a;
            p=p->next;
            a=a->next;
        }
        while(b){
            p->next=b;
            p=p->next;
            b=b->next;
        }
        return ans->next;
    }
};