#include<stdio.h>
void main()
{
    int n,i,j,k=1,a;
    printf("Enter the no of persons in the party\n");
    scanf("%d",&n);
    i=1;
    j=2;
    while(k<n)
    {
        printf("Does %d knows %d\n",i,j);
        scanf("%d",&a);
        if(k!=n-1)
        {
        if(a)
        {
            i=(i>j?i:j)+1;
            j=j;
        }
        else
        {
            i=i;
            j=(i>j?i:j)+1;
        }
        }
        k++;
    }
    if(a)
        printf("Celebrity was %d",j);
    else
        printf("Celebrity was %d",i);
}
