#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool p=1;
void dfs(list <ll> *adj,int * visited, int v)
{
	if(!visited[v])
	{
		p=0;
		return;
	}

	visited[v]--;

	for(auto vt:adj[v])
	{
		dfs(adj,visited,vt);
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,k;

		cin>>n>>k;
		list <ll> adj[1001];

		int visited[n+1];

		for(int i=0;i<n;i++)
		{
			int a,b;

			cin>>a>>b;

			memset(visited,0,sizeof(visited));

			if(b!=-1)
				adj[a].push_back(b);

		}

		for(int i=0;i<n;i++)
		{
			int val;
			cin>>val;
			visited[i+1]=val;
		}

		int num=0;

		for(int i=0;i<k;i++)
		{
			int v;
			cin>>v;
			dfs(adj,visited,v);
			
			if(p)
				num++;
			p=1;
		}

		cout<<num<<endl;
	}
	return 0;
}
