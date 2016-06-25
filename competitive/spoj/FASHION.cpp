#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		long long int s=0;
		scanf("%d",&n);
		long long int m[n],w[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&m[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&w[i]);
		}
		sort(m,m+n);
		sort(w,w+n);
		for(i=0;i<n;i++)
			s+=m[i]*w[i];
		printf("%lld\n",s );
	}
	return 0;
}