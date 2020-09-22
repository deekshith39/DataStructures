#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100
int top=-1;
char stck[MAX];
char infix[MAX];
char postfix[MAX];
char postfix[MAX];
void push(char k)
{
if(top==MAX)
printf("stack is full\n");
else
{
top=top+1;
stck[top]=k;
}
}

char pop()
{
char item;
if(top==-1)
{
printf("stack is empty");
getch();
exit(1);
}
else
{
item=stck[top];
top=top-1;
return item;
}
}
int prec(char x)
{
switch(x)
{
case '*':
case '/':return 3;
break;
case '+':
case '-':return 2;
break;
default:return 0;
}
}
int isoperator(char sym)
{
switch(sym)
{
case '+':
case '-':
case '*':
case '/':return 1;
break;
default:return 0;
}}
void evaluate(char infix [],char postfix [])
{    int x,i=0,k=0;
push('(');
strcat(infix,")");

while(infix[i]!='\0')
{
if(infix[i]=='(')
push(infix[i]);

else if(isdigit(infix[i])||isalpha(infix[i]))
{
postfix[k]=infix[i];
k++;
}
else if(isoperator(infix[i])==1)
{
x=pop();
while(isoperator(x)==1&&(prec(x)>=prec(infix[i])))
{
postfix[k]=x;
k++;
x=pop();
}
push(x);
push(infix[i]);
}
else if(infix[i]==')')
{
x=pop();
while(x!='(')
{
postfix[k]=x;
k++;
x=pop();
}}
else
{
printf("invalid expression");
getch();
exit(0);
}
i++;
}}
void main()
{
printf("enter the infix expression = \n");
gets(infix);

evaluate(infix,postfix);
printf("the postfix expression is = ");
puts(postfix);
getch();
}

