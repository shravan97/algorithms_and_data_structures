#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,c1o=0,c1e=0,c2o=0,c2e=0;
		cin>>n;


		for(ll i=0;i<n;i++)
		{
			ll k;
			cin>>k;
			if(i&1)
				c1o+=k;
			else
				c1e+=k;
		}
		for(ll i=0;i<n;i++)
		{
			ll k;
			cin>>k;
			if(i&1)
				c2o+=k;
			else
				c2e+=k;
		}

		cout<<min(c1e+c2o,c1o+c2e)<<endl;
		
	}
	return 0;
}