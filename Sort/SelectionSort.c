//Selection Sort
#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void SelectionSort(int A[],int n)
{
	int i,iMin,j;
	for(i=0;i<=n-2;i++)
	{
		iMin=i;
		for(j=i+1;j<=n-1;j++)
		{
			if(A[j]<A[iMin])
			iMin=j;
		}
		swap(&A[i],&A[iMin]);
	}
}
int main()
{
	int i,A[]={5,4,3,2,1,0};
	SelectionSort(A,6);
	for(i=0;i<6;i++)
		printf("%d ",A[i]);
	return 0;
}
