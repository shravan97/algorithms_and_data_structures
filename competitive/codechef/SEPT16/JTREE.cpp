#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs_chck(bool * visited , vector <ll> &v,ll vt , ll *tot_cost , list<ll> *graph,list< pair<ll,ll> > *cost)
{
	if(visited[vt])return;
	visited[vt]=1;
	list<ll>::iterator it;
	// cout<<" at vertex : "<<vt<<" and sz of vec "<<v.size()<<endl;
	// cout<<" elements "<<endl;

	std::vector<ll>::iterator it2;
	// for(it2=v.begin();it2!=v.end();it2++)
		// cout<<*it2<<endl;

	ll min_cost=INT_MAX;
	list< pair<ll,ll> >::iterator it1;

	for(it1=cost[vt].begin();it1!=cost[vt].end();it1++)
	{
		// cout<<it1->first<<' '<<it1->second<<endl;
		if(v.size()>=it1->first)
		{
			ll prevmin=(*min_element(v.end()-it1->first,v.end()));
			
			if(min_cost>it1->second+prevmin)
				min_cost=it1->second+prevmin;
		}
		else if(min_cost>it1->second)
			min_cost=it1->second;
	}

	// cout<<" for v "<<vt<<" min cost "<<min_cost<<endl;

	if(vt!=1)
	{
		tot_cost[vt]=min_cost;
	}
	else tot_cost[vt]=0;

	for(it=graph[vt].begin();it!=graph[vt].end();it++)
	{
		// cout<<" for "<<vt<<' '<<*it<<endl;
		if(visited[*it])
		{
			// cout<<" continue for "<<vt<<' '<<*it<<endl;
			continue;
		}
		std::vector<ll> k=v;
		k.push_back(min_cost);
		dfs_chck(visited,k,*it,tot_cost,graph,cost);

	}
}

int main(int argc, char const *argv[])
{
	ll n,m;
	cin>>n>>m;
	ll i;
	
	ll tot_cost[n+1];
	list<ll> graph[n+1];
	list< pair<ll,ll> > cost[n+1];

	for(i=0;i<n-1;i++)
	{
		ll a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		// cout<<" pushed "<<a<<' '<<b<<endl;
	}
	for(i=0;i<m;i++)
	{
		ll v,k,w;
		cin>>v>>k>>w;
		cost[v].push_back(make_pair(k,w));
		// cout<<" cost : "<<v<<' '<<k<<' '<<w<<endl;
	}
	ll q;
	cin>>q;
	bool visited[n+1];
	memset(visited,0,n+1);
	std::vector<ll> v1;
	dfs_chck(visited,v1,1,tot_cost,graph,cost);
	while(q--)
	{
		ll f;
		cin>>f;
		cout<<tot_cost[f]<<endl;
	}

	return 0;
}