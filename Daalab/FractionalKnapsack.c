#include<stdio.h>
void main()
{
    float r[20];
    int w[20],p[20],temp;
    int i,j,n,cap,weight,profit=0,c;
    printf("Enter the number of items\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the weight and profit of the %d item\n",i+1);
        scanf("%d",&w[i]);
        scanf("%d",&p[i]);
        r[i]=(float)(p[i]/w[i]);
    }
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
        {
            if(r[j]<r[j+1])
            {
                temp=r[j];
                r[j]=r[j+1];
                r[j+1]=temp;
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                temp=w[j];
                w[j]=w[j+1];
                w[j+1]=temp;
            }
        }
    printf("Enter the capacity of the knapsack\n");
    scanf("%d",&cap);
    weight=0;
    i=0;
        for(i=0;i<n;i++)
        {
            if(weight+w[i]<=cap)
            {
                profit+=p[i];
                weight=weight+w[i];
            }
            else
                break;
        }
        printf("%d\n",weight);
    if(cap>weight)
    {
        c=cap-weight;
        profit+=c*r[i];
        weight+=c;
    }
    printf("The weight and profit of the knapsack is %d and %d\n",weight,profit);
}

