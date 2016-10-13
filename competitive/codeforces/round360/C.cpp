#include <cstdio>
#include <cstring>
#include <vector>
typedef long long int ll;
using namespace std;

std::vector<ll> *v , blue , red;
std::vector< std::vector<ll> > connected;
bool dfs(ll index , int *color , int c , ll *visited)
{
	if(!v[index].empty())connected[connected.end()-1].push_back(index);
	if((*(color+index)!=0) && *(color+index)!=c)
		return 0;
	*(color+index)=c;
	if((c==1) && !v[index].empty())blue.push_back(index);
	else if(!v[index].empty()) red.push_back(index);
	else return 0;
	*(visited + index)=1;
	
	for(std::vector<ll>::iterator i=v.begin(); i!=v.end();i++)
	{
		bool b = dfs(*i,color,(c==1)?2:1,visited);
		if(b==0)return 0;
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	ll n,m,i,cc=0,ns=0;
	scanf("%lld %lld",&n,&m);
	v = new std::vector<ll>[n+1];
	int color[n+1];
	ll visited[n+1];

	memset(color,0,n+1);
	memset(visited,0,n+1);

	for(i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			if(!v[i].empty())
			{
				std::vector<ll> temp;
				connected.push_back(temp);
				cc++;
				if(dfs(i,color,1,visited)==0)
				{
					ns++;
				}
			}
		}
	}

	if(cc==1)
	{
		if(ns==1)printf("-1\n");
		else
		{
			printf("%lld\n",blue.size());
			vector<ll>::iterator it;
			for(it=blue.begin();it!=blue.end();it++)
				printf("%lld\n",*it );

			printf("%lld\n",red.size());
			for(it=red.begin();it!=red.end();it++)
				printf("%lld\n",*it );
			
		}
	}
	else if(cc==ns)
	{
		for(int j=0;j<2;j++)
		{
			printf("%lld\n",connected[j].size() );
			for (std::vector<ll>::iterator itr = connected[j].begin(); itr != connected[j].end(); ++itr)
			{
				printf("%lld\n",*itr );
			}
		}
	}
	else
		


	return 0;
}