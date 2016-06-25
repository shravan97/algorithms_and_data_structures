#include <cstdio>
typedef long long ll;
int main(int argc, char const *argv[])
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll x,y;
		scanf("%lld %lld",&x,&y);
		if(x==y)
		{
			if(!(x&1))
				printf("%lld\n",x*2);
			else printf("%lld\n",(x-1)*2 + 1 );
		}
		else if(y==(x-2))
		{
			if(!(x&1))
				printf("%lld\n",(x-1)*2);
			else printf("%lld\n",2*(x-2) + 1 );
		}
		else printf("No Number\n");
	}
	return 0;
}