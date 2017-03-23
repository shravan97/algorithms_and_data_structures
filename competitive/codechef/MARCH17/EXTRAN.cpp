#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;

		std::map<ll, ll> m;
		while(n--)
		{
			ll k;
			cin>>k;
			m[k]++;
		}

		std::map<ll, ll>::iterator it;

		std::vector<ll> v;

		for(auto e:m)
		{
			v.push_back(e.first);
		}

		for(ll i=0;i<v.size();i++)
		{
			if(i==0)
			{
				if(v[i]+1 != v[i+1])
				{
					cout<<v[i]<<endl;
					break;
				}
				else if(m[v[i]]>1)
				{
					cout<<v[i]<<endl;
					break;
				}
				
			}
			else if(i==v.size()-1)
			{
				if(v[i-1]+1 != v[i])
				{
					cout<<v[i]<<endl;
					break;
				}
				else if(m[v[i]]>1)
				{
					cout<<v[i]<<endl;
					break;
				}

			}
			else
			{
				if(m[v[i]]>1)
				{
					cout<<v[i]<<endl;
					break;
				}
			}
		}
	}
	return 0;
}