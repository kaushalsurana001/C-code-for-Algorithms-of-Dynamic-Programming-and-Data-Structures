#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data,height;
	struct node *left ,*right;
};

int getheight(struct node *);
int balfactor(struct node *);
struct node* insert(struct node *, int);
void displayTree(struct node *);
struct node* r_rotate(struct node *);
struct node* lr_rotate(struct node *);
struct node* l_rotate(struct node *);
struct node* rl_rotate(struct node *);
int findAncestor(struct node*, int, int);

void main()
{
	int n,u,v,value;
	char c;
	struct node *root;
	root=NULL;
	do
    {
        printf("Enter the value to be inserted\n");
        scanf("%d",&n);
        root = insert(root,n);
        printf("Do you want to insert more on the greater tree\nPress Y/y");
        fflush(stdin);
        scanf("%c",&c);
    }while(c=='y'||c=='Y');
    displayTree(root);
    printf("Enter u and v for finding their common ancestor\n");
    printf("u = ");
    scanf("%d",&u);
    printf("v = ");
    scanf("%d",&v);
    if(v==root->data || u==root->data)
         printf("One of them is root\n");
    else
    {
        value=findAncestor(root,u,v);
        printf("The common ancestor = %d ",value);
    }
}

int findAncestor(struct node* start, int u, int v)
{
    if(v>start->data&&u<start->data)
        return start->data;
    else if(v>start->data)
        return findAncestor(start->right,u,v);
    else
        return findAncestor(start->left,u,v);
}

struct node* insert(struct node *p,int k)
{
    int b;
    if(p==NULL)
    {
    p=(struct node *)malloc(sizeof(struct node));
    p->data=k;
    p->height=1;
    p->right=NULL;
    p->left=NULL;
    }
    else if(k>(p->data))
    {
    p->right = insert(p->right,k);
    }
    else if(k<(p->data))
    {
        p->left = insert(p->left,k);
    }
    p->height = getheight(p);
    b=balfactor(p);
    if(b>1 && (k<p->left->data))
        p = r_rotate(p);
    else if(b>1 && k>p->left->data)
        p = lr_rotate(p);
    else if(b<-1 && k>p->right->data)
        p = l_rotate(p);
    else if(b<-1 && k<p->right->data)
        p = rl_rotate(p);
    return p;
}

int getheight(struct node *p)
{
    int lh,rh;
    if(p==NULL)
        return 0;
    if(p->left==NULL)
        lh=1;
    else
        lh = 1 + (p->left->height);

    if(p->right==NULL)
        rh=1;
    else
        rh=1 + (p->right->height);
    if(lh>rh)
        return lh;
    else
        return rh;
}

int balfactor(struct node *p)
{
    int lh,rh;
    lh=getheight(p->left);
    rh=getheight(p->right);
    return (lh - rh);
}

struct node* r_rotate(struct node *p)
{
    struct node *temp;
    temp = p->left;
    p->left=temp->right;
    temp->right=p;
    p->height=getheight(p);
    temp->height=getheight(temp);
    return temp;
}

struct node* l_rotate(struct node *p)
{
    struct node *temp;
    temp = p->right;
    p->right=temp->left;
    temp->left=p;
    p->height=getheight(p);
    temp->height=getheight(temp);
    return temp;
}

struct node* lr_rotate(struct node *p)
{
    p->left=l_rotate(p->left);
    p=r_rotate(p);
    return p;
}

struct node* rl_rotate(struct node *p)
{
    p->right=r_rotate(p->right);
    p=l_rotate(p);
    return p;
}

void displayTree(struct node *temp)
{
	if(temp==NULL)
        return;
	displayTree(temp->left);
    printf("%d   %d\n",temp->data,temp->height);
	displayTree(temp->right);
}
