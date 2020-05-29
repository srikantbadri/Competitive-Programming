//Knapsack 0-1
//Dynamic Programming Problem
#include<iostream>
typedef long long int ll;
using namespace std;
ll Mat[100][100];
int main()
{
	ll i,j;
	ll totalWeight=7;
	ll val[]={1,4,5,7};
	ll wt[]={1,3,4,5};
	ll N=4;
	for(i=0;i<N;i++)
	{
		for(j=0;j<=totalWeight;j++)
		{
			if(i==0)
			{
				if(j>=wt[0])
				{
					Mat[i][j]=val[0];				
				}
			}
			else
			{
				if(j-wt[i]>=0)
					Mat[i][j]=max(Mat[i-1][j],val[i]+Mat[i-1][j-wt[i]]);
				else
					Mat[i][j]=Mat[i-1][j];				
			}
		}
	}
	cout<<Mat[N-1][totalWeight]<<endl;
	return 0;
}
