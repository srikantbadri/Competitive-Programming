//List of primes upto 10^8
//We need to do binary search to find any prime :)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 100000001;		//list of primes upto 10^8
const int LIM = 10001;
int flag[MAX>>6];
vector<int> primes;
 
#define ifcV(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define iscV(x) (flag[x>>6]|=(1<<((x>>1)&31)))
 
void sieve() {
	register int i, j, k=1, x;
	primes.emplace_back(2);
	for(i=3; i<LIM; i+=2) {
		if(!ifcV(i)) {
			primes.emplace_back(i);
			for(j=i*i, x=i<<1; j<MAX; j+=x) iscV(j);
		}
	}
	for(; i<MAX; i+=2) {
		if(!ifcV(i)) primes.emplace_back(i);
	}
}
int main()
{
	sieve();
	//cout<<primes[10000000];
    vector<int>::iterator it;
    long count=0;
    it=primes.end();
    while(count<=100)
    {
        cout<<*it<<endl;
        it--;     
        count++;
    }
}
