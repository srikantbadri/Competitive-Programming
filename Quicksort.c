#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int A[],int start,int end)
{
 	int	i,pivot=A[end];
	int	pIndex=start;
	for(i=start;i<=end-1;i++)
	{
		if(A[i]<=pivot)
		{
			swap(&A[i],&A[pIndex]);
			pIndex=pIndex+1;
		}
	}
	swap(&A[pIndex],&A[end]);
	return pIndex;
}
void QuickSort(int A[],int start,int end)
{
	if(start<end)
	{
		int pIndex=partition(A,start,end);
		QuickSort(A,start,pIndex-1);
		QuickSort(A,pIndex+1,end);
	}
}
int main()
{
	int i,A[]={5,4,3,2,1};
	QuickSort(A,0,4);
	for(i=0;i<=4;i++)
		printf("%d ",A[i]);
	return 0;
}
