//Insertion into max heap
#include<iostream>
using namespace std;
int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
void InsertIntoMaxHeap(int A[],int N,int x)
{
	A[N]=x;
	int parent=(N-1)/2;
	int child=N;
	while(child!=0 && A[parent]<A[child])
	{
		swap(A[parent],A[child]);
		child=parent;
		parent=(child-1)/2;
	}
//	N++;
}
int main()
{
	int A[10]={6,5,4,3,2,1};
	InsertIntoMaxHeap(A,6,100);
	for(int i=0;i<7;i++)
	{
		cout<<A[i]<<endl;
	}
	return 0;
}
