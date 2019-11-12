
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int data;
struct node *next;
}node;
node *head=NULL;
node *temp;

void create(int x)
{
temp=(node *)malloc(sizeof(node));
temp->data=x;
}
void push(int);
void pop();
void display();
void main()
{
int ele;
int choice;
do
{
printf("1.push\n2.pop\n3.display\n4.exit");

printf("enter the choice  = ");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the element = ");
scanf("%d",&ele);
push(ele);
break;
case 2:pop();
break;
case 3:display();
break;
case 4:exit(0);
break;
default:printf("invalid");

}
}while(choice!=4);
}


void push(int p)
{
create(p);
if(head==NULL)
head=temp;
else
{
temp->next=head;
head=temp;
}
}
void pop()
{
node *ptr;
ptr=head;
if(head==NULL)
printf("empty");

else
{
head=head->next;
free(ptr);
}
}
void display()
{
int i;
node *ptr;
ptr=head;
if(head==NULL)
{
printf("list is empty");
}
for(i=0;ptr!=NULL;i++)
{
printf("\n%d",ptr->data);
ptr=ptr->next;
}
}
