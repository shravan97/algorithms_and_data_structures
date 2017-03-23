#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t--)
	{
		int n,m;
		cin>>n>>m;

		ll c[n+1][m+1],p[n+1][m+1],cost[n+1][m+1];

		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=m;j++)
			{
				cin>>c[i][j];
				cost[i][j]=0;
			}
		}

		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=m;j++)
			{
				cin>>p[i][j];
			}
		}
		cost[1][1]=0;
		ll dsum=0,rsum=0;

		for(ll i=1;i<n;i++)
			dsum+=c[i][1];
		dsum+=p[n][1];
		for(ll j=1;j<m;j++)
			dsum+=c[n][j];

		for(ll i=1;i<m;i++)
			rsum+=c[1][i];
		rsum+=p[1][n];
		for(ll j=1;j<n;j++)
			rsum+=c[j][n];




		// for(ll i=1;i<=n;i++)
		// {
		// 	for(ll j=1;j<=m;j++)
		// 	{
		// 		if(!(i==1 && j==1))
		// 		{
		// 			if(i==1)
		// 			{
		// 				cost[i][j] = cost[i][j-1]+p[i][j-1];
		// 			}
		// 			else if(j==1)
		// 				cost[i][j] = cost[i-1][j]+c[i-1][j];
		// 			else
		// 				cost[i][j] = min(cost[i][j-1]+p[i][j-1],cost[i-1][j]+c[i-1][j]);
		// 		}

				
		// 	}
		// }

		cout<<min(dsum,rsum)<<endl;
		
	}
	return 0;
}
