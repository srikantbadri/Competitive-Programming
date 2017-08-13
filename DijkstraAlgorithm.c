//Implementing dijkstra algorithm
#include<stdio.h>
#include<limits.h>
#include<conio.h>
int dist[10];
void Dijkstra(int v,int cost[][9],int n)
{
	int count,w,i,num,u,min_index;
	int s[10];
	for(i=0;i<n;i++)
	{
		s[i]=0;
		dist[i]=cost[v][i];
	}
	s[v]=1;
	dist[v]=0;
	for(count=2;count<=n;count++)
	{
		int min=INT_MAX;
		for(u=0;u<n;u++)
		{
			if(dist[u]<min && s[u]==0)
			{
				min=dist[u];
				min_index=u;
			}
		}
		s[min_index]=1;
		for(w=0;w<n;w++)
		{
			if(dist[w]>dist[min_index]+cost[min_index][w] && s[w]==0)
				dist[w]=dist[min_index]+cost[min_index][w];
		}
	}
}
int main()
{
	int i,j,n,matrix[9][9];
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		scanf("%d",&matrix[i][j]);
		
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(matrix[i][j]==0)
				matrix[i][j]=999;
	Dijkstra(0,matrix,n);
	printf("So the distance matrix between 0 and every other node is:-\n");
	for(i=0;i<n;i++)
		printf("%d\n",dist[i]);
	getch();
}
