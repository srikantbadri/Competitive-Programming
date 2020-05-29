//Author: Srikant Badri
//Persistent Segment Tree
//RSQ using 
//Modified Version of segment tree
//Here the nodes can be updated
//Source:- Geeks for Geeks

#include<iostream>
using namespace std;
#define MAXN 1000

//Structure of node
struct node
{
	int val;
	struct node *left,*right;
	//Constructor
	node(){}
	node(node *l,node *r,int v)
	{
		left=l;
		right=r;
		val=v;
	}
	
};


//Input array
int Arr[MAXN];

//Root Pointers for all versions
node *version[MAXN];

//Version-0
void build(node *n,int low,int high)
{
	if(low==high)
	{
		n->val=Arr[low];
		return;
	}
	int mid=(low+high)/2;
	//Initialize left & right
	n->left=new node(NULL,NULL,0);
	n->right=new node(NULL,NULL,0);
	build(n->left,low,mid);
	build(n->right,mid+1,high);
	n->val=n->left->val+n->right->val;	
}
int query(node *n,int low,int high,int l,int r)
{
	if(l>high || r<low || low>high)	//No Overlap
		return 0;
	if(l<=low && r>=high)	//Total overlap
		return n->val;
	int mid=(low+high)/2;
	return query(n->left,low,mid,l,r)+query(n->right,mid+1,high,l,r);
}
void upgrade(node *prev,node *curr,int low,int high,int idx,int value)
{
	if(idx<low || idx>high || low>high)
	return;
	if(low==high)
	{
		curr->val=value;
		return;
	}
	int mid=(low+high)/2;
	if(idx<=mid)
	{
		//Changes int the left part
		//So right part will be as it is
		curr->right=prev->right;
		curr->left=new node(NULL,NULL,0);
		
		upgrade(prev->left,curr->left,low,mid,idx,value);		
	}
	else 
	{
		//Changes int the right part
		//So left part will be as it is
		curr->left=prev->left;
		curr->right=new node(NULL,NULL,0);
		
		upgrade(prev->right,curr->right,mid+1,high,idx,value);		
	}
	curr->val=curr->left->val+curr->right->val;
}
//Prints Segment Tree -Inorder
void print(node *root)
{
	if(root==NULL)return;
	print(root->left);
	cout<<root->val<<"->";
	print(root->right);	
}
int main()
{
	int i,A[]={1,2,3,4,5,6,7};
	for(i=0;i<7;i++)
		Arr[i]=A[ i];
	node *root=new node(NULL,NULL,0);
	build(root,0,6);
	version[0]=root;
	cout<<query(root,0,6,0,2)<<endl;
	
	//Modifying
	//Version-1
	version[1]=new node(NULL,NULL,0);
	upgrade(version[0],version[1],0,6,2,10);
	print(version[0]);
	cout<<endl;
	print(version[1]);
	cout<<endl;

	return 0;
}
