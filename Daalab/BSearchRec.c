#include<stdio.h>
#include<stdlib.h>
int BSearch(int *,int ,int, int);
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
   pos=BSearch(a,n-1,0,x);
   if(pos==-1)
    printf("Element not found\n");
   else
    printf("Element found at %d\n",pos+1);
}

int BSearch(int* b,int end,int beg, int x)
{
    int mid;
    mid=(beg+end)/2;
    if(beg>end)
        return -1;
    else if(b[mid]==x)
        return mid;
    else if(b[mid]>x)
        return BSearch(b,mid-1,beg,x);
    else
        return BSearch(b,end,mid+1,x);
}
