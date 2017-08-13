//Implementing Heap Sort
//Refernce-Coreman
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
void MaxHeapify(int A[],int i,int N)
{
	int largest;
	int l=left(i);
	int r=right(i);
	if(l<N && A[l]>A[i])
		largest=l;
	else largest=i;
	if(r<N && A[r]>A[largest])
		largest=r;
	if(largest!=i)
	{
		swap(A[i],A[largest]);
		MaxHeapify(A,largest,N);
	}
}
void build_max_heap(int A[],int N)
{
	int i;
	for(i=N/2;i>=0;i--){
		MaxHeapify(A,i,N);	
	}
}
void HeapSort(int A[],int N)
{
	build_max_heap(A,N);
	int i;
	for(i=N-1;i>=0;i--) 
	{
		swap(A[0],A[i]);
		N--;
		MaxHeapify(A,0,N);
	}
}
int main()
{
	int i;
	int A[20]={500,25,66,89,34,100,5,4,3,2,1};
	HeapSort(A,10);
	for(i=0;i<10;i++)
	cout<<A[i]<<endl;
	return 0;
}
