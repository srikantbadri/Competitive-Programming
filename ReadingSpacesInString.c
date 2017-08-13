#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int S;
		char ch[100];
		scanf("%d\n",&S);
		while(S--)
			fgets(ch,51,stdin);
		int Q;
		scanf("%d\n",&Q);
		while(Q--)
			fgets(ch,51,stdin);
		fflush(stdin);	
	}
	return 0;
}
