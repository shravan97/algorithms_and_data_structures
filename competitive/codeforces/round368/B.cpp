#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dist =INT_MAX;
std::map<ll, std::map<ll, ll> > graph;
set <ll> st;

int main(int argc, char const *argv[])
{
	ll n,m,k,i;
	cin>>n>>m>>k;

	for(i=0;i<m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		if(graph[a][b]!=0)
		{
			if(graph[a][b] > c)
			{
				graph[a][b]=c;
				graph[b][a]=c;
			}
		}
		else
		{
			graph[a][b]=c;
			graph[b][a]=c;
		}
	}
	if(k==0 || k==n)
	{
		cout<<-1<<endl;
		return 0;
	}
	else
	{
		for(i=0;i<k;i++)
		{
			ll t;
			cin>>t;
			st.insert(t);
		}
	}

	std::map<ll, std::map<ll, ll> >::iterator i1;
	std::map<ll, ll>::iterator i2;
	bool f=0;

	for(i1=graph.begin();i1!=graph.end();i1++)
	{
		for(i2=i1->second.begin();i2!=i1->second.end();i2++)
		{
			if(st.find(i1->first)!=st.end())
			{
				if(st.find(i2->first)==st.end())
				{
					if(dist>i2->second)
					{
						// cout<<i1->first<<' '<<i2->first<<endl;
						dist = i2->second;
						f=1;
					}
				}
			}
			else if(st.find(i2->first)!=st.end())
			{
				if(dist>i2->second)
				{
					f=1;
					dist = i2->second;
				}
			}
		}
	}
	if(!f)
		cout<<-1<<endl;
	else
	cout<<dist<<endl;

	return 0;
}