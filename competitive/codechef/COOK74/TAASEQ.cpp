#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];

		std::map<ll,ll > diff;

		ll prev;
		for(ll i=0;i<n;i++)
		{
			ll k;
			cin>>k;
			if(i!=0)
			{
				diff[k-prev]++;
			}
		}
	}
	return 0;
}