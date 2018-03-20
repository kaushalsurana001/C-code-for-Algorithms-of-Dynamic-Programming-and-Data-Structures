#include<stdio.h>
int insert(int,int);
void display(int);
int dele(int);
void adjust(int ,int);
int heap[30];
void main()
{
int n=0,i,x,j,temp,del=0,a[30];
char ch;
do
{
    printf("enter choice\n1 Insert\n2 Compare\n");
    scanf("%d",&j);
    if(j==1)
    {
        if(n==29)
            printf("Overflow\n");
        else
        {
        printf("Enter the element to be inserted in the heap\n");
        scanf("%d",&x);
        n=insert(n+1,x);
        printf("the heap after insertion is\n");
        display(n);
        }
    }
    else if(j==2)
    {
        if(n==0)
            printf("Underflow\n");
        else
        {
        printf("Enter the no for the comparison \n");
        scanf("%d",&x);
        printf("Enter the k for the comparison with the kth max element \n");
        scanf("%d",&del);
        if(del>n)
        del=n;
        for(i=0;i<del;i++)
        {
            a[i]=dele(n);
            n=n-1;
        }
        //printf("the heap after all the deletion is\n");
        //display(n);
        if(a[del-1]<x)
            printf("The element X is greater than the %dth max element of the heap\n",del);
        else if(a[del-1]>x)
            printf("The element X is smaller than the %dth max element of the heap\n",del);
        else
            printf("The element X is equal to the %dth max element of the heap\n",del);
        }

    }
    else
        printf("\t\t\tWRONG CHOICE\n\n\n");
printf("Do you want to operate more on the heap .   PRESS Y/y\n");
fflush(stdin);
scanf("%c",&ch);
}while(ch=='y' || ch=='Y');
printf("The heap sort output is\n");
for (i=0;i<del;i++)
{
    printf("%d    ",a[i]);
}
}


int insert(int count,int val)
{
    int i;
    i=count;
    heap[i]=val;
    while(i>1 && heap[i/2]<val)
    {
        heap[i]=heap[i/2];
        i=i/2;
    }
    heap[i]=val;
    return count;
}

void display(int c)
{
    int i;
    if(c==0)
        printf("no element present");
    else{
    for(i=1;i<=c;i++){
        printf("%d   ",heap[i]);
    }
}
}

int dele(int n)
{
    int num=heap[1];
    heap[1]=heap[n];
    adjust(n-1,1);
    return num;
}

void adjust(int n, int i)
{
    int j,item,temp=0;
    j=2*i;
    item = heap[i];
    while(j!=temp && j<=n)
    {
        temp=j;
        if(heap[j]>heap[j+1]&&heap[j]>item)
        {
            heap[i]=heap[j];
            i=j;
        }
        else if(item<heap[j+1])
        {
            heap[i]=heap[j+1];
            i=j+1;
        }
        j=2*i;
    }
    heap[i]=item;
}

