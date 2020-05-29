//Bfs Algorithm
//BFS is used for traversal
//More use of bfs is
//1.Spanning Tree
//The spanning tree will minimum in case of non weighted graph
//2.To compute short distance in case of non weighted graph
#include<iostream>
using namespace std;
int visited[100];
int Queue[100];
int A[100][100];
int parent[100];
int dist[100];
int front=-1;
int rear=-1;
void push(int val)
{
	if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
	}
	else
	{
		rear++;
	}
	Queue[rear]=val;
}
void pop()
{
	front++;
	if(front>rear)
	{
		front=rear=-1;
	}
}
void bfs(int in,int N)
{
	int i;
	visited[in]=1;
	push(in);
	parent[in]=-1;
	dist[in]=0;
	while(front!=-1 && rear!=-1)
	{
		int x=Queue[front];
		pop();
		printf("%d\n",x);
		for(i=0;i<N;i++)
			if(A[x][i]==1 && visited[i]==0)
			{
				push(i);
				parent[i]=x;
				dist[i]=dist[x]+1;
				visited[i]=1;
			}	
	}
}
int main()
{
	int N,i,j;
	cin>>N;
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	{
		ll U,V;
		cin>>U>>V;
		cin>>A[i][j];		
	
	}
	bfs(0,N);
	cout<<"\nDistance Array\n";
	for(i=0;i<N;i++)
	{
		cout<<i<<":"<<dist[i]<<"\t";
	}	
	return 0;
}
