#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

std::vector<long long> primes;

void init()
{
	bool curr_primes[32000];

	memset(curr_primes,0,32000);
	long long i;
	primes.push_back(2);
	for(i=3;i<32000;i+=2)
	{
		if(curr_primes[i-1]==0)
		{
			primes.push_back(i);
			long long curr=i*3;
			long long count=3;
			while(curr<32000)
			{
				curr_primes[curr-1]=1;
				curr=(curr/count)*(count+2);
				count+=2;
			}
		}
	}
}

void print_primes(long long m , long long n)
{
	long long sz = primes.size();
	bool p[n-m+1];
	memset(p,0,n-m+1);

	for (std::vector<long long >::iterator i = primes.begin()+1; i != primes.end(); ++i)
	{
		// printf("%lld\n",*i );
		if((*i) > sqrt(n))
			break;
		long long curr = (m/(*i))*(*i)    ;
		if(curr<m || ((curr&1)==0))
			curr=((curr/(*i)) + ((curr&1)?2:1)) * (*i)   ;
		bool dont=0;
		// if(curr>=m && curr<=n)
		// {
		// 	if(p[curr-m]==1)
		// 		dont=1;
		// }
		while(curr<=n && curr>=m)
		{
			p[curr-m]=1;
			// if(*i ==5)
			// printf("%lld \n",curr );
			curr = ((curr/(*i)) + 2)*(*i);
			// printf("%lld\n",curr );
		}
	}

	for(long long j=(((m&1)==1)?0:1);j<n-m+1;j+=2)
		if(p[j]==0)
			printf("%lld\n",m+j );

}

int main(int argc, char const *argv[])
{

	int t;
	scanf("%d",&t);
	init();
	for(;t>0;t--)
	{
		long long int m,n;
		scanf("%lld %lld",&m,&n);
		if(n<=32000)
		{
			for (std::vector< long long >::iterator i = primes.begin(); i != primes.end(); ++i)
			{
				if((*i)>n)
					break;
				else if((*i)>=m)
					printf("%lld\n",(*i) );
			}
		}
		else
		{
			print_primes(m,n);
		}
		printf("\n");
	}

	return 0;
}