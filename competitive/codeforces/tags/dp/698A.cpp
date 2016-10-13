#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
std::map<ll, std::map<ll, ll> > vals;
std::map<ll, std::map<ll, bool> > visited;

int dp(int d , std::vector<int> &v, int prev , int prev_ac)
{
	// cout<<v[d]<<" "<<prev<<endl;
	if(d==v.size())
		return 0;
	if(v[d]==0)
	{
		return 1+dp(d+1,v,0,-1);
	}
	else
	{
		// if(d==1)
		// {
		// 	if(prev==1)
		// 	{
		// 		if(prev_ac==1)
		// 			return 1+dp(d+1,v,1,-1);
		// 		else
		// 			return dp(d+1,v,1,1);
		// 	}
		// 	else if(prev==2)
		// }
		if(prev_ac==1)
		{
			if(v[d]==0||v[d]==1)
			{

				return 1+dp(d+1,v,v[d],-1);
			}
			else
				return dp(d+1,v,v[d],0);
		}
		else if(prev_ac==0)
		{
			if(v[d]==2||v[d]==0)
				return 1+dp(d+1,v,v[d],-1);
			else
				return dp(d+1,v,v[d],1);
		}
		else
		{
			if(v[d]==1)
				return dp(d+1,v,v[d],1);
			if(v[d]==2)
				return dp(d+1,v,v[d],0);
			if(v[d]==3)
				return min(dp(d+1,v,v[d],1),dp(d+1,v,v[d],0));
			if(v[d]==0)
				return 1+dp(d+1,v,v[d],-1);
		}

	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	std::vector<int> v;
	v.push_back(0);
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	cout<<dp(1,v,0,-1)<<endl;

	return 0;
}