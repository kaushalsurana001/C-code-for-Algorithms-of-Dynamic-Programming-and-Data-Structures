#include<stdio.h>
int insert(int,int);
void display(int);
int dele(int);
void adjust(int ,int);
int heap[30];
void main()
{
int n=0,i,x,j,temp,del=0,n1,a[30];
char ch;
        printf("Enter the no elements of the array\n");
        scanf("%d",&n);
        n1=n;
        printf("Enter the element to be inserted in the array\n");
        for(i=0;i<n;i++)
        {
        scanf("%d",&x);
        insert(i+1,x);
        }
        printf("The array after insertion is\n");
        display(n);
        if(n==0)
        printf("No element present\n");
        for(i=0;i<n;i++)
        {
            a[i]=dele(n1);
            n1=n1-1;
        }
        //printf("the heap after all the deletion is\n");
        //display(n);
printf("The heap sort output is\n");
for (i=0;i<n;i++)
{
    printf("%d   ",a[i]);
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

