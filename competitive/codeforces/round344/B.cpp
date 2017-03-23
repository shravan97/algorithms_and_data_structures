#include <iostream>
#include <map>
#include <utility>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n,m,k;
	cin>>n>>m>>k;
	std::map<ll , pair<ll,ll> > c,r;
	for(ll i=0;i<k;i++)
	{
		ll t,rc,col;
		cin>>t>>rc>>col;
		if(t==1)
			r[rc-1]=make_pair(col,i);
		else
			c[rc-1]=make_pair(col,i);
	}
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
			if(r[i].first==0 && r[i].second==0)
			{
				cout<<c[j].first<<" ";
			}
			else if(c[j].first==0 && c[j].second==0)
			{
				cout<<r[i].first<<' ';
			}
			else
			{
				if(r[i].second > c[j].second)
					cout<<r[i].first<<" ";
				else
					cout<<c[j].first<<" ";
			}
		cout<<endl;
	}

	return 0;
}