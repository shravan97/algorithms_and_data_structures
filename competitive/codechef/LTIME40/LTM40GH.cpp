#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(bool * visited , list<ll> *adj , ll v,ll *wt,ll *ul,ll val)
{
	
}

int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll wt[n+1],ul[n+1];
		for(ll i=1;i<=n;i++)
			cin>>wt[i];
		list <ll> adj[n+1];
		for(ll i=1;i<n;i++)
		{
			ll a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}


	}
	return 0;
}