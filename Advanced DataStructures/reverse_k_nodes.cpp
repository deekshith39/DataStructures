#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstring>
using namespace std;

class node
{
    public:
    int data;
    node* next;
};
class list1:public node {
    public:
    node* head;
    node* temp;
    public:
    list1()
    {
        head=NULL;
    }
    //void create();
    void insert(int ele);
    void k_reverse(int k);
    void display(node* head);
    
};
void list1::display(node* head)
{
    node* ptr;
    ptr=head;
    if(head==NULL)
    {
        cout<<"linked list is empty"<<endl;
    }
    else
    {
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    }
    cout<<endl;
}

void list1::insert(int ele)
{
    temp = new node();
    temp->data = ele;
    temp->next=NULL;
    if(head==NULL)
    head=temp;
    else
    {
    node* ptr;
    ptr=head;
    while(ptr->next!=NULL)
    ptr=ptr->next;
    ptr->next=temp;
    }
}
void list1::k_reverse(int k)
{
    int i=0;
    node* curr=head;
    node* last=head;
    node* prev;
    node* precurr=head;
    node* next;
    while(last!=NULL&&i<k)
    { last = last->next; i++;}
    prev=last;
    while(curr!=last)
    {
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr=next;       
    }
    head=prev;
    while(curr!=NULL)
    {
        i=0;
        node * t=curr;
        while(last!=NULL&&i<k)
        {last = last->next;i++;}
        prev = last;
        while(curr!=last)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        precurr->next=prev;
        precurr=t;
    }
    display(head);
}
int main()
{
    list1 l;
    int k;
    cout<<"enter the k value: "<<endl;
    cin>>k;
    cout<<"enter the number of nodes : "<<endl;
    int n;
    cin>>n;
    cout<<"enter the nodes : "<<endl;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        l.insert(ele);
    }
    cout<<"output"<<endl;
    l.k_reverse(k);

    return 0;


}