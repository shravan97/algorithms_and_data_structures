#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool compare(pair <ll,ll> p1,pair <ll,ll> p2)
{
	return (p1.first>p2.first);
}

int main(int argc, char const *argv[])
{
	
	int t;
	cin>>t;

	while(t--)
	{

		ll n;
		cin>>n;

		std::vector< pair<ll,ll> > p;

		for(ll i=0;i<n;i++)
		{
			ll k;
			cin>>k;
			p.push_back(make_pair(k,i));
		}

		list<ll> adj[50005];

		for(ll i=0;i<n-1;i++)
		{
			ll a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		ll ranks[n],elems[n];

		memset(ranks,0,sizeof(ranks));
		memset(elems,0,sizeof(elems));

		sort(p.begin(),p.end(),compare);

		for(ll i=0;i<p.size();i++)
		{
			// cout<<p[i].second<<' ';
			ranks[p[i].second]=i;
			elems[i]=p[i].second;
		}
		// cout<<endl;

		for(ll i=0;i<n;i++)
		{
			std::map<ll, bool> map;
			map[ranks[i]]=1;
			for(auto e:adj[i+1])
				map[ranks[e-1]]=1;
			ll prev=-1,ans=-1,c=0;
			// cout<<" for vertex : "<<i+1<<endl;
			if(map.size()==n)
			{
				cout<<0<<' ';
				continue;
			}
			for(auto e:map)
			{
				// cout<<e.first<<endl;
				if(e.first-prev>1)
				{
					ans=prev+1;
					break;
				}
				prev=e.first;
				c++;
			}

			if(ans<0)
			{
				ans=prev+1;
			}

			cout<<elems[ans]+1<<' ';
		}

		cout<<endl;
	}
	return 0;
}
