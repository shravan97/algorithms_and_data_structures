#include <cstdio>
#include <vector>
#include <cstring>
#define big_n 32000
std::vector<long long int> primes;

void init()
{
	bool curr_primes[big_n];

	memset(curr_primes,0,big_n);
	long long int i;
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,no_div=0;
		scanf("%d",&n);
		long long a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(!((a[i])&1))
				no_div++;
			if((a[i]%4)==0)
				no_div=2;
		}
		if(no_div!=0 && no_div!=1)
			printf("2\n");
		else
		{
			init();
			for (std::vector<long long int>::iterator it = primes.begin()+1; it != primes.end(); ++it)
			{
				no_div=0;
				for(i=0;i<n;i++)
				{
					if((a[i]%(*it))==0)
						no_div++;
					if((a[i]%((*it)*(*it)))==0)
					{
						no_div=2;
						break;
					}
					if(no_div>=2)
						break;
				}
				if(no_div>=2)
			{
				printf("%lld\n",*it );
				break;
			}
			
			}
		}
	}
	return 0;
}