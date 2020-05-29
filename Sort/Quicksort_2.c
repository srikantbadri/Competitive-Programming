//QuickSort
#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int findPivot(int A[],int start,int end)
{
	int pivot=start;
	int L=start+1,R=end;
	while(1)
	{
		while(A[L]<=A[pivot] && L<end)L++;
		while(A[R]>A[pivot] && R>0)R--;
		if(L<R)
		{
			swap(&A[L],&A[R]);	
		}
		else break;
	}
	//swap pivot
	swap(&A[pivot],&A[R]);
	return R;
}
void Quicksort(int A[],int start,int end)
{
	if(start<end)
	{
		int pIndex=findPivot(A,start,end);
		Quicksort(A,start,pIndex-1);
		Quicksort(A,pIndex+1,end);
	}
}
int main()
{
	int i,A[]={5,100,3,2,1};
	Quicksort(A,0,4);
	for(i=0;i<=4;i++)
		printf("%d ",A[i]);
	return 0;
}
