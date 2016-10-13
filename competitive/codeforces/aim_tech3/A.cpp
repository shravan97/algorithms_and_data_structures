#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n,b,d,c=0,i;
	cin>>n>>b>>d;
	ll s=0;

	for ( i = 0; i < n; ++i)
	{
		ll k;
		cin>>k;
		if(k<=b)
			s+=k;
		if(s>d)
		{
			s=0;
			c++;
		}

	}
	cout<<c<<'\n';
	return 0;
}