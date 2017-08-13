#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define debug(ccc)		cout<<#ccc<<"="<<ccc<<endl;
#define tr(c,it)	for(typeof(c.begin()) it=c.begin();it!=c.end();it++)
//Storing the prime factors
bool isPrime[1000009];
int visited[1000009];
ll factors[1000009];
vector<ll> Prime[1000009];

//InputArray
ll A[1000009];
//Sieve
void sieve()
{
	ll i,j;
	memset(isPrime,true,sizeof(isPrime));
	isPrime[0]=false;
	isPrime[1]=false;
	factors[1]=1;
	for(i=2;i<=1000000;i++)
	{
		if(isPrime[i])
		{
		factors[i]=i;
		for(j=i+i;j<=1000000;j+=i)
		{
			isPrime[j]=false;
			factors[j]=i;
		}			
		}
	}
}
//Structure for segment tree
struct node
{
	vector<ll> factors;
	node *left,*right;
	node(){
	}	
	node(node *l,node *r,ll s){
		left=l;
		right=r;
	}
};
typedef struct node node;
node *root=NULL;
void build(node *root,ll beg,ll end)
{
	if(beg>end)
	return;
	if(beg==end)
	{
		ll size=0;
		ll prevSum=0;
		tr(Prime[A[beg]],it)
		{	
			ll Num=*it;
			root->factors.push_back(Num);
		}
		sort(root->factors.begin(),root->factors.end());
		return;	
	}
	ll  mid=(beg+end)/2;
	root->left=new node(NULL,NULL,0);
	root->right=new node(NULL,NULL,0);
	build(root->left,beg,mid);
	build(root->right,mid+1,end);
	merge(root->left->factors.begin(),root->left->factors.end(),root->right->factors.begin(),root->right->factors.end(),back_inserter(root->factors));
}
ll query(node *root,ll beg,ll end,ll L,ll R,ll X,ll Y)
{
	//No Overlap
	if(L>end || R<beg || beg>end || root==NULL)
		return 0;
	//Total Overlap
	if(L<=beg && R>=end)
	{
//		tr(root->factors,it){
//			cout<<*it<<endl;
//		}
		ll index1=lower_bound(root->factors.begin(),root->factors.end(),X)-root->factors.begin();
		ll index2=upper_bound(root->factors.begin(),root->factors.end(),Y)-root->factors.begin();
		return index2-index1;
	}
	//Partial Overlap
	ll mid=(beg+end)/2;
	return
	query(root->left,beg,mid,L,R,X,Y)+
	query(root->right,mid+1,end,L,R,X,Y);
}
#define all(c) 			(c).begin(),(c).end()
#define cpresent(c,x) 	(find(all(c),x) != (c).end())
int main()
{
	ll N,Q,i;
	sieve();
	cin>>N;
	for(i=0;i<N;i++)
		cin>>A[i];
//	set<ll> Set(A,A+N);
//	tr(Set,it)	
	for(i=0;i<N;i++)
	{
		if(visited[A[i]]==1)
		continue;
		visited[A[i]]=1;
		ll num=A[i];
		if(num==1)continue;
		ll e=factors[A[i]];
		//obtaining all the prime factors.
		
		Prime[A[i]].push_back(e);
		while(e!=0 && num%e==0 && num>1)
		{
			num=num/e;
			e=factors[num];
			if(e!=1)
			Prime[A[i]].push_back(e);
		}
	}
	root=new node(NULL,NULL,0);
	build(root,0,N-1);
	cin>>Q;
	while(Q--)
	{
		ll L,R,X,Y;
		cin>>L>>R>>X>>Y;
		cout<<query(root,0,N-1,L-1,R-1,X,Y)<<endl;
	}
	return 0;
}
