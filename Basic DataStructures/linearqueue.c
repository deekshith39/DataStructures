#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 50
int rear=-1;
int front=-1;
int que[MAX];
void insert();
void del();
void display();
void main()
{
int choice;
do
{
printf("1.insert\n2.delete\n3.display\n4.exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:insert();
break;
case 2:del();
break;
case 3:display();
break;
case 4:exit(0);
break;
default:printf("wrong option");
}
}while(choice!=4);
getch();
}
void insert()
{
int item;
if(rear==MAX)
printf("queue is full ");
else
{
if(front==-1)
front=0;
printf("enter the elment to be added = ");
scanf("%d",&item);
rear=rear+1;
que[rear]=item;
}
}
void del()
{
if(front==-1||front>rear)
printf("queue is empty ");
else
{
printf("%d",que[front]);
front=front+1;
}
}
void display()
{
int i;
if(front==-1)
{printf("empty\n");
}
else
{
for(i=front;i<=rear;i++)
{
printf("%d",que[i]);
printf("\n");
}
}
}
