#include<stdio.h>
#include<stdlib.h>
int main()
{
   int *a,n,i,x,mid,beg=0,end;
   printf("Enter the no of elements of the array\n");
   scanf("%d",&n);
   end=n;
   a=(int *)malloc(n*sizeof(int));
   printf("Enter the elements of the array\n");
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   printf("Enter the element to be searched\n");
   scanf("%d",&x);
   mid=end/2;
   while(a[mid]!=x&&beg<=end)
   {
       if(a[mid]>x)
        end=mid-1;
       else
        beg=mid+1;
       mid=(beg+end)/2;
   }
   if(beg>end)
    printf("Element not found\n");
   else
    printf("Element is found at %d",mid+1);
}
