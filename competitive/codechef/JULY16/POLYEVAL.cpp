#include <cstdio>
typedef long long ll;

ll powermod(ll a ,ll b ,ll m)
{
	if(b==1) return a%m;
	else if(b==0) return 1%m;
	else
	{
		ll t = powermod(a,b/2,m);
		if(b&1) return ((t%m)*((t%m)*(a%m))%m)%m;

		return ((t%m)*(t%m))%m;
	}
}

int main(int argc, char const *argv[])
{
	ll n,i,q;
	scanf("%lld",&n);
	ll a[n+1];

	for(i=0;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}

	scanf("%lld",&q);

	while(q--)
	{
		ll x,s=0;
		scanf("%lld",&x);

		for(i=0;i<=n;i++)
		{
			s+=a[i]*powermod(x,i,786433);
			s=s%786433;
		}

		printf("%lld\n",s );
	}
	return 0;
}