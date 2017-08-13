#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	cout<<"Enter to number for which divisors have to be found\n";
	int i,k;
	cin>>k;
	int count=0;
	for(i=1;i<=sqrt(k);i++)
	{
		if(k%i==0)
		{
			cout<<i<<"\t";
			count++;
			if(i!=(k/i))
			{
				cout<<k/i<<"\t";
				count++;			
			}
		}
	}
	cout<<"\ncount="<<count<<"\n";
	return 0;
}
