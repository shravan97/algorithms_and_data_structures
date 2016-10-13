#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
list< pair<ll,ll> > adj[5005];

vector<int> dfs(int v , ll t,ll t_max,bool *visited,vector<int> vec,int max )
{
	// cout<<" here "<<v<<" at time "<<t<<endl;
	std::vector<int> emt;
	if(t>t_max)
		return emt;
	else if(t==t_max)
		return vec;
	visited[v]=1;
	list< pair<ll,ll> >::iterator it;
	ll st=t;
	// vec.push_back(v);
	std::vector<int> v1=vec;
	// ll cur_size=v.size();

	for(it=adj[v].begin();it!=adj[v].end();it++)
	{
		std::vector<int> tk=v1;
		// std::vector<int>  k;
		if(!visited[it->first] && it->first>tk[tk.size()-1])
		{
			tk.push_back(it->first);
			// cout<<" in "<<it->first<<endl;
			tk=dfs(it->first,t+it->second,t_max,visited,tk);
		}
		if(tk.size()>vec.size())
			vec=tk;
		else if(t+it->second==t_max)
			vec=tk;
	}
	return vec;

	// return 
}

int main(int argc, char const *argv[])
{
	ll n,m,t;
	cin>>n>>m>>t;
	for(int i=0;i<m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		adj[a].push_back(make_pair(b,c));
		adj[b].push_back(make_pair(a,c));
	}
	bool visited[n];
	memset(visited,0,sizeof(visited));
	std::vector<int> emt;
	emt.push_back(1);
	std::vector<int>::iterator it1;
	std::vector<int> v = dfs(1,0,t,visited,emt,n);

	cout<<v.size()<<endl;

	for(it1=v.begin();it1!=v.end();it1++)
		cout<<*it1<<' ';

	cout<<endl;

	// cout<<v.size()<<endl;
	return 0;
}