//Below is the implementation of the BI Partite Graph in Cpp using BFS and Graph Coloring
//The question was part of Codevita 2k17
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int visited[2009];
vector<ll> graph[2009];
 
void addedge(ll v,ll w){
	graph[v].push_back(w);
	graph[w].push_back(v);
}
 
bool bfs(int c){
	ll color[2009];
	memset(color,-1,sizeof(color));
	queue<int > Q;
	Q.push(c);
	color[c] = 1;
	while(!Q.empty()){
		int p = Q.front(); //parent vertex
		Q.pop();
		for(ll i=0;i<graph[p].size();i++){
		if(visited[ graph[p][i] ] == 0 && color[graph[p][i]] ==-1 ){	//unvisited vertex so change its color
			Q.push(graph[p][i]);
			color[ graph[p][i] ] = 1 - color[p];
		}
		else if(visited[ graph[p][i] ] != 0 && color[graph[p][i]] == color[p] ){	//parent and child with the same color
			return false;
		}
		}
		visited[p] = 1;
	}
return true;
}
 
int main(void)
{
	ll N;
	cin>>N;
	ll P;
	cin>>P;
//	int n,e;
//	while(tc--){
//	p++;
//	cin>>n>>e;
//	while(P--)
//	{
//	for(int i=0;i<2009;i++){
//		graph[i].clear();
//	}
	for(ll i=0;i<P;i++)
	{
		ll v,w;
		cin>>v>>w;
//		v--;
//		w--;
		addedge(v,w);
		addedge(w,v);
	}
	//print(n);
	memset(visited,0,sizeof(visited));
	bool flag=true;
//	for(ll i=1;i<=N;i++)
//	{
//		if(visited[i] == 0){	//If one or more components are remaining
			flag = bfs(1);
//		}
//		if(!flag) {
//			break;
//		}
//	}
	if(flag){
		printf("tadaa\n");
	}
	else {
		printf("bada\n");
	}
//	}
return 0;
}
