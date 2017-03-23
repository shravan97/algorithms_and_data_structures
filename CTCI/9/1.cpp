#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;

	map<ll,ll> dp;
	dp[0]=1;
	for(ll i=0;i<n;i++)
	{

		dp[i+1]+=dp[i];
		dp[i+2]+=dp[i];
		dp[i+3]+=dp[i];
		
	}

	cout<<dp[n]<<endl;

	return 0;
}