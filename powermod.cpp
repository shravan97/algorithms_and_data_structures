#include <cstdio>
typedef long long int ll;
/*
Modulus of a^b by Fermat's theorem
*/

ll powmod(ll a , ll b , ll m)
{
	if(b==1)
		return a%m;
	else if(b==0) return 1%m;
	else
	{
		ll t = powmod(a,b/2,m);
		if(b&1)
		{
			return (t*t*a)%m;
		}
		else return ((t)*(t))%m;
	}
}

int main(int argc, char const *argv[])
{
	ll a=5;
	ll b=5;
	printf("%lld\n",powmod(a,0,5) );
	return 0;
}