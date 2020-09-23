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

void deleteB()
{
    if(head==NULL) cout<<"list is empty "<<endl;
    else if(head->npx==NULL) head=NULL;
    else
    {
        Node* temp = head->npx;
        temp->npx = XOR(head,temp->npx);
        free(head);
        head=temp;
    }
    
}
void deleteE()
{
    if(head==NULL) cout<<"list is empty"<<endl;
    else if(head->npx==NULL) head=NULL;
    else
    {
        Node* prev=NULL;
        Node* next;
        Node* curr=head;
        while(curr!=NULL)
        {
           // cout<<curr->data<<" ";
            next=XOR(prev,curr->npx);
            prev=curr;
            curr=next;
        }
        Node* temp = prev->npx;
        temp->npx = XOR(temp->npx,prev);
        free(prev);
        //cout<<"last pointer element is "<<curr->data;
        
    }
    
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

    if(head==NULL)
    {
        head=temp;
        temp->npx = XOR(NULL,NULL);
    }
    else{
        while(curr!=NULL)
        {
            next = XOR(prev,curr->npx);
            prev=curr;
            curr=next;
        }

        prev->npx = XOR(prev->npx,temp);
        temp->npx = XOR(prev,NULL);
    }
    
}

void print()
{
    if(head==NULL) cout<<"empty!"<<endl;
    else
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
        cout<<endl;
    }
    //prev->npx = XOR(prev->npx,temp);
}

int main()
{
    head=NULL;
    int choice;
    cout<<"enter choice : "<<endl;
    cout<<"1. INSERT AT THE BEGINING \n2. INSERT AT THE END "<<endl;
    cin>>choice;
    cout<<"enter the number of nodes: "<<endl;
    int n;
    cin>>n;
    cout<<"enter the values : "<<endl;
    while(n--)
    {
        int ele;
        cin>>ele;
        if(choice==1) insertB(ele);
        else insertE(ele);
    }    
   
    cout<<"the output is "<<endl;
    print();

    cout<<"after deleting element at front : "<<endl;
    deleteB();
    print();
    cout<<"after deleting element at the end : "<<endl;
    deleteE();
    print();

    return 0;
}

