#include <bits/stdc++.h>
#define min(a,b)((a>b)?b:a)
#define INFY 1e15
#define pii pair<ll , ll>
typedef long long int ll;
using namespace std;

struct chck_pair
{
	bool operator()(const pii& p1 ,const pii& p2 )
	{
		return p1.second > p2.second;
	}
};

priority_queue <pii , vector<pii> , chck_pair> q;
list< pii > graph[1000];
void dijkstra(ll src,ll *dist,bool * visited)
{
	ll vt=src,vis=0;
	bool flag=1,flag1=0;
	while(flag)
	{
		list<pii>::iterator it;
		visited[vt]=1;
		if(q.empty() && flag1)flag=0;

		for(it=graph[vt].begin();it!=graph[vt].end();it++)
		{
			// cout<<" here "<<vt<<" , "<<it->first<<' '<<dist[vt]<<' '<<it->second<<' '<<dist[it->first]<<endl;
			if(dist[it->first]>dist[vt]+it->second)
			{
				// cout<<" update : "<<it->first<<" with distance "<<dist[vt]+it->second<<endl;
				dist[it->first]=dist[vt]+it->second;
			}
			if(!visited[it->first])
			{
				q.push(*it);
				flag1=1;
			}

		}
		if(!flag)continue;
		pii p1 = q.top();
		vt = p1.first;
		q.pop();
	}
}

int main()
{
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++)
	{
		ll a,b,wt;
		cin>>a>>b>>wt;
		graph[a].push_back(make_pair(b,wt));
		graph[b].push_back(make_pair(a,wt));
	}

	// cout<<" n is "<<n<<endl;

	ll dist[n+1];
	// const ll sz=sizeof(ll)*(n+1);
	bool visited[n+1];
	// memset(dist,INFY,sz);
	for(ll i=1;i<=n;i++)dist[i]=INFY;
	memset(visited,0,n+1);
	dist[1]=0;

	dijkstra(1 , dist,visited);
	for(ll i=1;i<=n;i++)
		cout<<" dist of vertex "<<i<<' '<<dist[i]<<endl;
	return 0;
}