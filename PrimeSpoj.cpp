#include<iostream>
#include<cmath>
typedef long long int ll;
using namespace std;
bool isPrime(ll n)
{
	ll i;
	if(n==1)	return 0;
	if(n==2)	return 1;
	if(n%2==0)	return 0;
	for(i=3;i<=sqrt(n);i+=2)	
		if(n%i==0)
			return 0;
	return 1;
}
void PrintPrime(int n)
{
	ll i;
	for(i=0;i<100000;i++){
	if(isPrime(i))
		{
			cout<<i<<endl;
			n--;	
		}	
		if(n==0)break;
	}
}
int main()
{
	PrintPrime(5);
	//cout<<isPrime(97);
//	ll t,i;
//	cin>>t;
//	while(t--)
//	{
//		ll A,B;
//		cin>>A>>B;
//		for(i=A;i<=B;i++)
//			if(isPrime(i))
//				cout<<i<<"\n";
//		cout<<"\n";
//	}
	return 0;
}
