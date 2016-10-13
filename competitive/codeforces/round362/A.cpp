#include <cstdio>
int main(int argc, char const *argv[])
{
	long long int t,s,x;
	scanf("%lld %lld %lld",&t,&s,&x);
	if(x>t && x<t+s)
		printf("NO\n");
	else if(x<t)printf("NO\n");
	else if((((x-t)%s)==0) || (((x-t-1)%s)==0) )
		printf("YES\n");
	else printf("NO\n");
	return 0;
}