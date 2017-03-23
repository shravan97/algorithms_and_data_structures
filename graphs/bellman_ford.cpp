#include <bits/stdc++.h>
using namespace std;
#define INF 1e10
typedef long long int ll;

/*

d(i,v) = min(d(i-1,v),dist(i-1,j)+d(j,v))

meaning : for i edges from source 'v', calculate using dp

*/


std::vector<ll> shortest_path(list < pair<ll,ll> > *graph, int s,int V)
{
	vector<ll> dist(V,INF);
	dist[s]=0;

	for(ll i=0;i<V-1;i++)
	{
		for(ll j=0;j<V;j++)
		{
			for(auto p:graph[j])
				dist[p.first]=min(dist[p.first],p.second+dist[j]);
		}
	}

	return dist;
}

int main(int argc, char const *argv[])
{

	
	
	return 0;
}
