#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 3
int cque[MAX];
int front=-1,rear=-1;
void enqueue(int);
void dequeue();
void display();
void main()
{
int choice,ele;
clrscr();
do
{
printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
printf("enter the choice = \n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the element =\n");
      scanf("%d",&ele);
      enqueue(ele);
      break;
case 2:dequeue();
break;
case 3:display();
break;
case 4:exit(0);
default:printf("invalid option\n");
}
}while(choice!=4);
}
void enqueue(int x)
{
if(front==((rear+1)%MAX))
printf("queue is full\n");
else
{
if(front==-1)
front=rear=0;
else
rear=(rear+1)%MAX;
cque[rear]=x;

}
}
void dequeue()
{
if(front==-1)
printf("queue is empty\n");
else
{
if(rear==front)
{
rear=-1;
front=-1;
}
else
{
printf("deleted elment = %d\n",cque[front]);
front=(front+1)%MAX;
}
}
}
void display()
{
int i;
for(i=front;i!=rear;i=(i+1)%MAX)
{
printf("%d\n ",cque[i]);
}
printf("%d\n",cque[i]);
}
