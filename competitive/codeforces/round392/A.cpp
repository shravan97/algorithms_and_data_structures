#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	std::vector<ll> v;
	while(n--)
	{
		ll k;
		cin>>k;
		v.push_back(k);
	}

	ll m=-1,d=0;

	for(auto e:v)
	{
		if(e>m)
			m=e;
	}
	for(auto e:v)
		d+=(m-e);

	cout<<d<<endl;

	return 0;
}
