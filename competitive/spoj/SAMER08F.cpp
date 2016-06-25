#include <cstdio>
int main(int argc, char const *argv[])
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)break;
		printf("%lld\n",(long long)((n*(n+1)*(2*n+1))/6) );
	}
	return 0;
}