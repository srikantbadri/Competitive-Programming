#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long int ll;
using namespace std;
struct IPC
{
    ll no;
    ll arrival;
    ll lectures;
    ll sadness;
};
bool myfunc(struct IPC a,struct IPC b)
{
    if(a.arrival!=b.arrival)
    {
        return a.arrival<b.arrival;
    }
    else{
        return a.sadness>b.sadness;
    }
}
void InsertIntoMaxHeap(struct IPC queue[],ll N,ll x,ll lec,ll no)
{
	queue[N].sadness=x;
	queue[N].lectures=lec;
	queue[N].no=no;
	ll parent=(N-1)/2;
	ll child=N;
	while(child!=0 && queue[parent].sadness<queue[child].sadness)
	{
		swap(queue[parent].sadness,queue[child].sadness);
		swap(queue[parent].lectures,queue[child].lectures);
		swap(queue[parent].no,queue[child].no);
		child=parent;
		parent=(child-1)/2;
	}
}
ll left(ll i)
{
	return 2*i+1;
}
ll right(ll i)
{
	return 2*i+2;
}
void MaxHeapify(struct IPC queue[],ll i,ll N)
{
	ll largest;
	ll l=left(i);
	ll r=right(i);
	if(l<N && queue[l].sadness>queue[i].sadness)
		largest=l;
	else largest=i;
	if(r<N && queue[r].sadness>queue[largest].sadness)
		largest=r;
	if(largest!=i)
	{
		swap(queue[i].sadness,queue[largest].sadness);
		swap(queue[i].lectures,queue[largest].lectures);
		swap(queue[i].no,queue[largest].no);
		MaxHeapify(queue,largest,N);
	}
}
struct IPC	queue[100005];
int main()
{
    ll t;
    cin>>t;
    while(t--)
	{
        ll i,N,B;
        cin>>N>>B;
        struct IPC ipc[N];
		for(i=0;i<N;i++)
        {
            ipc[i].no=i+1;
            cin>>ipc[i].arrival>>ipc[i].lectures>>ipc[i].sadness;
		}
        sort(ipc,ipc+N,myfunc);
		for(i=0;i<N;i++)
        {
            ipc[i].no=i;
		}
		ll front=0,ptr=0;
        ll index=0,size=0;
        ll total_sadness=0;
        for(i=1;i<=B;i++)
        {
			while(ipc[ptr].arrival<=i)
			{
				InsertIntoMaxHeap(queue,index,ipc[ptr].sadness,ipc[ptr].lectures,ipc[ptr].no);
				index++;
				ptr++;
			}
			if(index)
			{
				queue[0].lectures--;
				ipc[queue[0].no].lectures--;
				if(queue[0].lectures==0)
				{
					queue[0].sadness=0;
					swap(queue[0].sadness,queue[index-1].sadness);
					swap(queue[0].lectures,queue[index-1].lectures);
					swap(queue[0].no,queue[index-1].no);					
					index--;
					MaxHeapify(queue,0,index);	
				}				
			}
        }
        for(i=0;i<N;i++)
        {
              total_sadness+=ipc[i].lectures*ipc[i].sadness;
        }
        cout<<total_sadness<<endl;
 
    }
    return 0;
}
 
