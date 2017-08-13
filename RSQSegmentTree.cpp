//Segment Tree (-_-)
//For Range Sum Query  (>_<)
#include<iostream>
using namespace std;
void constructTree(int input[],int segTree[],int low,int high,int pos)
{
	if(low==high)
	{
		segTree[pos]=input[low];
		return;
	}
	int mid=(low+high)/2;
	constructTree(input,segTree,low,mid,2*pos+1);	//left child
	constructTree(input,segTree,mid+1,high,2*pos+2); //right child
	segTree[pos]=(segTree[2*pos+1]+segTree[2*pos+2]); //root
}
int rangeMinQuery(int segTree[],int qlow,int qhigh,int low,int high,int pos)
{
	if(qlow<=low && qhigh>=high) //total overlap
		return segTree[pos];
	if(qlow>high || qhigh<low)	//no overlap
		return 0;	//return 0
	//Partial Overlap
	int mid=(low+high)/2;
	return (rangeMinQuery(segTree,qlow,qhigh,low,mid,2*pos+1)+rangeMinQuery(segTree,qlow,qhigh,mid+1,high,2*pos+2));
}
int main()
{
	int Arr[]={1,2,3,4,5,6};
	int segTree[6];
	constructTree(Arr,segTree,0,5,0);
	cout<<rangeMinQuery(segTree,1,2,0,5,0)<<endl;
	return 0;
}
