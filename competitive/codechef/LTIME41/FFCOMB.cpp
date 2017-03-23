#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct compare
{
	bool operator ()(const pair< std::vector<ll>, ll> &p1,const pair< std::vector<ll>, ll> &p2)
	{
		return (p1.second<p2.second);
	}
};

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll c[n];
		for(int i=0;i<n;i++)
			cin>>c[i];

		vector< pair< std::vector<ll>, ll> > cs;

		for(ll i=0;i<m;i++)
		{
			ll k,sz;
			cin>>k>>sz;
			std::vector<ll> mv;
			ll sum=0;

			for(int z=0;z<sz;z++)
			{
				ll z1;
				cin>>z1;
				mv.push_back(z1);
				sum+=c[z1-1];
			}

			if(sum>k)
				sum=k;
			cs.push_back(make_pair(mv,sum));
		}

		sort(cs.begin(), cs.end(),compare());

		std::map<ll, bool> done;
		ll s=0;

		for(auto c:cs)
		{
			// cout<<" here "<<c.second<<endl;

			for(auto v:c.first)
			{
				done[v]=1;
			}
			s+=c.second;
			// cout<<" s "<<s<<endl;

			if(done.size()==n)
				break;
		}

		for(ll k=0;k<n;k++)
			if(!done[k+1])
				s+=c[k];

		cout<<s<<endl;

	}
	return 0;
}