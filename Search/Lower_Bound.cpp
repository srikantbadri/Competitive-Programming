#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int A[]={10,20,30,10,10,20};
	vector<int> v(A,A+6);
	sort(v.begin(),v.end());
	vector<int>::iterator low,up;
	low=lower_bound(v.begin(),v.end(),40);
	up=upper_bound(v.begin(),v.end(),30);
	cout<<"lower_bound="<<(low-v.begin())<<endl;
	cout<<"upper_bound="<<(up-v.begin())<<endl;
	return 0;
}
