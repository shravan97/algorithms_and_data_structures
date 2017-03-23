#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll powmod(ll a , ll b , ll m)
{
	if(b==1)
		return a%m;
	else if(b==0) return 1;
	else
	{
		ll t = powmod(a,b/2,m);
		if(b&2)
		{
			return (t*t*a)%m;
		}
		else return ((t)*(t))%m;
	}
}

ll modInv(ll a,ll mod)
{
	// Assume 'a' and 'mod' are coprime and mod is prime

	return powmod(a,mod-2,mod);
}
int main(int argc, char const *argv[])
{
	
	return 0;
}
