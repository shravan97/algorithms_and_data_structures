#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	std::vector<ll> v;
	for(int i=0;i<n;i++)
	{
		ll z;
		cin>>z;
		v.push_back(z);
	}

	std::vector<ll>::iterator it1,it2,it3;
	std::unordered_map<ll, ll> lh,rh;

	for(it1=v.begin();it1!=v.end();it1++)
	{
		ll a=*it1,d=*it1;
		for(it2=v.begin();it2!=v.end();it2++)
		{
			ll b=*it2,f=*it2;
			for(it3=v.begin();it3!=v.end();it3++)
			{
				ll c=*it3,e=*it3;
				lh[(ll)(a*b+c)]++;
				if(d!=0)
				rh[(ll)(d*(e+f))]++;
			}
		}
	}

	std::unordered_map<ll, ll>::iterator it;
	long long int res=0; 
	for(it=lh.begin();it!=lh.end();it++)
	{
		res+=(ll)(it->second * rh[it->first]);
	}
	cout<<res<<endl;

	return 0;
}