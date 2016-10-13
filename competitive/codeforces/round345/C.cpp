#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n;
	cin>>n;
	std::map<ll, ll> x,y;
	std::map< pair<ll,ll> , ll> cor;
	ll c=0,nr=0;
	while(n--)
	{
		ll x1,y1;
		cin>>x1>>y1;
		// cout<<" h "<<x1<<' '<<y1<<endl;
		c+=x[x1]+y[y1]-cor[make_pair(x1,y1)];
		x[x1]++;
		y[y1]++;
		// cout<<c<<endl;
		cor[make_pair(x1,y1)]++;
		// cor[make_pair(x1,y1)]=1;
	}
	cout<<c<<'\n';
	return 0;
}