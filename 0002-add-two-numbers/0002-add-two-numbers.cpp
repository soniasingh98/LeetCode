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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*ans=new ListNode(0);
        ListNode*p=ans;
        int carry=0;
        while(l1 || l2 || carry){
            int num=0;
            if(l1){
                num+=l1->val;
                l1=l1->next;
            }
            if(l2){
                num+=l2->val;
                l2=l2->next;
            }
            num+=carry;
            p->next=new ListNode(num%10);
            p=p->next;
            carry=num/10;
        }
        return ans->next;
    }
};