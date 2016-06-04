#include <stdio.h>
#include <math.h>
typedef long long int ll;
ll min(a,b)
{
	return ((a<b)?a:b);
}
int main()
{
	ll t;
	scanf("%lld",&t);
	for(;t>0;t--)
	{
		ll a , b, c ,d;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		if(a<b)
		{
			ll diff =b-a;
			if(diff/c==0)
				printf("%lld\n", (a+(c*(diff/c + 1)) - b)%d);
			else
				printf("%lld\n",min((a+(c*(diff/c))-b)%d, (a+(c*(diff/c + 1)) - b)%d));
		}
		else if(a==b)
			printf("0");
		else
		{
			ll diff =a-b;
			if(diff/d==0)
				printf("%lld\n", (b+(d*(diff/d + 1)) - a)%c);
			else
				printf("%lld\n",min((b+(d*(diff/d))-a)%c, (b+(d*(diff/d + 1)) - a)%c));
		}
	}
	return 0;
}