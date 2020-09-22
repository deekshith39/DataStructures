#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
}node;
node *head=NULL;
node *temp;
void create()
{
temp=(node *)malloc(sizeof(node));
}
void insertf(int n)
{
create();
temp->data=n;
temp->next=head;
head=temp;
}
int insertr(int x)
{
node *ptr;
create();
temp->data=x;
if(head==NULL)
{head=temp;
return 0;
}
else
{

ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=temp;
temp->next=NULL;

return 0;
}
}
int insertp(int z,int p)
{
int i;
node *ptr;
create();
temp->data=z;
if(head==NULL)
{
head=temp;
return 0;
}
else
{
if(p==1)
{
temp->next=head;
head=temp;
return 0;
}
else
{

for(i=1;i<p;i++)
{
ptr=ptr->next;
}
temp->next=ptr->next;
ptr->next=temp;

}
}
return 0;

}
void display()
{
node *ptr;
ptr=head;
while(ptr!=NULL)
{
printf("%d   ",ptr->data);
ptr=ptr->next;
}
}

void main()
{
int choice,pos,ele;
do
{
printf("1.insert at beginning\n");
printf("2.insert at end\n");
printf("3.insert at position\n");
printf("4.diplay\n");
printf("5.exit\n");
printf("enter the choice =\n ");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the element = ");
scanf("%d",&ele);
insertf(ele);
break;
case 2:printf("enter the element = ");
scanf("%d",&ele);
insertr(ele);
break;
case 3:printf("enter the element = ");
scanf("%d",&ele);
printf("enter the position = ");
scanf("%d",&pos);
insertp(ele,pos);
break;
case 4:display();
break;
case 5:exit(0);
break;
default:printf("wrong option");
}
}while(choice!=5);
}

