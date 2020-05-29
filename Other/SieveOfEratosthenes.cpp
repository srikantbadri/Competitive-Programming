#include<iostream>
#include<cstring>
#include<fstream>
typedef long long int ll;
using namespace std;
bool Primes[10000003];
void calPrime()
{
	ll t,i,j;
	memset(Primes,true,sizeof(Primes));
	Primes[0]=false;
	Primes[1]=false;
	for(i=2;i<=10000000;i++)
	{
		if(Primes[i])
		{
			for(j=i*2;j<=10000000;j+=i)
			{
				Primes[j]=false;
			}
		}
	}

}
int main()
{
	ll i,n;
	calPrime();
	cin>>n;
	for(i=0;i<100000;i++){
		if(Primes[i])
		{
			cout<<i<<endl;
			n--;	
		}	
		if(n==0)break;
	}
	return 0;
}
