#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,c1=0;
		cin>>n;

		bool k;
		std::map<ll, ll> v;
		for(ll i=0;i<n;i++)
		{
			for(ll j=0;j<n;j++)
			{
				v[abs(i-j)]++;
				cin>>k;
				if(k)
					c1++;
			}
		}

		for(auto e:v)
		{
			if(c1-e.second<=0)
			{
				cout<<e.first<<endl;
				break;
			}
			else
				c1-=e.second;
		}
	}
	return 0;
}