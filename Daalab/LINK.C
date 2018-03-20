#include<stdio.h>
#include<stdlib.h>
void insert(int);
struct node
{
int data;
struct node *next;
}*start;
struct node *newnode,*ptr,*temp;
int main()
{
int a,pos;
char ch;
start=NULL;
do
{
printf("Enter the data of the node\n");
scanf("%d",&a);
newnode =(struct node*)malloc(sizeof(struct node));
newnode->data=a;
newnode->next=NULL;
printf("Enter the position of the node\n");
scanf("%d",&pos);
insert(pos);
printf("\n\n\t\t\t\t\t\tNode Inserted\nDo you want to enter more.   Press Y\n");
fflush(stdin);
scanf("%c",&ch);
}while(ch=='y'||ch=='Y');
printf("The final link list is \n");
ptr=start;
while(ptr!=NULL)
{
    printf("%d     ",ptr->data);
    ptr=ptr->next;
}
}

void insert(int pos)
{
int count=0,i;
ptr=start;
if(start==NULL)
{
start=newnode;
newnode->next=NULL;
}
else
{
while(ptr!=NULL)
{
ptr=ptr->next;
count++;
}
if(pos>count){
ptr=newnode;
ptr->next=NULL;
}
else if(pos<=1)
{
    newnode->next=start;
    start=newnode;
}
else
{
    i=1;
    ptr=start;
    while(i<pos)
    {
        ptr=ptr->next;
    }
    temp=ptr;
    ptr=newnode;
    newnode->next=temp;
}
}
}

