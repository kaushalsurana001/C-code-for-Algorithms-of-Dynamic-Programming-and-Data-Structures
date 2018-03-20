#include<stdio.h>
int Stack1[20],Stack2[20],top1=-1,top2=-1;
void pops1();
void main()
{
    int i,n;
    char ch;
    do
    {
        printf("Enter your choice\n1 Enqueue\n2 Dequeue\n");
        scanf("%d",&i);
        if(i==1)
        {
            if(top1==19)
                printf("Overflow\n");
            else
            {
                top1++;
                printf("Enter the number to be entered\n");
                scanf("%d",&Stack1[top1]);
            }
        }
        else if(i==2)
        {
            if(top2==-1 && top1 == -1)
                printf("Underflow\n");
            else
            {
                if(top2==-1)
                    pops1();
                n=Stack2[top2];
                top2--;
                printf("the popped element is : %d\n",n);
            }
        }
        else
            printf("Wrong Choice\n");
        printf("Do you want to operate more\n......Press Y/y........\n");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    printf("The Queue at last is\n");
    for(i=top2;i>=0;i--)
        printf("%d    ",Stack2[i]);
    for(i=0;i<=top1;i++)
        printf("%d    ",Stack1[i]);
}

void pops1()
{
    int i;
    for(i=top1;i>=0;i--)
    {
        top2++;
        Stack2[top2]=Stack1[i];
        top1--;
    }
}
