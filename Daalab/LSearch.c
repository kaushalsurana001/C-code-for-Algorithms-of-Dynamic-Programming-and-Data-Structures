#include<stdio.h>
#include<stdlib.h>
int main()
{
   int *a,n,i,x;
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
   for(i=0;i<n;i++)
   {
       if(a[i]==x)
        break;
   }
   if(i==n)
    printf("Element not found\n");
   else
    printf("Element is found at %d",i+1);
}
