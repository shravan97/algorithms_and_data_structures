#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	std::vector<ll> v,sums(n,0);

	for(ll i=0;i<n;i++)
	{
		ll k;
		cin>>k;
		v.push_back(k);

	}
	sort(v.begin(),v.end());

	ll s=0,num=0, l1=0,l2=0;

	for(ll i=0;i<n;i++)
	{
		cout<<v[i]<<' ';
		if(s<=v[i])
		{
			num++;
			l1=i;
		}
		else
		{
			l2=i;
		}
		s+=v[i];
		sums[i]=s;
	}

	if(l1<l2 && l2==n-1)
	{
		if(sums[l1]<v[n-1])
			num++;
	}

	cout<<num<<endl;
	return 0;
}