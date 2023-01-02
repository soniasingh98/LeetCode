//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}

// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/
Node* reverse(Node* head){
    Node* prev=NULL,*cur=head,*temp=head;
    while(cur){
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    return prev;
}
Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_map<int,int>m;
    Node*p=head1;
    while(p){
        m[p->data]++;
        p=p->next;
    }
    vector<int>s;
    Node*q=head2;
    while(q){
        if(m.find(q->data)!=m.end()){
            s.push_back(q->data);
           m[q->data]--;
           if(m[q->data]==0)m.erase(q->data);
        }
         q=q->next;
    }
 
    Node* head=NULL;
    for(auto it:s){
        Node* r=new Node(it);
        r->next=head;
        head=r;
    }
    head=reverse(head);
    return head;
}