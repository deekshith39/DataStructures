#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 2
void push(int);
void pop();
void print();

int top=-1;
int stck[MAX];
int main()
{
int choice,p;
clrscr();
do
{
printf("\n1.push\n2.pop\n3.print\n4.exit\n");
printf("enter the choice = ");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("enter the element to pushed = ");
scanf("%d",&p);
push(p);
break;
case 2:pop();
break;
case 3:print();
break;
case 4:exit(0);
break;
default:printf("wrong option");
}}while(choice!=4);
return 0;
}
void push(int z)
{
if(top==MAX)
printf("stack is full");
else
{top=top+1;
stck[top]=z;}
}
void pop()
{
 if(top==-1)
 printf("stack is empty");
 else
 {
 printf("poped element is %d",stck[top]);
 top=top-1;
  }}
void print()
{int i;
if(top==-1)
printf("the stack is empty");
for(i=top;i>=0;i--)
{
printf("%d",stck[i]);
}
}
