	#include <bits/stdc++.h>
	using namespace std;
	#define max 1e18
	#define mod 10000000007
	typedef long long int ll;

	ll powmod(ll x,ll y,ll m)
	{
		if(x==0)return 0;
		if(y==1)
			return x%m;
		else if(y==0) return 1;

		ll k = powmod(x,y/2,m);
		if(y&1) return ((k%m)*(k%m)*(x%m))%m;
		else return ((k%m)*(k%m))%m;
	}

	int main(int argc, char const *argv[])
	{
		int t,count=0;
		cin>>t;
		ofstream ofile;
		ofile.open("out.txt",ios::out);
		while(t--)
		{
			ll i,j,a,b,n,k,num=0;
			cin>>a>>b>>n>>k;
			if(a==0 && b==0)
			{
				if(2%k==0)
					ofile<<"Case #"<<count+1<<": "<<powmod((n%mod * (n-1)%mod),1,mod)<<endl;
				else ofile<<"Case #"<<count+1<<": "<<0<<endl;
				count++;
				continue;
			}
			std::map< pair<ll,ll> , ll> sh;
			std::map<ll, ll>  wat;
			ll eq=0;
			// std::vector<ll> sh1,wat1;
			for(i=1;i<=n;i++)
			{
				sh[make_pair(powmod(i,a,k),i)]=i;
				// sh1.push_back(i);
				cout<<i<<' '<<powmod(i,a,k)<<' '<<powmod(i,b,k)<<'\n';
				wat[powmod(i,b,k)]++;
				if((powmod(i,b,k) + powmod(i,a,k))%k==0)
					eq++;
			}

			std::map< pair<ll,ll> , ll>::iterator it;
			for(it=sh.begin();it!=sh.end();it++)
			{
				// ll c=1;
				// cout<<" h "<<it->first.first<<'\n';
					
						// if(wat[k-it->first.first]!=0)
						// {
							// cout<<" in here "<<k-it->first.first<<' '<<it->first.first<<'\n';
						// 	// num=(num%mod + wat[val-it->first.first]%mod)%mod;
							if(it->first.first==0)
								num=(num%mod + wat[0]%mod)%mod;
							num=(num%mod + wat[k-it->first.first]%mod)%mod;


							// num+=wat[val-it->first.first];
							// num=num%mod;
						// }
						// else if(it->first.first==0)
						// 	num=(num%mod + wat[it->first.first]%mod)%mod;

					// }
			}

			// cout<<num<<' '<<eq<<endl;

			if(num==0)
				ofile<<"Case #"<<count+1<<": "<<0<<'\n';
			else
				ofile<<"Case #"<<count+1<<": "<<num-eq<<'\n';
			count++;
		}
		return 0;
	}