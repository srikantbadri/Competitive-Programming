#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void combine(int A[],int start,int end)
{
	int i,mid=(start+end)/2;
	int L=start;
	int R=mid+1;
	int B[100],index=start;
	while(L<=mid && R<=end)
	{
		if(A[L]<A[R])
		{
			B[index]=A[L];
			L++;
			index++;
		}
		else
		{
			B[index]=A[R];
			R++;
			index++;
		}
	}
	while(L<=mid)
	{
		B[index]=A[L];
		index++;
		L++;
	}
	while(R<=mid)
	{
		B[index]=A[R];
		index++;
		R++;
	}
	//Copy back elements to A
	for(i=start;i<=end;i++)
	{
		A[i]=B[i];
	}
}
void Mergesort(int A[],int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		Mergesort(A,start,mid);
		Mergesort(A,mid+1,end);
		combine(A,start,end);
	}
}
int main()
{
	int i,A[]={5,4,3,2,1};
	Mergesort(A,0,4);
	for(i=0;i<=4;i++)
		printf("%d ",A[i]);
}
