//Maximal Subarray Sum
#include<iostream>
using namepace std;
void Kadane()
{
int best = 0, sum = 0;
for (int k = 0; k < n; k++) {
sum = max(array[k],sum+array[k]);
best = max(best,sum);
}
cout << best << "\n";
	
}
int main()
{
	return 0;
}
