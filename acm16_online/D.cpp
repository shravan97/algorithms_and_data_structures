#include <bits/stdc++.h>
#define mod 1e9+7
using namespace std;
typedef long long int ll;
std::vector<int> primes;
void sieve()
{
	ll n=sqrt(750000)+1;
	bool curr_primes[n];

	memset(curr_primes,0,n);
	long long int i;
	primes.push_back(2);
	for(i=3;i<n;i+=2)
	{
		if(curr_primes[i-1]==0)
		{
			primes.push_back(i);
			long long int curr=i*3;
			long long int count=3;
			while(curr<n)
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
	int t;
	cin>>t;

	sieve();

	while(t--)
	{
		ll mx=0;
	
		std::map<ll, bool> nums;
		ll n;
		cin>>n;

		for(ll i=0;i<n;i++)
		{
			ll k;
			cin>>k;
			nums[k]=1;
			if(mx<k)
				mx=k;
		}

		std::map<ll, ll> divs,gs,gs1;
		
		if(nums[1])
		{
			divs[1]=1;
			gs[1]=1;
			gs1[1]=1;
		}

		for(ll i=2;i<=mx;i++)
		{
			// cout<<i<<endl;
			int l_prime=1;
			ll num=i;
			for(ll j=0;j<primes.size() && primes[j]<=num ;j++)
			{
				if(num%primes[j]==0)
				{
					if(l_prime<primes[j])
						l_prime=primes[j];
					// while(num%primes[j]==0)
						// num/=primes[j];
					break;
				}
			}

			if(nums[i])
			{
				if((i/l_prime)%l_prime==0)
				{
					divs[i]=divs[i/l_prime]+1;
					gs1[i]=2*gs1[i/l_prime]+1;
				}
				else
				{
					divs[i]=divs[l_prime]+divs[i/l_prime]+1;
					gs1[i]=2*(gs1[i/l_prime]+1)+1;
				}

				gs[i] = gs[i-1]+ gs1[i];
			}
			else
			{

				divs[i]=divs[i/l_prime];
				gs[i]=gs[i-1];
				gs1[i]=gs1[i/l_prime];
			}
		}

		cout<<gs[mx]<<endl;
	}
	return 0;
}