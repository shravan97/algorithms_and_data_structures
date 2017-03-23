#include <bits/stdc++.h>
#define big_n 1000
using namespace std;

typedef long long int ll;

std::vector<ll> primes;

void init()
{
	bool curr_primes[big_n];

	memset(curr_primes,0,big_n);
	long long int i;
	primes.push_back(2);
	for(i=3;i<big_n;i+=2)
	{
		if(curr_primes[i-1]==0)
		{
			primes.push_back(i);
			long long int curr=i*3;
			long long int count=3;
			while(curr<big_n)
			{
				curr_primes[curr-1]=1;
				curr=(curr/count)*(count+2);
				count+=2;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ll t;
	init();
	cin>>t;
	while(t--)
	{
		ll n;
		std::vector<ll> v;
		std::map<ll, std::vector<ll> > pw;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			ll k;
			cin>>k;
			v.push_back(k);

		}

		for(auto e:v)
		{
			for(auto p:primes)
			{
				ll c=0;
				if(e%p==0)
				{
					while((e%p==0))
					{
						e/=p;
						c++;
					}
					// cout<<p<<' '<<c<<endl;
					pw[p].push_back(c);
				}
			}
			if(e!=1)
				pw[e].push_back(1);
		}

		ll num=0;

		for(auto p:pw)
		{
			ll o=0,e=0;
			for(auto el:p.second)
			{
				if(el&1)
					e++;
				else
					o++;
			}

			// cout<<p.first<<' '<<o<<' '<<e<<endl;

			num+=(min((ll)(o+n-(p.second.size())),e));

		}

		cout<<num<<endl;
	}
	return 0;
}
