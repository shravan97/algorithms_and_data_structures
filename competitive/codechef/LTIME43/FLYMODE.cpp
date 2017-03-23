#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool compare(pair <ll,ll> p1, pair <ll,ll> p2)
{
	return p1.first>p2.first;
}

ll search(std::vector< pair<ll,ll> > &v,pair <ll,ll> p)
{
	ll len=v.size();

	ll s=0;
	cout<<" for "<<p.first<<' '<<p.second<<endl;
	for(ll i=0;i<len;i++)
	{
		if(v[i].first>=p.first && v[i].second<=p.second)
		{
			s++;
			cout<<v[i].first<<' '<<v[i].second<<endl;
		}
		else if(v[i].first<=p.first && v[i].second>p.first)
		{
			s++;
			cout<<v[i].first<<' '<<v[i].second<<endl;
		}
		else if(v[i].second>=p.second && v[i].first<p.second)
		{
			cout<<v[i].first<<' '<<v[i].second<<endl;
			s++;
		}
	}

	return s;
}

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	ll mx = INT_MIN, mxh=INT_MIN,prev;
	std::vector< pair<ll,ll> > v;

	for(ll i=0;i<n;i++)
	{

		ll k;
		cin>>k;
		if(i!=0)
		{
			v.push_back(make_pair(min(k,prev),max(k,prev)));
			prev=k;
		}
		else
			prev=k;
	}

	sort(v.begin(),v.end(),compare);

	ll m=INT_MIN;

	for(ll i=0;i<n;i++)
	{
		m=max(m,search(v,v[i]));
	}

	cout<<m<<endl;
	return 0;
}
