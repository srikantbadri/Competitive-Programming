//Insertion Sort
#include<stdio.h>
void InsertionSort(int A[],int n)
{
	int i;
	for(i=1;i<=n-1;i++)
	{
		int value=A[i];
		int hole=i;
		while(A[hole-1]>value && hole>0)
		{
			A[hole]=A[hole-1];
			hole=hole-1;
		}
		A[hole]=value;
	}
	
}
int main()
{
	int i,A[]={5,4,3,2,1,0};
	InsertionSort(A,6);
	for(i=0;i<6;i++)
		printf("%d ",A[i]);
	return 0;
}
