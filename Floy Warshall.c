#include<stdio.h>
#include<stdlib.h>
#define v 4
#define INF 9999
void print(int dist[][v])
{
	int i,j;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++)
		{
			if(dist[i][j]==INF)
				printf("INF\t");
			else
				printf("%d\t",dist[i][j]);
		}
		printf("\n");
	}
}
void FloydWarshall(int graph[][v])
{
	int dist[v][v],i,j,k;
	for(i=0;i<v;i++)
		for(j=0;j<v;j++)
			dist[i][j]=graph[i][j];
	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(dist[i][j]>(dist[i][k]+dist[k][j]))
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	print(dist);
}
int main()
{
	int i,j,graph[v][v];
	printf("Enter the adjecency matrix\n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			scanf("%d",&graph[i][j]);
			
		}
	}
	FloydWarshall(graph);
	return 0;
}
