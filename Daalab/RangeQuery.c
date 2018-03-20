#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data,slr,shr;
	struct node *left ,*right;
};
struct node * create(int,int);
void displayTree(struct node *);
void update(struct node *,int ,int);
int rangeQuery(struct node *, int, int);


void main()
{
	int n,x,i,ch,hr,lr,sum;
	char c;
	struct node *root;
	root=NULL;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	root=create(0,n-1);
	displayTree(root);
	do
    {
	printf("Enter your choice\n1 Update\n2 Range Query\n");
	scanf("%d",&ch);
	if(ch==1)
    {
        printf("Enter the value to be added\n");
        scanf("%d",&x);
        printf("Enter the index \n");
        scanf("%d",&i);
        //displayTree(root);
        if(i<n)
        {
            //printf("Before Update\n");
            update(root,x,i);
            //printf("After Update\n");
            displayTree(root);
        }
    }
    else if(ch==2)
    {
        printf("Enter the smaller index of the range\n");
        scanf("%d",&lr);
        printf("Enter the higher index of the range\n");
        scanf("%d",&hr);
        if(lr<=hr && hr<=root->shr && lr>=root->slr)
        {
            sum=rangeQuery(root,lr,hr);
            printf("Result of the range query is %d : ",sum);
        }
        else
            printf("\nWrong Range Entered\n");
    }
    else
        printf("\nWRONG CHOICE\n");
    printf("Do you want to operate more..... PRESS y/Y\n");
    fflush(stdin);
    scanf("%c",&c);
}while(c=='y'||c=='Y');

}

struct node *create(int start,int end)
{
    int mid;
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    if(end==start)
    {
        p->data=0;
        p->shr=end;
        p->slr=start;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    p->data=0;
    p->shr=end;
    p->slr=start;
    mid=(start+end)/2;
    p->left=create(start,mid);
    p->right=create(mid+1,end);
    return p;
}

int rangeQuery(struct node *ptr,int low,int high)
{
    if(ptr->shr<low || ptr->slr>high)
        return 0;
    else if(ptr->slr>=low && ptr->shr<=high)
        return ptr->data;
    else
        return rangeQuery(ptr->left,low,high) + rangeQuery(ptr->right,low,high);
}

void update(struct node *start,int x ,int index)
{
    int mid;
    struct node *temp;
    temp=start;

    while(temp!=NULL)
    {
        temp->data=(temp->data)+x;
        mid=(((temp->slr)+(temp->shr))/2);
        if(index>mid)
        {
            temp=temp->right;
        }
        else
        {
            temp=temp->left;
        }
    }
}

void displayTree(struct node *temp)
{
	if(temp==NULL)
        return;
	displayTree(temp->left);
    printf("%d  %d  %d  %d  %d\n",temp->data,temp->slr,temp->shr,temp->left,temp->right);
	displayTree(temp->right);
}
