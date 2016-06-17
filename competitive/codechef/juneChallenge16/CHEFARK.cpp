#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int l;
l comb(l n , l r)
{
	l de=1,comb=1;
	if(n-r<r)
		r=n-r;
	while(de<=r)
	{
		comb*=((n--)/(de++))%1000000007;
	}
	return comb%1000000007;
}

int main()
{
	int t;
	scanf("%d",&t);

	for(;t>0;t--)
	{
		l n ,k,i;
		scanf("%lld %lld",&n,&k);
		l no_zeroes=0;

		for(i=0;i<n;i++)
		{
			l temp;
			scanf("%lld",&temp);
			if(temp==0)
				no_zeroes++;
		}

		n-=no_zeroes;
		if(n==0)
			printf("1\n");
		else if(n==1)
		{
			if(no_zeroes>0)
				if(k>1)
					printf("2\n");
				else printf("1\n");
			else printf("1\n");	
		}
		else if(no_zeroes>0 && k>=n)
		{
			printf("%lld\n",(long long int)pow(2,n));
		}
		else
		{
			l sum;

			if(k%2)
			{
				sum=0;
				l limit=k;
				if(k>n)
					if(n%2)
						limit=n;
					else limit=n-1;

				for(i=1;i<=limit;i+=2)
					sum+=((comb(n,i)));
			}
			else
			{
				l limit=k;
				if(k>n)
					if(n%2)
						limit=n-1;
					else limit=n;

				sum=1;
				for(i=2;i<=limit;i+=2)
					sum+=(comb(n,i));
			}
			printf("%lld\n",sum );
		}
	}
	return 0;
}