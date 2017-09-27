//Author-Srikant Badri
//Calculating Prime factors of a given number
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long int ll;
bool Prime[1000000];
vector<ll> primeFactors[1000000];
void eval()
{
	ll i,j;
	memset(Prime,true,sizeof(Prime));
	for(i=2;i<=1000000;i++)
	{
		if(Prime[i])
		{
			primeFactors[i].push_back(i);
			for(j=2*i;j<=1000000;j+=i)
			{
				Prime[j]=false;
				primeFactors[j].push_back(i);
			}
		}
	}
}
int main()
{
	eval();
	ll Num=108;
	while(Num!=1)
	{
		cout<<primeFactors[Num][0]<<" ";
		Num=Num/primeFactors[Num][0];
	}
	return 0;
}
