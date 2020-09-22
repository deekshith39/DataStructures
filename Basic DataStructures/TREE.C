
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct node
{
int data;
struct node *lchild;
struct node *rchild;
}node;
node *temp;
void create(int item)
{
temp=(node *)malloc(sizeof(node));
temp->data=item;
temp->lchild=NULL;
temp->rchild=NULL;
}
void insert(node *root,node *temp)
{
if((temp->data)<(root->data))
  {
  if((root->lchild)==NULL)
  root->lchild=temp;
  else
  insert(root->lchild,temp);
  }
if((temp->data)>=(root->data))
{
  if((root->rchild)==NULL)
  root->rchild=temp;
  else
  insert(root->rchild,temp);
}
}
void preorder(node *root)
{
if(root!=NULL)
{
printf("\n%d",root->data);
preorder(root->lchild);
preorder(root->rchild);
}
}
void inorder(node *root)
{
if(root!=NULL)
{
inorder(root->lchild);
printf("\n%d",root->data);
inorder(root->rchild);
}
}
void postorder(node *root)
{
if(root!=NULL)
{
postorder(root->lchild);
postorder(root->rchild);
printf("\n%d",root->data);
}
}
void maxi(node *root)
{
if((root->rchild)==NULL)
{
printf("maximum = %d",root->data);
}
else
maxi(root->rchild);
}
int search(node *root,int data)
{
if(root==NULL)
{
printf("not found");
getch();
return;
}
if((root->data)==data)
{
printf("element found");
getch();
return;
}
else if((root->data)<data)
search(root->rchild,data);
else
search(root->lchild,data);

return;
}


void main()
{
int choice,ele;


node *root=NULL;
clrscr();
do
{
printf("\n1.insert\n2.preorder\n3.inorder\n4.postorder\n5.exit\n6.max\n7.search\n");

printf("enter the choice = \n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("\nenter the element = ");
scanf("%d",&ele);
create(ele);
if(root==NULL)
root=temp;
else
insert(root,temp);
break;
case 2:preorder(root);
break;
case 3:inorder(root);
break;
case 4:postorder(root);
break;
case 5:exit(0);
break;
case 6:maxi(root);
break;
case 7:printf("eneter the value to be searched = ");
scanf("%d",&ele);
search(root,ele);
    break;
default:printf("invalid");
}
}while(choice!=5);
}
