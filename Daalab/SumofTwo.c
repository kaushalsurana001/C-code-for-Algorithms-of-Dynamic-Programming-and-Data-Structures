#include<stdio.h>
void main()
{
    int array[20],i,n,x,end,beg=0;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements of sorted array\n");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    printf("Enter the value of x\n");
    scanf("%d",&x);
    i=n-1;
    while(array[i]>x)
    {
        i--;
    }
    end=i;
    while(end>beg)
    {
        if(x==(array[end]+array[beg]))
        {
            printf("x = array[%d] + array[%d]\n",end,beg);
            break;
        }
        else if(x>(array[end]+array[beg]))
            beg++;
        else
            end--;
    }
    if(end<=beg)
        printf("No solution exist\n");

}
