/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node*p=head,*temp;
        while(p){
            temp=p->next;
            p->next=new Node(p->val);
            p->next->next=temp;
            p=temp;
        }
        p=head;
        while(p){
            p->next->random=(p->random==NULL)?NULL:p->random->next;
            p=p->next->next;
        }
        Node*dup=new Node(0);
        Node*org=head,*copy=dup;
          while(org){
          dup->next=org->next;
          org->next=org->next->next;
          org=org->next;
          dup=dup->next;
      }
      return copy->next;
    }
};