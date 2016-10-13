#include <cstdio>
typedef long long int ll;
int main(int argc, char const *argv[])
{
	ll n,k,i;
	scanf("%lld %lld",&n,&k);
	ll c[n],caps[k],count=0,sum=0,tot=0,capsum=0;

	for(i=0;i<n;i++)
	{
		scanf("%lld",&c[i]);
		sum+=c[i];
	}
	for(i=0;i<k;i++)
		scanf("%lld",&caps[i]);
	// printf("sum  %lld \n",sum );
	for(i=0;i<n;i++)
	{
		if(count<k && i+1==caps[count])
		{
			sum-=c[i];
			if(i!=0)
			{
				if(caps[count-1]==i)
					tot+=sum*c[i];
				else
					tot+=(sum-c[i-1])*c[i];
				// printf("%lld * %lld\n",(sum-c[i-1]),c[i] );
			}
			else
			{
				tot+=(sum)*c[i];
				// printf("%lld * %lld\n",(sum),c[i]);
			}
			// if(i==n-1 && caps[0]!=1)
				// tot+=c[i]*c[0];
			count++;
		}
		else if(i!=n-1)
		{

			tot+=c[i]*c[i+1];
			// printf("%lld * %lld\n",c[i],c[i+1] );

		}
		else if(i==n-1)
		{
			if(caps[0]!=1)
				tot+=c[n-1]*c[0];
			// printf("%lld * %lld\n",c[n-1],c[0] );

		}
	}

		printf("%lld\n",tot );

	return 0;
}