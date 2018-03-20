#include<stdio.h>
void primMST(int g[20][20],int);
void printMST(int [],int ,int [20][20]);
int minKey(int [], int [],int);
void main()
{
    int graph[20][20],n,i,j;
    printf("Enter the number of vertices \n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
            for(j=i;j<n;j++)
            {
                if(i==j)
                    graph[i][j]=0;
                else
                {
                    printf("Enter the cost from %d to %d : ",i,j);
                    scanf("%d",&graph[i][j]);
                    graph[j][i]=graph[i][j];
                }
            }
    primMST(graph,n);
}

void primMST(int graph[20][20],int n)
{
     int parent[20];
     int key[20];
     int mstSet[20];
     for (int i = 0; i < n; i++)
        key[i] = 9999, mstSet[i] = 0;
     key[0] = 0;
     parent[0] = -1;
     for (int count = 0; count < n-1; count++)
     {
        int u = minKey(key, mstSet,n);
        mstSet[u] = 1;
        for (int v = 0; v < n; v++)
        {
           if (graph[u][v] && mstSet[v] == 0 && graph[u][v] <  key[v])
            {
             parent[v]  = u;
             key[v] = graph[u][v];
            }
        }
     }
     printMST(parent, n, graph);
}

void printMST(int parent[20], int n, int graph[20][20])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < n; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

int minKey(int key[20], int mstSet[20], int n)
{
   int min = 9999, min_index;

   for (int v = 0; v < n; v++)
    {
     if (mstSet[v] == 0 && key[v] < min)
         {
             min = key[v];
             min_index = v;
         }
    }
   return min_index;
}
