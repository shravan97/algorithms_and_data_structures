#include <stdio.h>
typedef long long int ll;
int main()
{
	int t;
	scanf("%d",&t);

	for(;t>0;t--)
	{
		ll n;
		scanf("%lld",&n);
		if(n%6==0)
			printf("Misha\n");
		else
			printf("Chef\n");
	}

	return 0;
}