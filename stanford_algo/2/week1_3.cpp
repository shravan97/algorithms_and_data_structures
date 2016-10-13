#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll wts[2500][2500];

struct chck
{
	bool operator ()(pair< pair <int,int> ,int> const &p1,pair< pair <int,int> ,int> const &p2)
	{
		return (p1.second > p2.second); 
	}
};

ll prims_mst(list<int> *adj,int s,int n)
{
	std::map<int, bool> s1;
	priority_queue <pair< pair <int,int> ,int> , std::vector<pair< pair <int,int> ,int> > , chck> q;
	list<int>::iterator it;
	bool visited[n];
	memset(visited,0,sizeof(visited));
	visited[s]=1;

	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		q.push(make_pair(make_pair(s,*it),wts[s][*it]));
		// visited[*it]=1;
	}

	ll len=0;

	while(!q.empty())
	{
		pair< pair <int,int> ,int> p=q.top();
		q.pop();
		// cout<<" here outside at edge "<<p.first.first<<' '<<p.first.second<<' '<<p.second<<endl;
		if(!s1[p.first.first] || !s1[p.first.second])
		{
			// cout<<" here at edge "<<p.first.first<<' '<<p.first.second<<' '<<p.second<<endl;
			int v;
			if(visited[p.first.first]==0)
				v=p.first.first;
			else
				v=p.first.second;

			s1[p.first.first]=1; 
			s1[p.first.second]=1;
			len+=p.second;

			list<int>::iterator it1;
			visited[v]=1;

			for(it1=adj[v].begin();it1!=adj[v].end();it1++)
			{
				// cout<<" here..... "<<v<<" "<<*it1<<endl;
				if(!visited[*it1])
				{
					q.push(make_pair(make_pair(v,*it1),wts[v][*it1]));
				}
			}
		}

	}

	return len;
}

int main(int argc, char const *argv[])
{
	int m,n;
	cin>>n>>m;
	list<int> adj[n+1];

	for(int i=0;i<m;i++)
	{
		int a,b;
		ll wt;
		cin>>a>>b>>wt;
		adj[a].push_back(b);
		adj[b].push_back(a);
		wts[a][b]=wts[b][a]=wt;

	}

	cout<<prims_mst(adj,1,n)<<endl;
	return 0;
}