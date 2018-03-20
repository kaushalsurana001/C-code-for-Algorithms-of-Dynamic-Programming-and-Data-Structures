#include<stdio.h>
void tower(int, char, char, char );
void main()
{
    int n;
    char beg = 'A',aux = 'B',end = 'C';
    printf("Enter the no of disks\n");
    scanf("%d",&n);
    tower(n,beg,aux,end);
}

void tower(int n,char beg,char aux,char end)
{
    if(n==0)
        return;
    else
    {
        tower(n-1,beg,end,aux);
        printf("Shift disk from %c to %c\n",beg,end);
        tower(n-1,aux,beg,end);
    }
}
