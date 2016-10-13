#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;
int val[105],d[105];
int dp(int k)
{
	if(k==0)
		return 0;
	// if(d[k]!=INF)
	// {
	// 	cout<<" here "<<k<<' '<<d[k]<<endl;
	// 	return d[k];
	// }
	int i;
	for(i=1;i<=k;i++)
	{
		// cout<<" in \n";
		int z = dp(k-i);
		if(val[i]!=-1 && z!=INF && d[k]>val[i]+z )
		{
			d[k]=val[i]+z;
			cout<<"  d["<<k<<']'<<" = "<<val[i]+z<<endl;
		}
	}
	return d[k];
}

int main(int argc, char const *argv[])
{
	// cout<<sizeof(d)<<endl;
	// cout<<INF<<endl;
	memset(d,INF,sizeof(d));
	d[0]=0;
	long long int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int i,j;
		for(i=1;i<=k;i++)
			cin>>val[i];
		// dp[0]=0;
		// cout<<" inf "<<INF<<endl;

		// for(i=0;i<=k;i++)
		// {
		// 	// bool isch=0;
		// 	for(j=1;j<=k;j++)
		// 	{
		// 		if(i==0)
		// 		{
		// 			dp[j]=INF;
		// 			// wt[i][j]=0;
		// 		}
		// 		else if(i>=j)
		// 		{
		// 			// cout<<" here "<<i<<" "<<i-j<<' '<<dp[i-j]<<endl;
		// 			if(val[j]!=-1 && dp[i]>val[j]+dp[i-j] && dp[i-j]!=INF)
		// 				dp[i]=val[j]+dp[i-j];
		// 		}
		// 		// else
		// 			// dp[i]=0;

		// 		// cout<<dp[j]<<' ';
		// 	}
		// 	// cout<<endl;
		// }

		if(dp(k)==INF)
			cout<<-1<<endl;
		else
			cout<<d[k]<<endl;
	} 	
	return 0;
}

// f(n) = min(val[i]+f(n-i));