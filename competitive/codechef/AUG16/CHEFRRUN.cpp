#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long int ll;
ll traverse(ll * visited , ll *a , ll *v, ll start , ll vnum , ll order , ll tot )
{
	if(visited[start]==vnum)
		return order-v[start];
	else if(visited[start]!=0 && visited[start]<vnum)
		return 0;
	else
	{
		visited[start]=vnum;
		v[start]=order;
		// cout<<"visited "<<start;
		return traverse(visited , a,v,(start+a[start]+1)%tot,vnum , order+1 , tot);
	}
}
int main(int argc, char const *argv[])
{
	ll t;
	cin>>t;

	while(t--)
	{
		ll i,n;
		cin>>n;
		ll a[n],tot=0;

		for(i=0;i<n;i++)
			cin>>a[i];
		ll visited[n],vnum=1,v[n];
		memset(visited,0,n*(sizeof(ll)));
		memset(v,0,n*(sizeof(ll)));
		

		// cout<<traverse(visited,a,0,vnum,1,n);

		for(i=0;i<n;i++)
		{
			// cout<<visited[i]<<'\n';
			if(!visited[i])
			{
				tot+=traverse(visited,a,v,i,vnum++,1,n);
			}
		}
		cout<<tot<<'\n';
	}
	return 0;
}