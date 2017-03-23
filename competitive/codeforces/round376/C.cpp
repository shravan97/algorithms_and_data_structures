#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef long long int ll;

ll find(std::vector<ll> v,ll pos,std::vector<pair<ll,ll> > &cl)
{
	if(pos==cl.size())
		return 0;
	if(v[cl[pos].first-1]==v[cl[pos].second-1])
	{
		// pos++;
		return find(v,pos+1,cl);
	}
	else
	{
		std::vector<ll> v1=v,v2=v;
		v1[cl[pos].first-1]=v[cl[pos].second-1];
		v2[cl[pos].second-1]=v[cl[pos].first-1];
		return min(1+find(v1,pos+1,cl),1+find(v2,pos+1,cl));
	}
}

int main(int argc, char const *argv[])
{
	ll n,m,k;
	cin>>n>>m>>k;
	// std::map<ll, std::map<ll, ll> > c;
	// std::map<ll, std::map<ll, bool> > cb;
	std::vector<pair<ll,ll> > cl;
	std::vector<ll> c;

	for(ll i=0;i<n;i++)
	{
		ll z;
		cin>>z;
		c.push_back(z);
		
	}
	for(ll i=0;i<m;i++)
	{
		ll l,r;
		cin>>l>>r;
		cl.push_back(make_pair(l,r));
	}
	cout<<find(c,0,cl)<<endl;
	return 0;
}