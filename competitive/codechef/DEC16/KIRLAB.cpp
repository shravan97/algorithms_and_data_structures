#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a,ll b)
{
	return (b==0)?a:gcd(b,a%b);
}

ll max_len=1;
std::map<ll, ll> dp;
ll iter=0;

void recurse(std::vector<ll> &v,ll pos,ll start, ll len)
{
	/*

	13 2 8 6 3 1 9
		
	*/
	cout<<iter<<endl;
	iter++;

	for(ll i=pos+1;i<v.size();i++)
	{
		// cout<<" here "<<i<<endl;
		iter++;
		if(v[pos]!=1 && gcd(v[pos],v[i])>1)
		{
			if(!dp[i])
				recurse(v,i,start,len+1);
			else
				max_len=max(max_len,dp[i]+len);
		}
		else if(v[i]!=1)
		{
			if(!dp[i])
				recurse(v,i,i,1);
			else
				max_len=max(max_len,dp[i]);
		}
	}
	max_len=max(max_len,len);
	dp[start]=len;

}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t--)
	{
		ll n;
		cin>>n;
		std::vector<ll> v,dp(n,1);
		for(ll i=0;i<n;i++)
		{
			ll k;
			cin>>k;
			v.push_back(k);
		}
		ll maxdp=1;
		for(ll i=0;i<n;i++)
		{
			for(ll j=i-1;j>=0;j--)
			{
				iter++;
				if(v[i]!=1 && v[j]!=1 && gcd(v[i],v[j])>1)
				{
					dp[i]=max(dp[i],1+dp[j]);
					maxdp=max(dp[i],maxdp);
				}
			}
		}

		cout<<maxdp<<endl;
		cout<<iter<<endl;
		
	}
	return 0;
}
