#include <bits/stdc++.h>
using namespace std;
#define val1 100005

typedef long long int ll;

void dfs(list<ll> * adj,bool *visited,ll v)
{
	visited[v]=1;

	for(auto node:adj[v])
	{
		if(!visited[node])
			dfs(adj,visited,node);
	}
}

int main(int argc, char const *argv[])
{
	ll n,e;
	
	cin>>n>>e;

	if(n==1 && e==0)
	{
		cout<<"YES\n";
		cout<<1<<endl;
		return 0;
	}


	list <ll> udir[val1];
	std::vector< pair<ll,ll> > v;
	ll indeg[n+1],outdeg[n+1];
	memset(indeg,0,sizeof(indeg));
	memset(outdeg,0,sizeof(outdeg));
	

	for(ll i=0;i<e;i++)
	{
		ll a,b;
		cin>>a>>b;

		v.push_back(make_pair(a,b));
		udir[a].push_back(b);
		udir[b].push_back(a);
		indeg[b]++;
		outdeg[a]++;
		
	}

	for(ll i=1;i<=n;i++)
	{
		if((indeg[i]+outdeg[i])&1)
		{
			cout<<"NO\n";
			return 0;
		}
	}

	ll cc=0;
	bool visited[n+1];
	memset(visited,0,sizeof(visited));

	for(ll i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			// cout<<i<<endl;
			dfs(udir,visited,i);
			cc++;
		}

		if(cc>1)
		{
			cout<<"NO\n";
			return 0;
		}
	}

	ll lh[n+1],rh[n+1],num[n+1];
	memset(lh,0,sizeof(lh));
	memset(rh,0,sizeof(rh));
	memset(num,0,sizeof(num));


	// for(ll i=0;i<e;i++)
	// {
	// 	pair <ll,ll> p=v[i];
	// 	// if(!(lh[p.first]==0 && rh[p.second]==0) && !(lh[p.first]!=0 && rh[p.second]!=0))
	// 	// {
	// 	// 	v[i] = make_pair(p.second,p.first);
	// 	// 	// swap(p.first,p.second);
	// 	// }

		
	// 	// cout<<p.first<<' '<<p.second<<endl;
	// 	lh[p.first]++;
	// 	rh[p.second]++;
	// }

	// for(ll i=e-1;i>=0;i--)
	// {
	// 	// cout<<lh[v[i].second]<<' '<<rh[v[i].second]<<' '<<rh[v[i].first]<<' '<<lh[v[i].first]<<endl;
	// 	if(((lh[v[i].second]<rh[v[i].second]) || (rh[v[i].first]<lh[v[i].first])) && !(lh[v[i].second]==rh[v[i].second] || lh[v[i].first]==rh[v[i].first]))
	// 	{
	// 		lh[v[i].first]--;
	// 		rh[v[i].first]++;
	// 		rh[v[i].second]--;
	// 		lh[v[i].second]++;
			
	// 		v[i] = make_pair(v[i].second,v[i].first);
	// 	}
	// }

	// for(ll i=e-1;i>=0;i--)
	// {
	// 	// cout<<lh[v[i].second]<<' '<<rh[v[i].second]<<' '<<rh[v[i].first]<<' '<<lh[v[i].first]<<endl;
	// 	if(((lh[v[i].second]<rh[v[i].second]) || (rh[v[i].first]<lh[v[i].first])) && !(lh[v[i].second]==rh[v[i].second] || lh[v[i].first]==rh[v[i].first]))
	// 	{
	// 		lh[v[i].first]--;
	// 		rh[v[i].first]++;
	// 		rh[v[i].second]--;
	// 		lh[v[i].second]++;
			
	// 		v[i] = make_pair(v[i].second,v[i].first);
	// 	}
	// }


	// for(ll i=1;i<=n;i++)
	// {
	// 	// cout<<lh[i]<<' '<<rh[i]<<endl;
	// 	if(lh[i]==0 || rh[i]==0 || lh[i]!=rh[i])
	// 	{
	// 		cout<<"NO\n";
	// 		return 0;
	// 	}
	// }

	// memset(indeg,0,sizeof(indeg));
	// memset(outdeg,0,sizeof(outdeg));
	

	// for(auto p:v)
	// {
	// 	indeg[p.second]++;
	// 	outdeg[p.first]++;
	// }

	// for(ll i=1;i<=n;i++)
	// {
	// 	if(indeg[i]!=outdeg[i])
	// 	{
	// 		cout<<"NO\n";
	// 		return 0;
	// 	}
	// }

	for(ll i=0;i<e;i++)
	{
		pair<ll,ll> p=v[i];
		if((abs(lh[p.first]+1-rh[p.first]) + abs(lh[p.second]-rh[p.second]-1)) >(abs(lh[p.first]-rh[p.first]-1) + abs(lh[p.second]-rh[p.second]+1)) )
		{
			swap(v[i].first,v[i].second);
		}
		lh[v[i].first]++;
		rh[v[i].second]++;
	}


	cout<<"YES\n";

	for(ll i=0;i<e;i++)
	{
		cout<<v[i].first<<' '<<v[i].second<<endl;
	}

	return 0;
}