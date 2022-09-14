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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)return head;
        ListNode*p=head;
        vector<int>v;
        while(p!=NULL){
            v.push_back(p->val);
            p=p->next;
        }
        ListNode*n=new ListNode(v[v.size()-1]);
        ListNode*q=n;
        for(int i=v.size()-2;i>=0;i--){
            ListNode*t=new ListNode(v[i]);
            q->next=t;
            q=t;
        }
        return n;
    }
};