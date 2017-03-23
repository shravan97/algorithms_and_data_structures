#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool func(const pair<ll,ll> &p1,const pair<ll,ll> &p2)
{
	return !((p1.second-p1.first)>(p2.second-p2.first));
}
int main(int argc, char const *argv[])
{
	ll n,m;
	cin>>n>>m;

	std::vector< pair<ll,ll> > v;

	for(ll i=0;i<m;i++)
	{
		ll x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(), v.end(),func);
	ll l =v[0].first-1,r=v[0].second-1;

	ll out=1,in=0;

	cout<<v[0].second-v[0].first+1<<endl;

	for(int i=0;i<n;i++)
	{
		if(i>=l && i<=r )
		{
			cout<<in<<' ';
			in++;
		}
		else
		{
			cout<<out<<' ';
			out++;
		}
	}

	cout<<endl;

	return 0;
}
