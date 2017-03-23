#include <cstdio>
#include <cstring>
#include <list>
using namespace std;
typedef long long int ll;
list<ll> tree[10005];
bool visited[10005];
ll l1=0,l2=0;
ll dfs(bool * visited , ll v)
{
	visited[v]=1;

	list<ll>::iterator it;
	ll max1=0,max2=0;
	for(it=tree[v].begin();it!=tree[v].end();it++)
	{
		if(!visited[*it])
		{
			ll dt= dfs(visited,*it);
			if(max1<=1+dt)
			{
				max2=max1;
				max1=1+dt;
			}
			else if(max2<1+dt)
				max2=1+dt;
		}
	}

	if(l1<max1+max2)
		l1=max1+max2;
	return max1;

}

int main(int argc, char const *argv[])
{
	long int n,i;
	scanf("%ld",&n);
	for(i=0;i<n-1;i++)
	{
		long int a,b;
		scanf("%ld %ld",&a,&b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	ll val = dfs(visited,1);

	printf("%lld\n", l1);

	return 0;
}