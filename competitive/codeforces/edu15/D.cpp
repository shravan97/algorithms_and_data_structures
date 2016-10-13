#include <cstdio>
typedef long long int ll;

ll least_time(ll d,ll k,ll a,ll b,ll t , bool repaired)
{
	if(d<=k && !repaired)
		return a*d;
	else if(d<=k)
		return ((t+a*d)>b*d)?b*d:(t+a*d);
	else
	{
		if(k*a+t >=b*k)
		{
			return k*a + (d-k)*b;
		}
		else
		{
			return (d/k)*(k*a +t)-t+least_time(d-k*(d/k) , k,a,b,t,1); 
		}
	}
}

int main(int argc, char const *argv[])
{
	ll d,k,a,b,t;
	scanf("%lld %lld %lld %lld %lld",&d,&k,&a,&b,&t);
	printf("%lld\n",least_time(d,k,a,b,t,0) );

	return 0;
}