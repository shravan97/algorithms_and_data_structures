#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

std::vector<long long int> primes;

void init()
{
	bool curr_primes[32000];

	memset(curr_primes,0,32000);
	long long int i;
	primes.push_back(2);
	for(i=3;i<32000;i+=2)
	{
		if(curr_primes[i-1]==0)
		{
			primes.push_back(i);
			long long int curr=i*3;
			long long int count=3;
			while(curr<32000)
			{
				curr_primes[curr-1]=1;
				curr=(curr/count)*(count+2);
				count+=2;
			}
		}
	}
}

void print_primes(long long int m , long long int n)
{
	if(m==1)m++;
	for(;m<=n;m+=1)
	{
		long long int i;
		bool flag=0;
		for(i=0;primes[i]<=(sqrt(m));i++)
		{
			// printf("%lld %lld\n",i,m );
			// printf("%lld %lld\n",m,primes[i] );
			if((m%(primes[i]))==0)
			{
				// printf("HERE\n");
				flag=1;
				break;
			}
		}

		if(!flag)
			cout<<m<<'\n';
	}
}

int main(int argc, char const *argv[])
{

	int t;
	cin>>t;
	init();
	for(;t>0;t--)
	{
		long long int m,n;
		cin>>m>>n;
		if(n<=32000)
		{
			for (std::vector< long long int >::iterator i = primes.begin(); i != primes.end(); ++i)
			{
				if((*i)>n)
					break;
				else if((*i)>=m)
					cout<<(*i)<<'\n';
			}
		}
		else
		{
			print_primes(m,n);
		}
		cout<<'\n';
	}

	return 0;
}