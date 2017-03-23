#include <bits/stdc++.h>
# define mod 1000000007
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;

	std::vector<ll> fact;
	fact.push_back(1);

	for(ll i=1;i<=10000;i++)
	{
		fact.push_back((fact[i-1]*i)%mod);
	}

	while(t--)
	{
		ll n;
		cin>>n;
		cout<<((n-3)*fact[n-3])%mod<<endl;
	}
	return 0;
}