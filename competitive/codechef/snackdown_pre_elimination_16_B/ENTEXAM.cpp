#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);

	for(;t>0;t--)
	{
		long long int n,k,m,i;
		int e,j;
		scanf("%lld %lld %d %lld",&n,&k,&e,&m);
		long long int marks[n][e] , tot[n];
		for(i=0;i<n-1;i++)
		{
			tot[i]=0;
			for(j=0;j<e;j++)
			{
				scanf("%lld",&marks[i][j]);
				tot[i]+=marks[i][j];
			}
		}

		tot[i]=0;
		for(j=0;j<e-1;j++)
		{
			scanf("%lld",&marks[i][j]);
			tot[i]+=marks[i][j];
		}

		sort(tot,tot+n-1);
		long long int d=(tot[n-1-k]+1-tot[n-1]);
		if(d>m)
			printf("Impossible\n");
		else
			printf("%lld\n",(d>0)?d:0);
	}

	return 0;
}