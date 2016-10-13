#include <cstdio>
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int n,m;
		scanf("%lld %lld",&n,&m);
		if((n*m)&1)
			printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}