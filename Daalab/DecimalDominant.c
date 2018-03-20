#include<stdio.h>
void main()
{
    int num,array[60],count[10]={0,0,0,0,0,0,0,0,0,0},dec_dom[10],i,c,j,n;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements in the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);
    dec_dom[0]=array[0];
    count[0]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<10,j<=i;j++)
        {
            if(dec_dom[j]==array[i])
            {
                count[j]++;
                break;
            }
            else if(i%10==0)
                count[j]--;
            if(count[j]==0&&num!=dec_dom[j])
            {
                dec_dom[j]=array[i];
                count[j]=1;
                break;
            }
        }
    }
    /*printf("The decimal dominant array is\n");
    for(j=0;j<10;j++)
         printf("%d   ",dec_dom[j]);
    printf("The decimal dominant array is\n");
    */
    for(j=0;j<10;j++)
    {
        c=0;
        for(i=0;i<n;i++)
        {
            if(dec_dom[j]==array[i])
            c++;
        }
        if(c>=((n/10)+((n%10>0)?1:0))))
        printf("%d   ",dec_dom[j]);
    }
}
