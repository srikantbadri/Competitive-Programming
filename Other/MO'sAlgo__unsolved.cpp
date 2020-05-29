//MO's Algorithm
#include<iostream>
#include<cmath>
#include<algorithm>
typedef long long int ll;
ll N;
#define FastRead ios_base::sync_with_stdio(0);cin.tie(0); 
#define BLOCK ceil(sqrt(N))
ll A[1000009];
//The count array
ll cnt[1000009];
//The answer array
ll ans[1000009];
ll answer=0;
void fastscan(ll &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;
 
    number = 0;
 
    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;
 
        // extract the next character from the buffer
        c = getchar();
    }
 
    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;
 
    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
void add(ll position)
{
	cnt[A[position]]++;
	if(cnt[A[position]]==1)
		answer++;
}
void remove(ll position)
{
	cnt[A[position]]--;
	if(cnt[A[position]]==0)
		answer--;	
}
struct node
{
	ll L,R,i;
}q[100000];
bool cmp(node x,node y)
{
	//First priority by block
	if(x.L/BLOCK!=y.L/BLOCK)
	{
		return x.L/BLOCK<y.L/BLOCK;
	}
	else //OR else by right index
		return x.R<y.R;
}
using namespace std;
int main()
{
	ll i;
	fastscan(N);
	for(i=0;i<N;i++)
		fastscan(A[i]);
	ll Q;
	fastscan(Q);
//	cin>>Q;
	for(i=0;i<Q;i++)	
	{
		fastscan(q[i].L);
//		cin>>q[i].L;
		q[i].L--;
		fastscan(q[i].R);
		q[i].R--;
		q[i].i=i;
	}
	sort(q,q+Q,cmp);
	ll currentL=0;
	ll currentR=0;
	for(i=0;i<Q;i++)
	{
		ll L=q[i].L;
		ll R=q[i].R;
		//Incase currentL is less than L
		//Time to remove some elements
		while(currentL<L)
		{
			remove(currentL);
			currentL++;
		}
		
		//Incase currentL is more than L
		//Time to add some elements
		while(currentL>R){
			add(currentL-1);
			currentL--;
		}

		//Incase currentR is less than R
		//Time to add some elements
		while(currentR<=R)
		{
			add(currentR);
			currentR++;
		}
		
		//Incase currentR is more than R
		//Time to remove some elements
		while(currentR>R+1){
			remove(currentR-1);
			currentR--;
		}
		ans[q[i].i]=answer;
	}
	for(i=0;i<Q;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
