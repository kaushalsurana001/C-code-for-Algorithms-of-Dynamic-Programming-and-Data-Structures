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
void merge(struct node *,struct node *);
struct node* dele(struct node*,int);
struct node* mergeInLeft(struct node*,struct node*,int );
struct node* mergeInRight(struct node*,struct node*,int );

void main()
{
	int n,i,ch,value;
	char c;
	struct node *groot,*sroot,*q,*temp;
	groot=NULL;
	sroot=NULL;
	for(i=1;i<3;i++)
    {
    if(i==1)
        printf("Enter the value of the greater tree\n");
    else
        printf("Enter the value of the smaller tree\n");
	do
    {
        printf("Enter the value to be inserted\n");
        scanf("%d",&n);
        if(i==1)
        {
            groot = insert(groot,n);
        }
        else
        {
            if(n<value)
            sroot = insert(sroot,n);
            else
            printf("Entered value is greater than the value of greater tree\n");
        }
        if(i==1)
        printf("Do you want to insert more on the greater tree\nPress Y/y");
        else
        printf("Do you want to insert more on the smaller tree\nPress Y/y");
        fflush(stdin);
        scanf("%c",&c);
    }while(c=='y'||c=='Y');
    if(i==1)
    {
        q=groot;
        while(q->left!=NULL)
            q=q->left;
        value=q->data;
    printf("The tree after insertion in greater tree is\n");
    displayTree(groot);
    }
    else
    {
        printf("The tree after insertion in smaller tree is\n");
        displayTree(sroot);
    }

}
merge(sroot,groot);
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

struct node * dele(struct node *sroot,int x)
{
    struct node *p;
    if(sroot==NULL)
        return NULL;
    else if(x > sroot->data)
    {
        sroot->right=dele(sroot->right,x);
        if(balfactor(sroot)==2)
            if(balfactor(sroot->left)>=0)
                sroot=l_rotate(sroot);
            else
                sroot=lr_rotate(sroot);
    }
    else if(x < sroot->data)
    {
        sroot->left=dele(sroot->left,x);
        if(balfactor(sroot)==-2)
            if(balfactor(sroot->right)<=0)
                sroot=r_rotate(sroot);
            else
                sroot=rl_rotate(sroot);
    }
    else
    {
        if(sroot->right!=NULL)
        {
            p=sroot->right;
            while(p->left!=NULL)
                p=p->left;
            sroot->data=p->data;
            sroot->right=dele(sroot->right,p->data);
            if(balfactor(sroot)==2)
                if(balfactor(sroot->left)>=0)
                    sroot=l_rotate(sroot);
                else
                    sroot=lr_rotate(sroot);
        }
    else
        return(sroot->left);
    }
    sroot->height=getheight(sroot);
    return sroot;
}

void merge(struct node *sroot,struct node *groot)
{
    struct node *temp1,*temp2;
    int n,b;
    temp1=sroot;
    temp2=groot;
    if(temp1->height<temp2->height)
    {
    while(temp1->right!=NULL)
        temp1 = temp1->right;
    n=temp1->data;
    sroot = dele(sroot,n);
    //displayTree(sroot);
    groot = mergeInLeft(sroot,groot,n);
    printf("The tree after merging is \n");
    displayTree(groot);
    }
    else
    {
        while(temp2->left!=NULL)
        temp2 = temp2->left;
    n=temp2->data;
    groot = dele(groot,n);
    sroot = mergeInRight(groot,sroot,n);
    printf("The tree after merging is \n");
    displayTree(sroot);
    }
}

struct node * mergeInLeft(struct node *s,struct node *g,int num)
{
    struct node *temp,*p;
    int b;
    temp=g;
    while(temp->left->height>s->height)
    {
        temp=temp->left;
    }
        p=(struct node *)malloc(sizeof(struct node));
        p->data=num;
        p->right=temp->left;
        p->left=s;
        p->height=getheight(p);
        temp->left=p;
        temp->height=getheight(temp);
        b=balfactor(temp);
        if(b==2)
            r_rotate(temp);
        return g;
}

struct node * mergeInRight(struct node *g,struct node *s,int num)
{
    struct node *temp,*p;
    int b;
    temp=s;
    while(temp->right->height>g->height)
    {
        temp=temp->right;
    }
        p=(struct node *)malloc(sizeof(struct node));
        p->data=num;
        p->left=temp->right;
        p->right=g;
        p->height=getheight(p);
        temp->right=p;
        temp->height=getheight(temp);
        b=balfactor(temp);
        if(b==-2)
            l_rotate(temp);
        return s;
}
