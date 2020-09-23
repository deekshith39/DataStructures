#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* npx;
};
Node* head=NULL;
Node* XOR(Node* a,Node* b)
{
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));  
}

void insertB(int data)
{
    Node* temp = new Node();
    temp->data = data;

    temp->npx = XOR(NULL,head);

    if(head==NULL) head=temp;
    else
    {
        head->npx = XOR(temp,head->npx);
        head=temp;
    }
    
}

void insertE(int data)
{
    Node* temp = new Node();
    temp->data = data;

    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    while(curr!=NULL)
    {
        next = XOR(prev,curr->npx);
        prev=curr;
        curr=next;
    }

    prev->npx = XOR(prev->npx,temp);
    temp->npx = XOR(prev,NULL);
}

void print()
{
    Node* curr=head;
    Node* next;
    Node* prev=NULL;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";

        next = XOR(prev,curr->npx);
        prev = curr;
        curr = next;
    }
    //prev->npx = XOR(prev->npx,temp);
}

int main()
{
    head=NULL;
    //insertion at the begining
    insertB(3);
    insertB(2);
    insertB(1);
    //insertion at the end
    insertE(4);
    insertE(5);
    insertE(6);

    cout<<"the output is "<<endl;


    print();

    return 0;
}

