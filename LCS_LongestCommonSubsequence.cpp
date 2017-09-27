//Longest Common Subsequence
//LCS- Standard Dp Problem
//Problem Link- https://www.codechef.com/DI17R086/problems/CITYTRAV
#include<iostream>
using namespace std;
typedef long long int ll;
ll Mat[100][100];
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll i,j;
		string a,b;
		cin>>a>>b;
		ll I,J;
		ll size_a=a.size();
		ll size_b=b.size();
		for(i=0;i<size_a;i++)
		{
			for(j=0;j<size_b;j++)
			{
				I=i+1;
				J=j+1;
				if(a[i]==b[j])
				{
					Mat[I][J]=Mat[I-1][J-1]+1;
				}
				else
				{
					Mat[I][J]=max(Mat[I-1][J],Mat[I][J-1]);
				}
			}
		}
		cout<<Mat[size_a][size_b]<<endl;
	}
	return 0;
}
