//Sliding Window Maximum (Maximum of all subarrays of size k)
//Given an array and an integer k, find the maximum for each and every contiguous subarray of size k.
//http://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
#include<iostream>
#include<deque>
typedef long long int ll;
using namespace std;
void FindMaxSlideWindow(ll arr[],ll n,ll k)
{
	ll i;
	
	//Create a deque of size k
	//It will be filled with all zeroes
	///We will store indices in decreasing order
	deque<ll> Deque(k);
	
	//For 1st Window
	for(i=0;i<k;i++)
	{
		//Remove all the smaller elements from the back
		while(!Deque.empty() && arr[i]>=arr[Deque.back()])
			Deque.pop_back();
		//Now push current element.
		Deque.push_back(i);		
	}
	for(;i<n;i++)
	{
		//Print the Maximum element of the previous window
		cout<<arr[Deque.front()]<<" ";
		
		//Remove all the element from the front which will be out of window
		while(!Deque.empty() && arr[i]<=i-k)
			Deque.pop_front();
		
		//Remove all the elements which are smaller than current element
		while(!Deque.empty() && arr[i]>=arr[Deque.back()])
			Deque.pop_back();
		
		//Now push the current element
		Deque.push_back(i);
	}
	cout<<arr[Deque.front()]<<endl;
	return;
}
int main()
{
	ll i,N;
	cin>>N;
	ll arr[N];
	for(i=0;i<N;i++)cin>>arr[i];
	ll K;
	cin>>K;
	FindMaxSlideWindow(arr,N,K);
	return 0;
}
