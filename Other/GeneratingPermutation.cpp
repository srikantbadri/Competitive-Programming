#include<iostream>
#include<algorithm>
typedef long long int ll;
using namespace std;
int main()
{
	ll A[]={5,4,3,2,1};
	sort(A,A+5);
	while(1)
	{
		cout<<A[0]<<" "<<A[1]<<" "<<A[2]<<" "<<A[3]<<" "<<A[4]<<endl;
		if(!next_permutation(A,A+5))break;
	}
	return 0;
}
