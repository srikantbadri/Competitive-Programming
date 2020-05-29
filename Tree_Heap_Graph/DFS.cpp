#include<iostream>
#include<list>
#include<cstring>
using namespace std;
bool visited[4];
list<int> *adj;
void AddEdge(int u,int v)
{
	adj[u].push_back(v);
}
void dfs(int i)
{
	visited[i]=true;
	cout<<i<<"\n";
	
	list<int>::iterator it;
	for(it=adj[i].begin();it!=adj[i].end();it++) 
		if(!visited[*it])
			dfs(*it);
}
int main()
{
	memset(visited,false,sizeof(visited));
	adj=new list<int> [10];
	AddEdge(0,1);
	AddEdge(1,2);
	AddEdge(2,3);
	dfs(0);
	return 0;
}
