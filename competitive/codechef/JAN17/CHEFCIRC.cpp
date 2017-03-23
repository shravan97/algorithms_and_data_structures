#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;

	std::vector< pair<int,int> > v;

	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}

	std::vector<float> dist;

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			dist.push_back((float)sqrt((v[i].first-v[j].first)*(v[i].first-v[j].first) + (v[i].second-v[j].second)*(v[i].second-v[j].second) ));
		}
	}

	sort(dist.begin(),dist.end());

	for(auto e:dist)
		cout<<e<<' ';
	cout<<endl;

	cout<<dist[m-1]<<endl;
	return 0;
}
