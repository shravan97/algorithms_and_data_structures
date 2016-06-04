#include <stdio.h>
typedef long long int ll;
int main()
{
	ll t;
	scanf("%lld",&t);
	for(;t>0;t--)
	{
		ll n , i;
		scanf("%lld",&n);
		ll c[n] , cp[n];
		int flag=0;

		for(i=0;i<n;i++)
			scanf("%lld",&c[i]);

		for(i=0;i<=n-2;i++)
		{
			if(i==n-2)
			{
				if(cp[n-1]!=c[n-1] || cp[n-2]!=c[n-2] || cp[n-3]!=c[n-3])
					flag=0;
				else flag=1;

				break;
			}

			else if(cp[i]!=c[i])
			{
				cp[i]=c[i];
				cp[i+1]=c[i];
				cp[i+2]=c[i];
			}	
		}

		if(flag)
			printf("Yes\n");
		else
			{
				for(i=n-1;i>=1;i--)
				{
					if(i==1)
					{
						if(cp[0]!=c[0] || cp[2]!=c[2] || cp[1]!=c[1])
							flag=0;
						else flag=1;
						break;
					}
					else if(cp[i]!=c[i])
					{
						cp[i]=c[i];
						cp[i-1]=c[i];
						cp[i-2]=c[i];
					}
				}

				if(flag)
					printf("Yes\n");
				else printf("No\n");
			}
	}

	return 0;
}