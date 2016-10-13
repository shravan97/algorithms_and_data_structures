#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll sum(ll x)
{
	if(x<10)return x*(x+1)/2;

	int p = log(x)/log(10);
	cout<<" p : "<<p<<endl;
	ll first_dig = x/(ll)pow(10,p);
	ll mod = (first_dig*(ll)pow((ll)10,(ll)p));
	
	ll k = sum(x%mod);
	return first_dig*pow(45,p) + (first_dig*(first_dig+1)/2)*pow(10,p) +(x%mod)*first_dig + k;
}

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	while(1)
	{
		ll a,b;
		cin>>a>>b;
		cout<<sum(a)<<' '<<sum(b)<<endl;

	}
	return 0;
}