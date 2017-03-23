#include <bits/stdc++.h>
# define mod 1e9+7
using namespace std;
typedef long long int ll;
std::vector<int> primes;
void sieve()
{
	ll val=2;
	while(val<100)
	{
		if(chck[val])
		{
			val+=2;
			continue;
		}
		ll v=val,c=3;
		if(val==2)c=2;
		primes.push_back(val);
		ld[val]=val;
		// cout<<val<<" here  \n";
		while(v*c<100)
		{
			// cout<<" for  "<<v*c<<'\n';
			chck[v*c]=1;
			if(ld[v*c]==0)
				ld[v*c]=val;
			if(val==2)c++;
			else
			c+=2;
		}
		if(val==2)val++;
		else
		val+=2;
	}
}

long long int func(int n,int k,int v)
{
	sieve();
	long long int pdt=1,tot=0;
	std::map<int, int> m;
	for(int i=0;i<k;i++)
	{
		long long int min=INT_MAX;
		int cur=1;
		for(int p=0;p<primes.size();p++)
		{
			if(pdt*primes[p] < min)
			{
				min=pdt*primes[p];
				cur=primes[p];
			}
		}

		pdt=min;


		if(pdt%k==v)
		{
			if()
			tot+=ncr();
		}

	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}
