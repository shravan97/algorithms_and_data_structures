#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct compare
{
	bool operator() (const pair<string,ll> &p1,const pair<string,ll> &p2)
	{
		if(p1.second>p2.second)
			return 1;
		return 0;
	}
};

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	std::vector< pair<string,ll> > sp,nsp;
	std::map<ll, bool> chck_sp;
	// std::map<ll, string> posts;

	for (ll i = 0; i < n; ++i)
	{
		ll k;
		cin>>k;
		chck_sp[k]=1;
	}
	for (ll i = 0; i < m; ++i)
	{
		ll a,p;
		string f;
		cin>>a>>p>>f;
		// posts[a]=f;

		if(chck_sp[a])
		{
			sp.push_back(make_pair(f,p));
		}
		else
			nsp.push_back(make_pair(f,p));
	}

	sort(sp.begin(),sp.end(),compare());
	sort(nsp.begin(),nsp.end(),compare());
	
	for(ll i=0;i<sp.size();i++)
	{
		// cout<<" sp pop "<<sp[i].second<<endl;
		cout<<sp[i].first<<endl;
	}

	for(ll i=0;i<nsp.size();i++)
	{
		// cout<<" nsp pop "<<nsp[i].second<<endl;
		cout<<nsp[i].first<<endl;
	}
	

	return 0;
}