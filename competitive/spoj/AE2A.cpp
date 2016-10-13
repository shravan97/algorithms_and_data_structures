#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp(ll s,ll t , std::map<ll, std::map<ll, ll> > &d)
{
	if(t==0)return 0;
	if(s<=0)return 0;
	else if(s<t || s>6*t)
		return 0;
	else if(t==1)return 1;
	else if(t==s)return 1;
	ll res=0;
	
	// cout<<" r for "<<t<<' '<<s<<endl;
	for(ll i=1;i<7;i++)
	{
		if(d[s-i][t-1]!=0)
			res+=d[s-i][t-1];
		else
		{
			ll k=dp(s-i,t-1,d);
			res+=k;
			d[s-i][t-1]=k;
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		std::map<ll, std::map<ll, ll> > m;
		cout<<(int)(dp(k,n,m)*100/pow(6,n))<<endl;

	}
	return 0;
}