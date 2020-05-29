//Longest Increasing Sequence
//DP Problem
#include<iostream>
#include<cstring>
typedef long long int ll;
using namespace std;
int main()
{
	ll N,i,j;
	cin>>N;
	ll A[N];
	ll Val[N];
	for(i=0;i<N;i++){cin>>A[i];Val[i]=1;}
	for(i=1;i<N;i++)
	{
		for(j=0;j<i;j++)
		{
			if(A[j]<A[i])
				Val[i]=max(Val[i],Val[j]+1);			
		}
	}
	cout<<Val[N-1];
	return 0;
}
