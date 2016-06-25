#include <cstdio>
#include <cmath>
int main(int argc, char const *argv[])
{
	while(1)
	{
		long long int n,i,s=0;
		scanf("%lld",&n);
		if(n==-1)break;
		long long int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			s+=a[i];
		}
		if(s%n!=0)
			printf("-1\n");
		else
		{
			long long int i,reqd=0,avg=s/n,add=0,rm=0;
			for(i=0;i<n;i++)
			{
				reqd+=(avg-a[i]);
				if(avg>a[i])
					add+=avg-a[i];
				else
					rm+=a[i]-avg;
			}
			printf("%lld\n",add );
		}
	}
	return 0;
}