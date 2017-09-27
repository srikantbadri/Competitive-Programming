#include<iostream>
#include<list>
#include<cstring>
#include<queue>
using namespace std;
typedef long long int ll;
list<ll> adj[100];
bool visited[100];
void addEdge(ll U,ll V)
{
	adj[U].push_back(V);
	adj[V].push_back(U);
}
void dfs(ll K)
{
	visited[K]=true;
	cout<<K<<" ";
	list<ll>::iterator it=adj[K].begin();
	for(;it!=adj[K].end();it++)
	{
		if(!visited[*it])
			dfs(*it);
	}
}
void bfs(ll K)
{
	memset(visited,false,sizeof(visited));
	visited[K]=true;
	queue<ll> Queue;
	Queue.push(K);
	while(!Queue.empty())
	{
		ll front=Queue.front();
		Queue.pop();
		cout<<front<<" ";
		list<ll>::iterator it=adj[front].begin();
		for(;it!=adj[front].end();it++)
		{
			if(!visited[*it])
			{
				visited[*it]=true;
				Queue.push(*it);	
			}	
		}		
	}
}
int main()
{
	memset(visited,false,sizeof(visited));
	ll N,M,i;
	cin>>N>>M;
	for(i=0;i<M;i++)
	{
		ll U,V;
		cin>>U>>V;
		addEdge(U,V);
	}
//	dfs(1);
	bfs(1);
	return 0;
}
