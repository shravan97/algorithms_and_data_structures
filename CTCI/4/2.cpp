#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void dfs(bool * visited , list <ll> *adj,ll v)
{
	visited[v]=1;
	for(auto vr:adj[v])
	{
		if(!visited[vr])
			dfs(visited,adj,vr);
	}
}

int main(int argc, char const *argv[])
{
	list <ll> adj[10];
	adj[1].push_back(2);
	adj[2].push_back(3);
	adj[4].push_back(2);
	adj[5].push_back(4);
	adj[1].push_back(7);
	adj[1].push_back(8);
	
	bool visited[11];
	memset(visited,0,sizeof(visited));
	dfs(visited,adj,4);
	cout<<visited[2]<<endl;
	cout<<((visited[4]==0 || visited[1]==0)?0:1)<<endl;
	return 0;
}
