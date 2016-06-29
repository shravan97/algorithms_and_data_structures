#include <cstdio>
int main(int argc, char const *argv[])
{
	long long int n,m,i,ed=0;
	scanf("%lld %lld",&n,&m);
	for(i=0;i<m;i++)
	{
		long long int v1 , v2;
		scanf("%lld %lld",&v1,&v2);
		if(v1-v2==1 || v2-v1==1)
			ed++;
		else if(v2-v1==n-1 || v1-v2==n-1)
			ed++;
	}
	if(ed>=n-1)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}