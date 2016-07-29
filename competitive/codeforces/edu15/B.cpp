#include <cstdio>
#include <map>
#include <cmath>
using namespace std;
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n,i,count=0,pow2[31],no_pow2=0;
	scanf("%lld",&n);
	std::map<ll, ll> val;
	for(i=0;i<=30;i++)
		pow2[i]=pow(2,i);
	for(i=0;i<n;i++)
	{
		ll num;
		scanf("%lld",&num);
		val[num]++;
		if((num&num-1)==0) no_pow2++;
	}
	std::map<ll, ll>::iterator it;
	//printf("%lld\n",val[0] );
	for(it=val.begin();it!=val.end();it++)
	{
		// printf("%lld\n",it->first );
		for(i=0;i<=30;i++)
			if(pow2[i]-it->first>=0)
			{
				// printf("%lld %lld %lld\n",pow2[i],count,it->first );
				if(pow2[i]-it->first == it->first)
					count+=val[pow2[i]-it->first]*(val[pow2[i]-it->first] - 1);
				else if(val.find(pow2[i]-it->first)!=val.end())
					count+=it->second * val[pow2[i]-it->first];
			}
			// else break;
	}

	
	printf("%lld\n",count/2 );
	return 0;
}