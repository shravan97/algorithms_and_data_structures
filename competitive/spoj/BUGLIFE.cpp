#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool chck(list<ll> *adj ,bool *visited,ll v,int *cl,int curr)
{
	visited[v]=1;
	cl[v]=curr;
	list<ll>::iterator it;

	queue<ll> q;
	q.push(v);
	while(!q.empty())
	{
		list<ll>::iterator it;
		ll vt = q.front();
		q.pop();
		int rcl = -cl[vt];
		for(it=adj[vt].begin();it!=adj[vt].end();it++)
		{
			if(visited[*it])
			{
				if(cl[*it]!=rcl)
					return 0;
			}
			else
			{ 
				cl[*it]=rcl;
				visited[*it]=1;
				q.push(*it);
			}
		}

	}


	// for(it=adj[v].begin();it!=adj[v].end();it++)
	// {
	// 	// cout<<" here "<<*it<<endl;
	// 	int rcl=-curr;


	// 	// if(visited[*it] && *it!=v)
	// 	// {
	// 	// 	if(cl[*it]!=rcl)
	// 	// 		return 0;
	// 	// }
	// 	// else if(*it!=v)return chck(adj,visited,*it,cl,rcl);
	// }
	return 1;
}
int main(int argc, char const *argv[])
{
	ll t,k;
	scanf("%lld",&t);
	k=t;
	while(t--)
	{
		ll n,m;
		scanf("%lld %lld",&n,&m);
		list<ll> adj[n+1];
		for(ll i=0;i<m;i++)
		{
			// cout<<" for i "<<i<<endl;
			ll a,b;
			scanf("%lld %lld",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		// cout<<" here \n";

		bool visited[n+1];
		int cl[n+1];
		memset(visited,0,n+1);
		memset(cl,0,n+1);
		
		bool flag=1;

		for(ll i=1;i<=n;i++)
		{
			if(!visited[i])
			{
				if(chck(adj,visited,i,cl,1)==0)
				{
					flag=0;
					break;
				}
			}
		}

		printf("Scenario #%lld:\n",k-t);

		if(!flag)
			printf("Suspicious bugs found!\n");
		else
			printf("No suspicious bugs found!\n");

	}
	return 0;
}