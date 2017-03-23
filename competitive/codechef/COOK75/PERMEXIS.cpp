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
		std::vector<ll> v;
		for(ll i=0;i<n;i++)
		{
			ll k;
			cin>>k;
			v.push_back(k);
		}
		sort(v.begin(), v.end());
		bool flag=1;

		for(ll i=0;i<v.size()-1;i++)
		{
			if(abs(v[i]-v[i+1])>1)
			{
				flag=0;
				break;
			}
		}

		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}