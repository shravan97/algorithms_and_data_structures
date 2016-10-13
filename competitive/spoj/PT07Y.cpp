#include <iostream>
#include <list>
#include <cstring>
using namespace std;

list <long long int> g[10005];

void chck_cycle(bool * visited , long long int parent , long long int st)
{
	visited[st]=1;
	list <long long int>::iterator it;

	for(it=g[st].begin(); it!=g[st].end();it++)
	{
		// cout<<st<<' '<<*it<<'\n';			
		if(!visited[*it]) chck_cycle(visited,st,*it);
	}
	// return 0;
}

int main(int argc, char const *argv[])
{
	long long int n,i=0,m;
	cin>>n>>m;

	while(i<m)
	{
		long long int x,y;
		cin>>x>>y;
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
		i++;
	}

	bool visited[n],flag=1,chckd=0;
	memset(visited,0,n);
	long long int cc=0;
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		{
			chck_cycle(visited,i,i);
			cc++;
		}

	}
	if(cc==1 && m==n-1) cout<<"YES\n";
	else cout<<"NO\n";

	return 0;
}