#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll n,x,count=0;

	cin>>n>>x;

	std::vector<ll> pow2;
	pow2.push_back(1);

	ll c=0;


	std::map<ll, ll> m;
	std::map<ll, bool> exists;
	for(ll i=0;i<n;i++)
	{
		ll k;
		cin>>k;
		m[k]++;
		exists[k]=1;
		// c++;
		// cout<<" input "<<k<<endl;
	}

	for(int i=0;i<17;i++)
		pow2.push_back(2*pow2[i]);

	for(auto e:m)
	{
		ll val=e.first;
		
		ll num=val^x;

		// cout<<val<<endl;

		if(num!=val)
		{
			if(exists[num])
			{
				count+=m[num]*e.second;
				// cout<<num<<"  for :  "<<val<<" with freq  "<<m[num]<<endl;
			}
		}
		else
		{
			if(exists[num])
			{
				// cout<<num<<"  for :  "<<val<<" with freq  "<<(m[num]*(m[num]-1))<<endl;
				count+=(m[num]*(m[num]-1));
			}
		}
	}


	cout<<count/2<<endl;
	// cout<<c<<endl;
	return 0;
}

