#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n,m,sz,n_uniq=0;
	cin>>n>>m;
	ll tot[m];
	sz=n;
	std::map< std::vector<ll> , bool> pts;
	for(int x=0;x<m;x++)tot[x]=0;
	while(sz--)
	{
		int i;
		std::vector<ll> v;

		for(i=0;i<m;i++)
		{
			ll k;
			cin>>k;
			v.push_back(k);
			// cout<<" tot for "<<i<<' '<<tot[i]<<endl;
		}
		if(pts[v]==0)
		{
			for(i=0;i<m;i++)
				tot[i]+=v[i];
			n_uniq++;
		}
	}
	for(int z=0;z<m;z++)
		cout<<(tot[z])/n_uniq<<' ';
	cout<<endl;
	return 0;
}