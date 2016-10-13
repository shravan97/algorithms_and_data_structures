#include <bits/stdc++.h>
#define max(a,b)((a>b)?a:b)
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	ll sz=s.size();

	ll dp[sz+1][sz+1],i,j;

	for(i=0;i<sz+1;i++)
		for (j = 0; j < sz+1; ++j)
		{
			dp[i][j]=0;
		}

	for(i=1;i<sz+1;i++)
	{
		for(j=1;j<sz+1;j++)
		{
			if(i!=j&&s[i-1]==s[j-1])
			{
				dp[i][j]=max(1+dp[i-1][j-1],max(dp[i][j-1],dp[i-1][j]));
			}
			else 
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}

	cout<<dp[sz][sz]<<endl;
	return 0;
}