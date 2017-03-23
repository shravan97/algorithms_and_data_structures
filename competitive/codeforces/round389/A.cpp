#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll n,m,k,r,c;
	cin>>n>>m>>k;
	if(k&1)
	{
		r=ceil((((float)k-1.0)/2.0 + 1.0)/(float)m);
		c=((k-1)/2 + 1)%m;
		if(c==0)
			c=m;
	}
	else
	{
		r=ceil((((float)k)/2.0 )/(float)m);
		c=((k)/2)%m;
		if(c==0)
			c=m;

	}

	cout<<r<<' '<<c<<' '<<((k&1)?'L':'R')<<endl;

	return 0;
}
