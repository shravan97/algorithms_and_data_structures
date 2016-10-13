#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct chck
{
	bool operator ()(const pair<ll,ll> &p1 , const pair<ll,ll> &p2)
	{
		if((float)((float)p1.first/(float)p1.second)!=(float)((float)p2.first/(float)p2.second))
			return ((float)((float)p1.first/(float)p1.second)>(float)((float)p2.first/(float)p2.second));
		return ((p1.first>p2.first));
	}
};

struct chck1
{
	bool operator ()(const pair<ll,ll> &p1 , const pair<ll,ll> &p2)
	{
		if((p1.first-p1.second)!=(p2.first-p2.second))
			return ((p1.first-p1.second)>(p2.first-p2.second));
		return ((p1.first>p2.first));
	}
};

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	std::vector< pair<ll,ll> > v;
	for(ll i=0;i<n;i++)
	{
		ll a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end(),chck1());

	std::vector< pair<ll,ll> >::iterator it;
	ll s=0,t=0;
	for(it=v.begin();it!=v.end();it++)
	{
		t+=it->second;
		s+=it->first*t;
		// cout<<it->first<<' ';
		// cout<<it->second<<endl;
	}

	cout<<s<<endl;

	return 0;
}