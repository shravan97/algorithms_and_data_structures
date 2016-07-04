#include <cstdio>
#include <list>
#include <vector>
#include <set>
using namespace std;

std::list <long long int> *graph;
vector <int> color;
bool state=0;
long long int freq[2] = {0,0};
int count=0;
int dfs(long long int n , long long int it=1)
{
	long long int i;
	bool cur_st=state;
	for(list <long long int >::iterator t=graph[it].begin();t!=graph[it].end();t++)
	{
		printf("%lld %d %d\n",*t,color[*t],cur_st );
		if(color[*t]==-1)
		{
			color[*t]=cur_st;
			freq[color[*t]]++;
		}
		else if(color[*t]!=cur_st)
		{
			return -1;
		}

		state = (state==0)?1:0;
		int b = dfs(n,*t);
		if(b==-1)return -1;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	long long int n,m,i;
	scanf("%lld %lld",&n,&m);
	
	graph = new std::list<long long int> [n+1];
	for(i=0;i<m;i++)
	{
		long long int v1,v2;
		scanf("%lld %lld",&v1,&v2);
		if(graph[v1].size() >= graph[v2].size())
			graph[v1].push_back(v2);
		else graph[v2].push_back(v1);
	}
	vector <int> col(n+1,-1);
	color=col;
	if(!graph[1].empty())
	{
		color[1]=1;
		freq[1]++;
	}
	std::set<long long int> v0;
	std::set<long long int> v1;

	bool flag=0;
	for(i=1;i<=n;i++)
	{
		if(color[i]==-1 || i==1)
		{
			
			if(dfs(n,i)==-1)
			{
				flag=1;
				break;
			}
		}
	}

	if(flag==1)
		printf("-1\n");
	else
	{
		for(i=1;i<=n;i++)
		{
			if(color[i]==0)v0.insert(i);
			else if(color[i]==1) v1.insert(i);
			for(list<long long int>::iterator k=graph[i].begin();k!=graph[i].end();k++)
			{
				if(color[*k]==0)
					v0.insert(*k);
				else if(color[*k]==1) v1.insert(*k);
			}
		}

		printf("%lld\n",freq[0] );
		for(set<long long int>::iterator k=v0.begin();k!=v0.end();k++)
			printf("%lld ",*k );
		printf("\n%lld\n",freq[1]);
		for(set<long long int>::iterator k=v1.begin();k!=v1.end();k++)
			printf("%lld ",*k );

	}

	return 0;
}