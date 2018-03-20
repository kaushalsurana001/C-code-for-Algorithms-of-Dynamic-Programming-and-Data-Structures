#include<stdio.h>
#include<stdlib.h>
int LSearch(int *,int ,int);
int main()
{
   int *a,n,i,x,pos;
   printf("Enter the no of elements of the array\n");
   scanf("%d",&n);
   a=(int *)malloc(n*sizeof(int));
   printf("Enter the elements of the array\n");
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   printf("Enter the element to be searched\n");
   scanf("%d",&x);
   pos=LSearch(a,n-1,x);
   if(pos==-1)
    printf("Element not found\n");
   else
    printf("Element found at %d\n",pos+1);
}

int LSearch(int *b,int n,int x)
{
    if(n==-1)
        return -1;
    else if(b[n]==x)
        return n;
    else
        return LSearch(b,n-1,x);
}
