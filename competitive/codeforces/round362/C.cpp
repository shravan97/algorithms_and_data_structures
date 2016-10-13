#include <bits/stdc++.h>
#include <string.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int q;
	cin>>q;
	std::map<ll, ll> tree;

	while(q--)
	{
		// cout<<" q here "<<q<<endl;
		ll v , u,w;
		int val;
		cin>>val;

		if(val==1)
		{
			cin>>v>>u>>w;
			// cout<<v<<u<<w<<endl;
			std::map<ll, bool> visited;
			ll node = v;
			while(node!=1)
			{
				tree[node]+=w;
				visited[node]=1;
				node/=2;
				// cout<<" here "<<node<<' '<<tree[node]<<endl;
			}

			node = u;
			// cout<<u<<endl;

			while(!visited[node] && node!=1)
			{
				tree[node]+=w;
				visited[node]=1;
				node/=2;
				// cout<<" here "<<node<<' '<<tree[node]<<endl;
			}
			// cout<<node<<" h \n";

			while(node!=1)
			{
				// cout<<" this \n";
				tree[node]-=w;
				node/=2;
			}
		}
		else
		{ 
			cin>>v>>u;
			// cout<<v<<u<<" yo \n";
			std::map<ll , bool> visited;
			ll node = v;
			ll sum=0;
			while(node!=1)
			{
				sum+=tree[node];
				// cout<<" here "<<node<<' '<<tree[node]<<endl;
				visited[node]=1;
				node/=2;
			}
			node = u;
			while(!visited[node] && node!=1)
			{
				// cout<<" h "<<node<<endl;
				sum+=tree[node];
				visited[node]=1;
				node/=2;
			}
			while(node!=1)
			{
				// cout<<" h1 \n";
				sum-=tree[node];
				node/=2;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}