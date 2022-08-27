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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newlist=NULL;
        ListNode* end=NULL;
        ListNode* p=head->next;
        int sum=0;
        while(p!=NULL){
            if(p->val==0){
                ListNode*a=new ListNode();
                a->val=sum;
                sum=0;
                a->next=NULL;
                if(newlist==NULL){
                    newlist=a;
                    end=a;
                }
                else{
                    end->next=a;
                    end=end->next;
                }
            }
            else{
                sum+=p->val;
            }
            p=p->next;
        }
        return newlist;
    }
};