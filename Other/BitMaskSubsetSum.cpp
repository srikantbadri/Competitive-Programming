//BitMask
//SubsetSum
#include <iostream>
#include<cmath>
#include<map>
using namespace std;
typedef long long int ll;
int main() {
	int N=5,i,j;
	ll Arr[]={1,2,3,4,5};
	int size=pow(2,N);
	for(i=0;i<size;i++)
	{
		ll Num=i,sum=0;
		for(j=0;j<5;j++)
		{
			if(Num%2==0)
			{
				//cout<<1<<" ";
				sum+=Arr[j];
			}
			else
			{
				//cout<<0<<" ";
			}
			Num/=2;
		}
		cout<<sum<<endl;
	}
	return 0;
}
