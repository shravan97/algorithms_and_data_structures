#include <cstdio>
#include <algorithm>
#include <map>
typedef long long int ll;
using namespace std;
int main(int argc, char const *argv[])
{
	ll n,i;
	scanf("%lld",&n);
	ll p[n];
	std::map<ll, ll> max_ind , min_ind;

	for(i=0;i<n;i++)
	{
		scanf("%lld",&p[i]);
	}
	ll q;
	scanf("%lld",&q);

	sort(p,p+n);
	for(i=0;i<n;i++)
	{
		max_ind[p[i]]=i;
		if(i!=0)
		{
			if(min_ind[p[i]]==0)
				min_ind[p[i]]=i;
		}

	}

	for(i=0;i<q;i++)
	{
		ll m;
		scanf("%lld",&m);
		ll l=0,ul=n-1,mid=(l+ul)/2;
		// printf("Here q %lld \n",q);
		if(m<p[0])
		{
			printf("0\n");
			continue;
		}
		while(l<ul && p[mid]!=m)
		{
			// printf("l %lld ul %lld \n",l,ul );
			if(m>p[mid])
			{
				l = mid+1;
			}
			else ul = mid-1;

			mid=(l+ul)/2;
			// printf("m %lld ",mid );
		}
		if(p[mid]<=m)
			printf("%lld\n",max_ind[p[mid]]+1 );
		else printf("%lld\n",min_ind[p[mid]] );
	}

	return 0;
}