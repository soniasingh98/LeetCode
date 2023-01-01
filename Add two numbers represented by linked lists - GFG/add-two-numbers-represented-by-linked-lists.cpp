//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
   struct Node* reverse(Node* head){
        Node* prev=NULL;
        Node* cur=head,*temp=head;
        while(cur){
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* f, struct Node* s)
    {
        // code here
        struct Node* first=reverse(f);
        struct Node* second=reverse(s);
        int carry=0;
        Node* ans=new Node(0);
        Node* head=ans;
        while(first && second){
            int num=first->data+second->data+carry;
            ans->next=new Node(num%10);
            ans=ans->next;
            first=first->next;
            second=second->next;
            carry=num/10;
        }
        while(first){
            int num=first->data+carry;
            ans->next=new Node(num%10);
            ans=ans->next;
            first=first->next;
            carry=num/10;
        }
        while(second){
            int num=second->data+carry;
            ans->next=new Node(num%10);
            ans=ans->next;
            second=second->next;
            carry=num/10;
        }
        if(carry==1){
            ans->next=new Node(carry);
            ans=ans->next;
        }
        head=reverse(head->next);
        return head;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends